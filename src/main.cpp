#include <Arduino.h>
#include <Arduino_JSON.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <esp_timer.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include "time.h"
#include <PubSubClient.h>
#include <esp_now.h>
#include <ThingSpeak.h>

#include "scr1.h"
#include "scr2.h"
#include "scr_weather.h"
#include "ui_share.h"
#include "scr_temp.h"
#include "scr_light.h"

#define MQTT_SERVER "broker.mqttdashboard.com"
#define MQTT_PORT 1883
#define MQTT_LED1_TOPIC "MQTT_ESP32/LED1"
#define LED 2

typedef struct struct_message {
    char a[32];
    int b;
    float c;
    bool d;
} struct_message;  

struct_message myData;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("Char: ");
  Serial.println(myData.a);
  Serial.print("Int: ");
  Serial.println(myData.b);
  Serial.print("Float: ");
  Serial.println(myData.c);
  Serial.print("Bool: ");
  Serial.println(myData.d);
  Serial.println();
}

unsigned long previousMillis = 0; 
const long interval = 5000;
 
WiFiClient wifiClient;
PubSubClient client(wifiClient);
String ledStatus1 = "OFF";


#define TEST 0

#define WIFI_TIMEOUT_MS 20000
#define LV_USE_UI 1
#define LV_SETUP 1

const int   phys_btn = 0;
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

String openWeatherMapApiKey = "c84fc3a54f52cfece19811689eb58f1f";
String city = "HaNoi";
String countryCode = "VN";
String jsonBuffer;

void TaskSetup(void);

static TaskHandle_t KeepWifiTask = NULL;
static TaskHandle_t LocalTimeTask = NULL;
static TaskHandle_t UIHandleTask = NULL;
static TaskHandle_t WeatherUpdateTask = NULL;
static TaskHandle_t MQTTTask = NULL;

void Memory_track(void)
{
    Serial.print("UI: ");
    Serial.println(uxTaskGetStackHighWaterMark(UIHandleTask));
    Serial.print("Wifi: ");
    Serial.println(uxTaskGetStackHighWaterMark(KeepWifiTask));
    Serial.print("Time: ");
    Serial.println(uxTaskGetStackHighWaterMark(LocalTimeTask));
    Serial.print("Weather: ");
    Serial.println(uxTaskGetStackHighWaterMark(WeatherUpdateTask));
    Serial.print("MQTT: ");
    Serial.println(uxTaskGetStackHighWaterMark(MQTTTask));
}

void connect_to_broker() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe(MQTT_LED1_TOPIC);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
  char status[20];
  Serial.println("-------new message from broker-----");
  Serial.print("topic: ");
  Serial.println(topic);
  Serial.print("message: ");
  Serial.write(payload, length);
  Serial.println();
  for(int i = 0; i<length; i++)
  {
    status[i] = payload[i];
  }
  Serial.println(status);
  Memory_track();
  if(String(topic) == MQTT_LED1_TOPIC)
  {
    if(String(status) == "OFF")
    {
      ledStatus1 = "OFF";
      digitalWrite(LED, LOW);
      Serial.println("LED1 OFF");
    }
    else if(String(status) == "ON")
    {
      ledStatus1 = "ON";
      digitalWrite(LED, HIGH);
      Serial.println("LED1 ON");
    }
  }
}

void MQTTTest(void * parameters) {
    for(;;){
        client.loop();
        if (!client.connected()) {
            connect_to_broker();
    }
    }
}


void keepWifiAlive(void * parameters)
{
    for(;;) {
        if(WiFi.status() == WL_CONNECTED) {
            Serial.println("Wifi is still connected");
            vTaskDelay(20000 / portTICK_PERIOD_MS);
            WiFi.disconnect();
            Serial.print("FreeHeap: ");
            vTaskDelay(10000 / portTICK_PERIOD_MS);
            Serial.println(ESP.getFreeHeap());
            continue;
        }
        Serial.println("Wifi Connecting");
        WiFi.mode(WIFI_MODE_APSTA);
        WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);

        unsigned long startAttemptTime = millis();

        while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {}
        if(WiFi.status() != WL_CONNECTED) {
            Serial.println("Connected failed");
            vTaskDelay(20000 / portTICK_PERIOD_MS);
            continue;
        }
    
        Serial.println("[WiFi] Connected: " + WiFi.localIP());
    }
}

String httpGETRequest(const char* serverName) {
    WiFiClient client;
    HTTPClient http;
        
    // Your Domain name with URL path or IP address with path
    http.begin(client, serverName);
    
    // Send HTTP POST request
    int httpResponseCode = http.GET();
    
    String payload = "{}"; 
    
    if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();

    return payload;
}

char weather_code[8][4] = {"01d", "02d", "03d", "04d", "09d", "10d", "11d", "50d"};
char weather_code_night[8][4] = {"01n", "02n", "03n", "04n", "09n", "10n", "11n", "50n"};

void WeatherUpdate(void * parameters) {
    for(;;) {
        if(WiFi.status()== WL_CONNECTED){
            String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + openWeatherMapApiKey;
        
            jsonBuffer = httpGETRequest(serverPath.c_str());
            Serial.println(jsonBuffer);
            JSONVar myObject = JSON.parse(jsonBuffer);

            // JSON.typeof(jsonVar) can be used to get the type of the var
            if (JSON.typeof(myObject) == "undefined") {
                Serial.println("Parsing input failed!");
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                continue;
            }
            
            clientData Data;
            Data.temp = myObject["main"]["temp"];
            Data.humidity = myObject["main"]["humidity"];
            strcpy(Data.code, myObject["weather"][0]["icon"]);
            strcpy(Data.label, myObject["weather"][0]["main"]);

            for(int i = 0; i < 8; i++) {
                if(!strcmp(Data.code, weather_code[i]) || !strcmp(Data.code, weather_code_night[i])) {
                    weather_icon_changer(weather_icon, i);
                    weather_icon_changer(weather_icon_scr1, i);
                };
            };

            //Data write

            lv_label_set_text_fmt(humidity, "%d", Data.humidity);
            lv_label_set_text_fmt(temperature, "%d Kelvin", Data.temp);
            lv_label_set_text_fmt(weather_label_scr1, "%s !", Data.label);
            lv_label_set_text_fmt(weather_label, "%s", Data.label);

            Serial.print("JSON object = ");
            Serial.println(myObject["main"]);
            Serial.print("Icon = ");
            Serial.println(Data.code);
            
            vTaskDelete(WeatherUpdateTask);
        }
        else
            Serial.println("WiFi Disconnected");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void LocalTime(void * pvParameters){
    for(;;){
        if(!getLocalTime(&timeinfo)){
            Serial.println("Failed to obtain time");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            continue;
        }else{
            hour = timeinfo.tm_hour + 7;
            if(hour > 23)
                hour -= 24;
            minute = timeinfo.tm_min;
            Month = timeinfo.tm_mon;
            Week = timeinfo.tm_mon;
            Day = timeinfo.tm_mday;
            Year = timeinfo.tm_year + 1900;
            lv_label_set_text_fmt(hour_label, "%d", hour);
            lv_label_set_text_fmt(minute_label, "%d", minute);
            lv_label_set_text_fmt(Week_label, "%s", daysOfTheWeek[Week]);
            lv_label_set_text_fmt(Day_label, "%d %s %d", Day, monthOfTheYear[Month], Year);
            vTaskDelete(NULL);
        }
    }
}

void IRAM_ATTR detectPress()
{
    Serial.println("PRESSED");
    switch (cur_scr)
    {
    case Screen1:
        ui_init_2();
        break;
    case Screen2:
        ui_init_1();
        break;
    default:
        break;
    }
}

void UIHandle( void * pvParameters )
{
    for(;;)
    {
        lv_timer_handler();
        vTaskDelay(5 / portTICK_PERIOD_MS);
    }
}

#if LV_SETUP

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
    Serial.printf(buf);
    Serial.flush();
}
#endif
/*Change to your screen resolution*/
static const uint16_t screenWidth  = 240;
static const uint16_t screenHeight = 320;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * 10 ];
TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    tft.startWrite();
    tft.setAddrWindow( area->x1, area->y1, w, h );
    tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
    tft.endWrite();

    lv_disp_flush_ready( disp );
}   

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch( &touchX, &touchY, 600 );

    if( !touched )
    {
        data->state = LV_INDEV_STATE_REL;
    }
    else
    {
        data->state = LV_INDEV_STATE_PR;

        /*Set the coordinates*/
        data->point.x = touchX;
        data->point.y = touchY;

        Serial.print( "Data x " );
        Serial.println( touchX );

        Serial.print( "Data y " );
        Serial.println( touchY );
    }
}

#endif

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    WiFi.mode(WIFI_MODE_APSTA);
    Serial.println(WiFi.macAddress());
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }else {
        Serial.println("Success");
    }
    // Once ESPNow is successfully Init, we will register for recv CB to
    // get recv packer info
    esp_now_register_recv_cb(OnDataRecv);
    lv_init();
    
#if LV_USE_LOG != 0
    lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

#if LV_USE_UI
    tft.begin();          /* TFT init */
    tft.setRotation( 1 );
    uint16_t calData[5] = { 275, 3620, 264, 3532, 7 };
    tft.setTouch( calData );

    lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * 10 );

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenHeight;
    disp_drv.ver_res = screenWidth;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init( &indev_drv );
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register( &indev_drv );

#endif

    // WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
    // while (WiFi.status() != WL_CONNECTED) {
    //     delay(500);
    //     Serial.print(".");
    // }
    // client.setServer(MQTT_SERVER, MQTT_PORT );
    // client.setCallback(callback);
    // connect_to_broker();
    // pinMode(LED, OUTPUT);
    WiFi.disconnect();
    TaskSetup();
}

void TaskSetup()
{
    #if !TEST
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    attachInterrupt(digitalPinToInterrupt(phys_btn), detectPress, FALLING);
    
    // xTaskCreatePinnedToCore(keepWifiAlive, "keepWiFi", 2200, NULL, 11, &KeepWifiTask, CONFIG_ARDUINO_RUNNING_CORE);
    xTaskCreate(UIHandle, "ui_handle", 3200, NULL, 10, &UIHandleTask);
    xTaskCreate(WeatherUpdate, "weather", 6000, NULL, 3, &WeatherUpdateTask);
    xTaskCreate(LocalTime, "time", 1200, NULL, 1, &LocalTimeTask);
    // xTaskCreate(MQTTTest, "MQTT", 2500, NULL, 9, &MQTTTask);

//------------------------BUILD PAGES------------------------//
    
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    ui_weather_screen_init();
    ui_scr_temp_init();
    ui_screen_light_init();
    ui_init_1();

    #elif TEST
    lv_obj_t * parent = lv_obj_create(lv_scr_act());
    lv_obj_t * label = lv_label_create(parent);
    lv_obj_center(label);
    lv_obj_center(parent);
    lv_label_set_text(label, "TESSTTTTTTTTTT");
    //xTaskCreate(UIHandle, "ui_handle", 5000, NULL, 1, &UIHandleTask);
    #endif

}

void loop()
{
}

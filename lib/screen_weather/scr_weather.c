#include "scr_weather.h"
#include "ui_share.h"

//--------------------------STATIC PROTOTYPES-------------------------//

void ui_init_weather(void);
void ui_weather_screen_init(void);
static void panel_style_init(void);
static void main_panel_create(lv_obj_t* parent);
static void side_panel_create(lv_obj_t* parent);
static void weather_4_days(lv_obj_t* parent);


//--------------------------STATIC VARIABLES--------------------------//

static lv_obj_t* ui_scr_weather;
static lv_obj_t* main_panel;
static lv_obj_t* side_panel;
static lv_style_t panel_style;

//--------------------------GLOBAL FUNCTIONS--------------------------//

void ui_init_weather(void)
{
    lv_scr_load_anim(ui_scr_weather, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
    cur_scr = Scr_weather;
}

void ui_weather_screen_init(void)
{
    panel_style_init();
    
    ui_scr_weather = lv_obj_create(NULL);
    lv_obj_add_flag(ui_scr_weather, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui_scr_weather, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen2);
    lv_obj_set_style_bg_color(ui_scr_weather, lv_color_hex(0x353d4d), 0);

    lv_obj_set_style_pad_all(ui_scr_weather, 0, 0);
    side_panel_create(ui_scr_weather);
    main_panel_create(ui_scr_weather);
}


//---------------------------STATIC FUNCTIONS--------------------------//

static void panel_style_init()
{
    lv_style_init(&panel_style);
    lv_style_set_bg_color(&panel_style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&panel_style, 100);

    lv_style_set_border_opa(&panel_style, 255);
    lv_style_set_border_side(&panel_style, LV_BORDER_SIDE_NONE);
    lv_style_set_border_width(&panel_style, 0);
    lv_style_set_border_color(&panel_style, lv_color_hex(0xFFFFFF));;
    lv_style_set_border_opa(&panel_style, 50);

    lv_style_set_pad_all(&panel_style, 0);
    lv_style_set_text_color(&panel_style, lv_color_white());

    lv_style_set_radius(&panel_style, 0);
    lv_style_set_height(&panel_style, lv_pct(45));
    lv_style_set_width(&panel_style, lv_pct(50));
}

static void main_panel_create(lv_obj_t* parent)
{
    main_panel = lv_obj_create(parent);
    lv_obj_add_style(main_panel, &panel_style, 0);
    lv_obj_set_style_radius(main_panel, 10, 0);
    lv_obj_align(main_panel, LV_ALIGN_LEFT_MID, lv_pct(5), 0);
    lv_obj_set_size(main_panel, lv_pct(40), lv_pct(70));
    lv_obj_set_style_bg_img_src(main_panel, &weather_main_panel_bg, 0);
    lv_obj_set_style_bg_img_recolor(main_panel, lv_color_hex(0x4888FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(main_panel, 80, LV_PART_MAIN | LV_STATE_DEFAULT);

    Week_label = lv_label_create(main_panel);
    lv_label_set_text_fmt(Week_label, "%s", daysOfTheWeek[Week]);
    lv_obj_align(Week_label, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_set_style_text_font(Week_label, &lv_font_montserrat_16, 0);

    Day_label = lv_label_create(main_panel);
    lv_label_set_text_fmt(Day_label, "%d ", Day);
    lv_obj_align(Day_label, LV_ALIGN_TOP_LEFT, 10, 30);
    lv_obj_set_style_text_font(Day_label, &lv_font_montserrat_12, 0);

    weather_label = lv_label_create(main_panel);
    lv_obj_align(weather_label, LV_ALIGN_BOTTOM_LEFT, 10, -10);
    lv_obj_set_style_text_font(weather_label, &lv_font_montserrat_12, 0);
    lv_label_set_text(weather_label, "Clear");

    temperature = lv_label_create(main_panel);
    lv_obj_align(temperature, LV_ALIGN_BOTTOM_LEFT, 10, -30);
    lv_obj_set_style_text_font(temperature, &lv_font_montserrat_18, 0);
    lv_label_set_text_fmt(temperature, "%d C", 19);

    weather_icon = lv_img_create(main_panel);
    lv_img_set_src(weather_icon, &w01d);
    lv_img_set_zoom(weather_icon, 200);
    lv_obj_set_style_img_recolor(weather_icon, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(weather_icon, 255, 0);
    lv_obj_align(weather_icon, LV_ALIGN_BOTTOM_LEFT, 0, -50);
}

static void side_panel_create(lv_obj_t* parent)
{
    static lv_style_t text;
    lv_style_init(&text);
    lv_style_set_text_font(&text, &lv_font_montserrat_10);
    lv_style_set_align(&text, LV_ALIGN_TOP_LEFT);

    side_panel = lv_obj_create(parent);
    lv_obj_add_style(side_panel, &panel_style, 0);
    lv_obj_set_style_radius(side_panel, 0, 0);
    lv_obj_align(side_panel, LV_ALIGN_RIGHT_MID, lv_pct(-6), 0);
    lv_obj_set_size(side_panel, lv_pct(50), lv_pct(60));
    lv_obj_set_style_bg_color(side_panel, lv_color_hex(0x202831), 0);
    lv_obj_set_style_bg_opa(side_panel, 255, 0);
    lv_obj_set_style_radius(side_panel, 5, 0);

    lv_obj_t* percipitation_label = lv_label_create(side_panel);
    lv_obj_add_style(percipitation_label, &text, 0);
    lv_obj_set_pos(percipitation_label, 10, 10);
    lv_label_set_text(percipitation_label, "Percipitation");
    lv_obj_t* percipitation = lv_label_create(side_panel);
    lv_obj_align(percipitation, LV_ALIGN_TOP_RIGHT, -10, 10);
    lv_obj_set_style_text_font(percipitation, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(percipitation, "%d", 100);

    lv_obj_t* humidity_label = lv_label_create(side_panel);
    lv_obj_add_style(humidity_label, &text, 0);
    lv_obj_set_pos(humidity_label, 10, 25);
    lv_label_set_text(humidity_label, "Humidity");
    humidity = lv_label_create(side_panel);
    lv_obj_align(humidity, LV_ALIGN_TOP_RIGHT, -10, 25);
    lv_obj_set_style_text_font(humidity, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(humidity, "%d", 100);

    lv_obj_t* wind_label = lv_label_create(side_panel);
    lv_obj_add_style(wind_label, &text, 0);
    lv_obj_set_pos(wind_label, 10, 40);
    lv_label_set_text(wind_label, "Wind");
    lv_obj_t* wind = lv_label_create(side_panel);
    lv_obj_align(wind, LV_ALIGN_TOP_RIGHT, -10, 40);
    lv_obj_set_style_text_font(wind, &lv_font_montserrat_10, 0);
    lv_label_set_text_fmt(wind, "%d", 15);

    weather_4_days(side_panel);
}

static void weather_4_days(lv_obj_t* parent)
{
    lv_obj_t* panel = lv_obj_create(parent);
    lv_obj_align(panel, LV_ALIGN_BOTTOM_MID, 0, -10);
    lv_obj_set_style_radius(panel, 5, 0);
    lv_obj_add_style(panel, &panel_style, 0);
    lv_obj_set_size(panel, lv_pct(90), lv_pct(50));

    lv_obj_t* day1_icon = lv_img_create(panel);
    lv_img_set_src(day1_icon, &w10d);
    lv_obj_set_style_pad_all(day1_icon, 0, 0);
    lv_obj_set_align(day1_icon, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_img_recolor(day1_icon, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(day1_icon, 255, 0);
    lv_img_set_zoom(day1_icon, 100);
    lv_obj_set_size(day1_icon, lv_pct(30), lv_pct(50));
    lv_obj_t* day1_label = lv_label_create(panel);
    lv_obj_align(day1_label, LV_ALIGN_BOTTOM_LEFT, 12, -5);
    lv_label_set_text_fmt(day1_label, "%d'C", 20);

    lv_obj_t* day2_icon = lv_img_create(panel);
    lv_img_set_src(day2_icon, &w10d);
    lv_obj_set_style_pad_all(day2_icon, 0, 0);
    lv_obj_align(day2_icon, LV_ALIGN_TOP_MID, -3, 0);
    lv_obj_set_style_img_recolor(day2_icon, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(day2_icon, 255, 0);
    lv_img_set_zoom(day2_icon, 100);
    lv_obj_set_size(day2_icon, lv_pct(30), lv_pct(50));
    lv_obj_t* day2_label = lv_label_create(panel);
    lv_obj_align(day2_label, LV_ALIGN_BOTTOM_MID, 5, -5);
    lv_label_set_text_fmt(day2_label, "%d'C", 18);

    lv_obj_t* day3_icon = lv_img_create(panel);
    lv_img_set_src(day3_icon, &w09d);
    lv_obj_set_style_pad_all(day3_icon, 0, 0);
    lv_obj_align(day3_icon, LV_ALIGN_TOP_RIGHT, -5, 0);
    lv_obj_set_style_img_recolor(day3_icon, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(day3_icon, 255, 0);
    lv_img_set_zoom(day3_icon, 100);
    lv_obj_set_size(day3_icon, lv_pct(30), lv_pct(50));
    lv_obj_t* day3_label = lv_label_create(panel);
    lv_obj_align(day3_label, LV_ALIGN_BOTTOM_RIGHT, -5, -5);
    lv_label_set_text_fmt(day3_label, "%d'C", 21);
}
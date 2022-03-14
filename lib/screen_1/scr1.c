#include "scr1.h"
#include "ui_share.h"

//--------------------------STATIC PROTOTYPES-------------------------//

static void panel_style_init(void);
static void panel_time_creat(lv_obj_t * parent);
static void panel_weather_creat(lv_obj_t * parent);
static void msg_box_creat(void);
static void noti_btn_creat(lv_obj_t * parent);
static void time_timer_cb(lv_timer_t * timer);

//--------------------------STATIC VARIABLES--------------------------//

static lv_obj_t * boot_gif;
static lv_obj_t * ui_Screen1;
static lv_obj_t * left_panel;
static lv_obj_t * right_panel;
static lv_obj_t * noti_btn;
static lv_obj_t * noti_num;

struct tm timeinfo;
uint8_t hour;
uint8_t minute;

static lv_style_t panel_style;
static uint8_t checked_noti = 0;

//--------------------------GLOBAL FUNCTIONS--------------------------//


void ui_init_1(void)
{
    lv_scr_load_anim(ui_Screen1, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
    cur_scr = Screen1;
    lv_obj_add_event_cb(ui_Screen1, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen2);
    lv_obj_add_flag(ui_Screen1, LV_OBJ_FLAG_CLICKABLE);
}

void ui_Screen1_screen_init(void)
{
    panel_style_init();

    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x234f66), 0);
    boot_gif = lv_gif_create(ui_Screen1);
    lv_gif_set_src(boot_gif, &boot_gif_img);
    lv_obj_center(boot_gif);

    panel_time_creat(ui_Screen1);
    panel_weather_creat(ui_Screen1);
    noti_btn_creat(right_panel);
}

//---------------------------STATIC FUNCTIONS--------------------------//

static void panel_style_init(void)
{
    lv_style_init(&panel_style);
    lv_style_set_bg_color(&panel_style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&panel_style, 100);
    lv_style_set_border_opa(&panel_style, 255);
    lv_style_set_border_side(&panel_style, LV_BORDER_SIDE_NONE);
    lv_style_set_pad_all(&panel_style, 0);
    lv_style_set_text_color(&panel_style, lv_color_white());
    lv_style_set_radius(&panel_style, 0);
}

//************TIME**********//


static void time_timer_cb(lv_timer_t * timer)
{
    lv_label_set_text_fmt(hour_label, "%d", hour);
    lv_label_set_text_fmt(minute_label, "%d", minute);
    minute += 1;
    if(minute > 59) {
        minute = 0;
        hour += 1;
    }
    if(hour > 23) {
        hour = 0;
        update_date();
    }
    if(hour == 7 && checked_noti == 1){
        noti_btn_creat(right_panel);
    }
}

static void panel_time_creat(lv_obj_t * parent)
{
    left_panel = lv_obj_create(parent);
    lv_obj_set_size(left_panel, lv_pct(31), lv_pct(100));
    lv_obj_set_align(left_panel, LV_ALIGN_LEFT_MID);
    lv_obj_add_style(left_panel, &panel_style, 0);

    //Time
    hour_label = lv_label_create(left_panel);
    lv_obj_set_style_text_font(hour_label, &lv_font_montserrat_30, 0);
    lv_obj_align(hour_label, LV_ALIGN_CENTER, 0, lv_pct(-15));
    minute_label = lv_label_create(left_panel);
    lv_obj_set_style_text_font(minute_label, &lv_font_montserrat_30, 0);
    lv_obj_align(minute_label, LV_ALIGN_CENTER, 0, lv_pct(15));

    lv_timer_create(time_timer_cb, 1000 * 60, NULL);
}


//************WEATHER**********//


static void panel_weather_creat(lv_obj_t * parent)
{
    right_panel = lv_obj_create(parent);
    lv_obj_set_size(right_panel, lv_pct(31), lv_pct(100));
    lv_obj_set_align(right_panel, LV_ALIGN_RIGHT_MID);
    lv_obj_add_style(right_panel, &panel_style, 0);

    weather_icon_scr1 = lv_img_create(right_panel);
    lv_img_set_src(weather_icon_scr1, &w01d);
    lv_obj_align(weather_icon_scr1, LV_ALIGN_CENTER, 0, lv_pct(-15));
    icon_white_setup(weather_icon_scr1);

    weather_label_scr1 = lv_label_create(right_panel);
    lv_obj_set_size(weather_label_scr1, 60, LV_SIZE_CONTENT);
    lv_obj_align(weather_label_scr1, LV_ALIGN_CENTER, 0, lv_pct(15));
    lv_label_set_text(weather_label_scr1, "Clear!\nGo Outside");
}

//************NOTIFICATION**********//


static void noti_btn_click(lv_event_t * e)
{
    LV_UNUSED(e);
    msg_box_creat();
}

static void delete_msg(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_add_flag(ta, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(noti_btn, LV_OBJ_FLAG_HIDDEN);
    checked_noti = 1;
}

static void noti_btn_creat(lv_obj_t * parent)
{
    //Noti
    noti_btn = lv_obj_create(parent);
    lv_obj_set_size(noti_btn, 25, 25);
    lv_obj_align(noti_btn, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_set_style_bg_color(noti_btn, lv_color_hex(0xB71C1C), 0);
    lv_obj_set_style_border_color(noti_btn, lv_color_hex(0xEF5350), 0);
    lv_obj_set_style_pad_all(noti_btn, 0, 0);
    lv_obj_clear_flag(noti_btn, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(noti_btn, LV_OBJ_FLAG_CLICKABLE);

    noti_num = lv_label_create(noti_btn);
    lv_obj_center(noti_num);
    lv_obj_set_style_text_color(noti_num, lv_color_white(), 0);
    lv_label_set_text_fmt(noti_num, "1");

    lv_anim_t float_noti;
    lv_anim_init(&float_noti);
    lv_anim_set_var(&float_noti, noti_btn);
    lv_anim_set_exec_cb(&float_noti, (void*)lv_obj_set_y);
    lv_anim_set_values(&float_noti, 5, 0);
    lv_anim_set_time(&float_noti, 400);
    lv_anim_set_playback_time(&float_noti, 600);
    lv_anim_set_repeat_delay(&float_noti, 2000);
    lv_anim_set_repeat_count(&float_noti, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&float_noti);

    lv_obj_add_event_cb(noti_btn, noti_btn_click, LV_EVENT_CLICKED, NULL);

    checked_noti = 0;
}

static void msg_box_creat(void)
{
    lv_obj_t * msg_bg = lv_obj_create(ui_Screen1);
    lv_obj_set_size(msg_bg, 320, 240);
    lv_obj_add_style(msg_bg, &panel_style, 0);
    lv_obj_set_style_bg_opa(msg_bg, 200, 0);
    lv_obj_add_flag(msg_bg, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(msg_bg, delete_msg, LV_EVENT_CLICKED, NULL);

    lv_obj_t * msg = lv_obj_create(msg_bg);
    lv_obj_set_style_pad_top(msg, 0, 0);
    lv_obj_align(msg, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t * msg_title = lv_label_create(msg);
    lv_obj_align(msg_title, LV_ALIGN_TOP_LEFT, 0, 5);
    lv_obj_set_size(msg_title, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_set_style_radius(msg_title, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(msg_title, lv_color_hex(0xB2BAFC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(msg_title, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(msg_title, LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_text(msg_title, "WiFi");

    lv_obj_t * wl_label = lv_label_create(msg);
    lv_obj_align_to(wl_label, msg_title, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10);
    lv_obj_set_size(wl_label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_label_set_text_fmt(wl_label, "%s\n%s", WIFI_NETWORK, WIFI_PASSWORD);

    lv_anim_t a;
    lv_anim_init(&a);

    lv_anim_set_var(&a, msg);
    lv_anim_set_exec_cb(&a, (void*)lv_obj_set_x);
    lv_anim_set_values(&a, 150, 0);
    lv_anim_set_time(&a, 300);
    lv_anim_start(&a);

    lv_anim_set_exec_cb(&a, (void*)lv_obj_set_y);
    lv_anim_set_values(&a, -110, 0);
    lv_anim_set_time(&a, 300);
    lv_anim_start(&a);

    lv_anim_set_exec_cb(&a, (void*)lv_obj_set_height);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_set_time(&a, 300);
    lv_anim_start(&a);

    lv_anim_set_exec_cb(&a, (void*)lv_obj_set_width);
    lv_anim_set_values(&a, 0, 200);
    lv_anim_set_time(&a, 300);
    lv_anim_start(&a);
}

#include "scr3.h"
#include "ui_share.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t* ui_Screen3;
static lv_obj_t* ui_left_panel;
static lv_obj_t* ui_weather;
static lv_obj_t* ui_weather_label;
static lv_obj_t* ui_weather_icon;
static lv_obj_t* ui_date;
static lv_obj_t* ui_date_label;
static lv_obj_t* ui_task;
static lv_obj_t* ui_task_label;
static lv_obj_t* ui_right_panel;
static lv_obj_t* ui_time;
static lv_obj_t* ui_minute;
static lv_obj_t* ui_hour;
static lv_obj_t* ui_push_box;
static lv_obj_t* ui_button;
static lv_obj_t* ui_button_label;
static uint8_t date = 0;

static int8_t value_tran = 10;

static lv_style_t panel_style;

///////////////////// PROTOTYPES ////////////////////
static void count(void);
static void ui_event_button(lv_event_t* e);

///////////////////// ANIMATIONS ////////////////////

// FUNCTION HEADER
static void Animation_Animation(lv_obj_t* TargetObject, int delay);

// FUNCTION
static void Animation_Animation(lv_obj_t* TargetObject, int delay)
{
    value_tran = -value_tran;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, TargetObject);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, value_tran);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
}


///////////////////// FUNCTIONS ////////////////////

static void count(void)
{
    date++;
    if (date > 29)
        date = 1;
    lv_label_set_text_fmt(ui_date_label, "Feb, %d", date);
    lv_label_set_text_fmt(ui_hour, "%d", date);
}

static void ui_event_button(lv_event_t* e)
{
    LV_UNUSED(e);
    count();
    Animation_Animation(ui_hour, 0);
}

static void panel_style_init(void)
{
    lv_style_init(&panel_style);
    lv_style_set_bg_color(&panel_style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&panel_style, 0);
    lv_style_set_border_opa(&panel_style, 255);
    lv_style_set_border_side(&panel_style, LV_BORDER_SIDE_NONE);
    lv_style_set_pad_all(&panel_style, 0);
    lv_style_set_text_color(&panel_style, lv_color_white());
}


///////////////////// SCREENS ////////////////////
void ui_Screen3_screen_init(void)
{
    panel_style_init();

    ui_Screen3 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen3, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_img_src(ui_Screen3, &ui_img_bg_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui_Screen3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui_Screen3, 100, LV_PART_MAIN | LV_STATE_DEFAULT);

    // left_panel

    ui_left_panel = lv_obj_create(ui_Screen3);
    lv_obj_set_width(ui_left_panel, lv_pct(60));
    lv_obj_set_height(ui_left_panel, lv_pct(100));

    lv_obj_align(ui_left_panel, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_clear_flag(ui_left_panel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_style(ui_left_panel, &panel_style, 0);
    lv_obj_set_style_border_side(ui_left_panel, LV_BORDER_SIDE_RIGHT, 0);

    // weather

    ui_weather = lv_obj_create(ui_left_panel);

    lv_obj_set_width(ui_weather, lv_pct(100));
    lv_obj_set_height(ui_weather, lv_pct(33));

    lv_obj_align(ui_weather, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_clear_flag(ui_weather, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(ui_weather, &panel_style, 0);
    lv_obj_set_style_border_side(ui_weather, LV_BORDER_SIDE_BOTTOM, 0);

    // weather_label

    ui_weather_label = lv_label_create(ui_weather);

    lv_obj_set_width(ui_weather_label, lv_pct(65));
    lv_obj_set_height(ui_weather_label, LV_SIZE_CONTENT);

    lv_obj_align(ui_weather_label, LV_ALIGN_LEFT_MID, lv_pct(3), 0);

    lv_obj_clear_flag(ui_weather_label, LV_OBJ_FLAG_CLICKABLE);

    lv_label_set_text(ui_weather_label, "Ashita no Tenki");

    // weather_icon

    ui_weather_icon = lv_img_create(ui_weather);
    lv_img_set_src(ui_weather_icon, &ui_weather_gif);

    lv_obj_set_width(ui_weather_icon, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_weather_icon, LV_SIZE_CONTENT);

    lv_obj_align(ui_weather_icon, LV_ALIGN_RIGHT_MID, -10, -5);

    lv_obj_add_flag(ui_weather_icon, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_weather_icon, LV_OBJ_FLAG_SCROLLABLE);

    // date

    ui_date = lv_obj_create(ui_left_panel);

    lv_obj_set_width(ui_date, lv_pct(100));
    lv_obj_set_height(ui_date, lv_pct(33));


    lv_obj_align(ui_date, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_clear_flag(ui_date, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(ui_date, &panel_style, 0);
    lv_obj_set_style_border_side(ui_date, LV_BORDER_SIDE_BOTTOM, 0);

    // date_label

    ui_date_label = lv_label_create(ui_date);

    lv_obj_set_width(ui_date_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_date_label, LV_SIZE_CONTENT);
    lv_obj_center(ui_date_label);

    lv_obj_clear_flag(ui_date_label, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui_date_label, "Date");

    // task_panel
    ui_task = lv_obj_create(ui_left_panel);

    lv_obj_set_width(ui_task, lv_pct(100));
    lv_obj_set_height(ui_task, lv_pct(33));

    lv_obj_align(ui_task, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    lv_obj_clear_flag(ui_task, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_style(ui_task, &panel_style, 0);
    lv_obj_set_style_border_side(ui_task, LV_BORDER_SIDE_NONE, 0);

    // task_label

    ui_task_label = lv_label_create(ui_task);

    lv_obj_set_width(ui_task_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_task_label, LV_SIZE_CONTENT);
    lv_obj_center(ui_task_label);

    lv_obj_clear_flag(ui_task_label, LV_OBJ_FLAG_CLICKABLE);

    lv_label_set_text(ui_task_label, "No task. Relax...");


    // right_panel

    ui_right_panel = lv_obj_create(ui_Screen3);

    lv_obj_set_width(ui_right_panel, lv_pct(40));
    lv_obj_set_height(ui_right_panel, lv_pct(100));

    lv_obj_align(ui_right_panel, LV_ALIGN_TOP_RIGHT, 0, 0);

    lv_obj_clear_flag(ui_right_panel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_style(ui_right_panel, &panel_style, 0);

    // time

    ui_time = lv_obj_create(ui_right_panel);

    lv_obj_set_width(ui_time, lv_pct(100));
    lv_obj_set_height(ui_time, lv_pct(70));

    lv_obj_align(ui_time, LV_ALIGN_TOP_RIGHT, 0, 0);

    lv_obj_clear_flag(ui_time, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_style(ui_time, &panel_style, 0);
    lv_obj_set_style_border_side(ui_time, LV_BORDER_SIDE_BOTTOM, 0);

    // hour

    ui_hour = lv_label_create(ui_time);

    lv_obj_set_width(ui_hour, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_hour, LV_SIZE_CONTENT);

    lv_obj_align(ui_hour, LV_ALIGN_CENTER, 0, lv_pct(-20));

    lv_label_set_text(ui_hour, "Text");

    lv_obj_clear_flag(ui_hour, LV_OBJ_FLAG_CLICKABLE);

    // minute

    ui_minute = lv_label_create(ui_time);

    lv_obj_set_width(ui_minute, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_minute, LV_SIZE_CONTENT);

    lv_obj_align(ui_minute, LV_ALIGN_CENTER, 0, lv_pct(20));

    lv_label_set_text(ui_minute, "Text");

    lv_obj_clear_flag(ui_minute, LV_OBJ_FLAG_CLICKABLE);

    // push_box

    ui_push_box = lv_obj_create(ui_right_panel);

    lv_obj_set_width(ui_push_box, lv_pct(100));
    lv_obj_set_height(ui_push_box, lv_pct(30));

    lv_obj_align(ui_push_box, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    lv_obj_clear_flag(ui_push_box, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_style(ui_push_box, &panel_style, 0);

    // button

    ui_button = lv_btn_create(ui_push_box);

    lv_obj_set_width(ui_button, lv_pct(80));
    lv_obj_set_height(ui_button, lv_pct(71));

    lv_obj_align(ui_button, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_flag(ui_button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_button, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_button, ui_event_button, LV_EVENT_CLICKED, NULL);

    lv_obj_add_event_cb(ui_button, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen1);

    // button_label

    ui_button_label = lv_label_create(ui_button);

    lv_obj_set_width(ui_button_label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_button_label, LV_SIZE_CONTENT);

    lv_obj_align(ui_button_label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_clear_flag(ui_button_label, LV_OBJ_FLAG_CLICKABLE);

    lv_label_set_text(ui_button_label, "PUSH");

}

void ui_init_3(void)
{
    lv_scr_load_anim(ui_Screen3, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, false);
    cur_scr = Screen3;
}



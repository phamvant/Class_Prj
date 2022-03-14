// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.0
// LVGL VERSION: 8.2
// PROJECT: LVGL_demo

#ifndef UI_SHARE_H_INCLUDED
#define UI_SHARE_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"

#define WIFI_NETWORK "4T-Wifi-Connection"
#define WIFI_PASSWORD "88888888"

LV_IMG_DECLARE(w01d);
LV_IMG_DECLARE(w02d);
LV_IMG_DECLARE(w03d);
LV_IMG_DECLARE(w04d);
LV_IMG_DECLARE(w09d);
LV_IMG_DECLARE(w10d);
LV_IMG_DECLARE(w11d);
LV_IMG_DECLARE(w50d);

//-------------------structure-------------------//

extern char daysOfTheWeek[7][12];
extern char monthOfTheYear[12][4];
extern char weather_code[8][4];
extern char weather_code_night[8][4];

uint8_t Day;
uint8_t Week;
uint8_t Month;
int Year;

typedef struct clientData {
  int temp;
  int humidity;
  char code[4];
  char label[20];
}clientData;

clientData Data;

//-------------------Screen1_var--------------------//

uint8_t hour;
uint8_t minute;
lv_obj_t * hour_label;
lv_obj_t * minute_label;

//-----------------Screen_weather_var--------------------//

lv_obj_t * Week_label;
lv_obj_t * Day_label;

//--------------------------------------------------------//

enum Screen{Screen1 = 1, Screen2 = 2, Screen3 = 3, Scr_weather = 4};
enum Screen cur_scr;

void ui_init_weather();
void ui_init_3();
void ui_init_2();
void ui_init_1();

void weather_icon_changer(lv_obj_t* target, int change_val);
void icon_white_setup(lv_obj_t* target);

#define _UI_TEMPORARY_STRING_BUFFER_SIZE 32
#define _UI_BAR_PROPERTY_VALUE 0
#define _UI_BAR_PROPERTY_VALUE_WITH_ANIM 1
void _ui_bar_set_property(lv_obj_t * target, int id, int val);

#define _UI_BASIC_PROPERTY_POSITION_X 0
#define _UI_BASIC_PROPERTY_POSITION_Y 1
#define _UI_BASIC_PROPERTY_WIDTH 2
#define _UI_BASIC_PROPERTY_HEIGHT 3
void _ui_basic_set_property(lv_obj_t * target, int id, int val);

#define _UI_DROPDOWN_PROPERTY_SELECTED 0
void _ui_dropdown_set_property(lv_obj_t * target, int id, int val);

#define _UI_IMAGE_PROPERTY_IMAGE 0
void _ui_image_set_property(lv_obj_t * target, int id, uint8_t * val);

#define _UI_LABEL_PROPERTY_TEXT 0
void _ui_label_set_property(lv_obj_t * target, int id, char * val);

#define _UI_ROLLER_PROPERTY_SELECTED 0
#define _UI_ROLLER_PROPERTY_SELECTED_WITH_ANIM 1
void _ui_roller_set_property(lv_obj_t * target, int id, int val);

#define _UI_SLIDER_PROPERTY_VALUE 0
#define _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM 1
void _ui_slider_set_property(lv_obj_t * target, int id, int val);

void _ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

void _ui_arc_increment(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

void _ui_bar_increment(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

void _ui_slider_increment(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

#define _UI_MODIFY_FLAG_ADD 0
#define _UI_MODIFY_FLAG_REMOVE 1
#define _UI_MODIFY_FLAG_TOGGLE 2
void _ui_flag_modify(lv_obj_t * target, int32_t flag, int value);

#define _UI_MODIFY_STATE_ADD 0
#define _UI_MODIFY_STATE_REMOVE 1
#define _UI_MODIFY_STATE_TOGGLE 2
void _ui_state_modify(lv_obj_t * target, int32_t state, int value);

void _ui_opacity_set(lv_obj_t * target, int val);

void _ui_anim_callback_set_x(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_y(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_width(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_height(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_opacity(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_image_zoom(lv_anim_t * a, int32_t v);

void _ui_anim_callback_set_image_angle(lv_anim_t * a, int32_t v);

int32_t _ui_anim_callback_get_x(lv_anim_t * a);

int32_t _ui_anim_callback_get_y(lv_anim_t * a);

int32_t _ui_anim_callback_get_width(lv_anim_t * a);

int32_t _ui_anim_callback_get_height(lv_anim_t * a);

int32_t _ui_anim_callback_get_opacity(lv_anim_t * a);

int32_t _ui_anim_callback_get_image_zoom(lv_anim_t * a);

int32_t _ui_anim_callback_get_image_angle(lv_anim_t * a);

void _ui_arc_set_text_value(lv_obj_t * trg, lv_obj_t * src, char * prefix, char * postfix);

void _ui_slider_set_text_value(lv_obj_t * trg, lv_obj_t * src, char * prefix, char * postfix);

void _ui_checked_set_text_value(lv_obj_t * trg, lv_obj_t * src, char * txt_on, char * txt_off);

void update_date(void);

void ui_event_scr_by_click(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
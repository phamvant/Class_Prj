#ifndef _LVGL_DEMO_UI_H
#define _LVGL_DEMO_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"
#include <time.h>

LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(boot_gif_img);
LV_IMG_DECLARE(ui_weather_gif);

struct tm timeinfo;
uint8_t hour;
uint8_t minute;
lv_obj_t * hour_label;
lv_obj_t * minute_label;

void ui_init_1(void);
void ui_Screen1_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

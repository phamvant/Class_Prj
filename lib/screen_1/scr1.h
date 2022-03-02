#ifndef SCR1_H_INCLUDED
#define SCR1_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"
#include <time.h>

struct tm timeinfo;
lv_obj_t * weather_icon_scr1;
lv_obj_t * weather_label_scr1;

LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(boot_gif_img);
LV_IMG_DECLARE(ui_weather_gif);

void ui_init_1(void);
void ui_Screen1_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif

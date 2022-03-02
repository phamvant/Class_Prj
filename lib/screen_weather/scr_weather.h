#ifndef SCR_WEATHER_H_INCLUDED
#define SCR_WEATHER_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"

LV_IMG_DECLARE(weather_main_panel_bg);

void ui_init_weather(void);
void ui_weather_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif
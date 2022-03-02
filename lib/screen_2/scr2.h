#ifndef SCR2_H_INCLUDED
#define SCR2_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"

LV_IMG_DECLARE(lightbulb);
LV_IMG_DECLARE(circle_bg);
LV_IMG_DECLARE(weather);
LV_IMG_DECLARE(printer);
LV_IMG_DECLARE(security);

void ui_init_2(void);
void ui_Screen2_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif
#endif

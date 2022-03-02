#ifdef __cplusplus
extern "C" {
#endif

#include "../lvgl/lvgl.h"
extern lv_obj_t* ui_Screen3;

LV_IMG_DECLARE(ui_img_bg_png);    // assets\bg.png
LV_IMG_DECLARE(ui_weather_gif);    // assets\weather.png

void ui_init_3(void);
void ui_Screen3_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

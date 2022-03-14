#include "ui_share.h"
#include "scr2.h"

//--------------------------STATIC PROTOTYPES-------------------------//

static void panel_style_init(void);
static void func_title_create(lv_obj_t* parent);
static void panel_func1_create(lv_obj_t* parent);
static void panel_func2_create(lv_obj_t* parent);
static void panel_func3_create(lv_obj_t* parent);
static void panel_func4_create(lv_obj_t* parent);
static void bg_circle_anim(lv_obj_t* target);

// static void show_border(lv_obj_t* target);

//--------------------------STATIC VARIABLES--------------------------//

static lv_obj_t* ui_Screen2;
static lv_obj_t* f1_panel;
static lv_obj_t* f2_panel;
static lv_obj_t* f3_panel;
static lv_obj_t* f4_panel;
static lv_obj_t* func_title_panel;

static lv_style_t panel_style;


//--------------------------GLOBAL FUNCTIONS--------------------------//

void ui_init_2(void)
{
    lv_scr_load_anim(ui_Screen2, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
    cur_scr = Screen1;
    lv_obj_add_event_cb(ui_Screen2, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen1);
    lv_obj_add_flag(ui_Screen2, LV_OBJ_FLAG_CLICKABLE);
}

void ui_Screen2_screen_init(void)
{
    panel_style_init();

    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_Screen2, lv_color_hex(0x234f66), 0);
    panel_func1_create(ui_Screen2);
    panel_func2_create(ui_Screen2);
    panel_func3_create(ui_Screen2);
    panel_func4_create(ui_Screen2);
    func_title_create(ui_Screen2);
}


//---------------------------STATIC FUNCTIONS--------------------------//

static void panel_style_init()
{
    lv_style_init(&panel_style);
    lv_style_set_bg_color(&panel_style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&panel_style, 100);

    lv_style_set_border_opa(&panel_style, 255);
    lv_style_set_border_side(&panel_style, LV_BORDER_SIDE_FULL);
    lv_style_set_border_width(&panel_style, 1);
    lv_style_set_border_color(&panel_style, lv_color_hex(0xFFFFFF));;
    lv_style_set_border_opa(&panel_style, 50);

    lv_style_set_pad_all(&panel_style, 0);
    lv_style_set_text_color(&panel_style, lv_color_white());
 
    lv_style_set_radius(&panel_style, 0);
    lv_style_set_height(&panel_style, lv_pct(45));
    lv_style_set_width(&panel_style, lv_pct(50));
}


//************FUNCTION1**********//

// static void show_border(lv_obj_t* target)
// {
//     lv_obj_set_style_border_side(target, LV_BORDER_SIDE_FULL, 0);
//     lv_obj_set_style_border_color(target, lv_color_white(), 0);
//     lv_obj_set_style_border_opa(target, 255, 0);
//     lv_obj_set_style_border_width(target, 1, 0);
// }

static void func_click(lv_event_t* e)
{
    lv_obj_t* ta = lv_event_get_user_data(e);
    bg_circle_anim(ta);
}

static void bg_circle_anim(lv_obj_t* target)
{
    lv_obj_t* target_child = lv_obj_get_child(target, 0);

    lv_anim_t a;
    lv_anim_t b;
    lv_anim_init(&a);
    lv_anim_init(&b);

    lv_anim_set_var(&a, target);
    lv_anim_set_var(&b, target_child);

    lv_anim_set_exec_cb(&a, (void*)lv_img_set_angle);
    lv_anim_set_values(&a, 0, 360 * 10);
    lv_anim_set_time(&a, 300);

    lv_anim_set_exec_cb(&b, (void*)lv_img_set_zoom);
    lv_anim_set_values(&b, 256, 320);
    lv_anim_set_time(&b, 150);
    lv_anim_set_repeat_delay(&b, 0);
    lv_anim_set_playback_time(&b, 150);

    lv_anim_start(&a);
    lv_anim_start(&b);
}

static void func_title_create(lv_obj_t* parent)
{
    func_title_panel = lv_obj_create(parent);
    lv_obj_t* func_title = lv_label_create(func_title_panel);
    lv_obj_add_style(func_title_panel, &panel_style, 0);
    lv_obj_set_size(func_title_panel, lv_pct(100), lv_pct(10));
    lv_label_set_text(func_title, "All Function");
    lv_obj_set_style_text_align(func_title, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(func_title, lv_color_white(), 0);
    lv_obj_set_style_pad_all(func_title, 0, 0);
    lv_obj_center(func_title);
    
    lv_obj_t* back_btn = lv_btn_create(func_title_panel);
    lv_obj_set_size(back_btn, lv_pct(5), lv_pct(70));
    lv_obj_align(back_btn, LV_ALIGN_LEFT_MID, 10, 0);
    lv_obj_add_event_cb(back_btn, ui_event_scr_by_click, LV_EVENT_CLICKED, (void*)Screen1);
}

static void panel_func1_create(lv_obj_t* parent)
{
    f1_panel = lv_obj_create(parent);
    lv_obj_align(f1_panel, LV_ALIGN_TOP_LEFT, 0, lv_pct(10));
    lv_obj_add_style(f1_panel, &panel_style, 0);

    lv_obj_t* f1_icon_bg = lv_img_create(f1_panel);
    lv_img_set_src(f1_icon_bg, &circle_bg);
    lv_obj_set_style_img_recolor(f1_icon_bg, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(f1_icon_bg, 255, 0);
    lv_obj_center(f1_icon_bg);

    lv_obj_t* f1_icon = lv_img_create(f1_icon_bg);
    lv_img_set_src(f1_icon, &lightbulb);
    lv_img_set_zoom(f1_icon, 290);
    lv_obj_center(f1_icon);

    lv_obj_add_flag(f1_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(f1_icon, ui_event_scr_by_click, LV_EVENT_CLICKED, (void*)Src_light);
}

static void panel_func2_create(lv_obj_t* parent)
{
    f2_panel = lv_obj_create(parent);
    lv_obj_align(f2_panel, LV_ALIGN_TOP_RIGHT, 0, lv_pct(10));
    lv_obj_add_style(f2_panel, &panel_style, 0);

    lv_obj_t* f2_icon_bg = lv_img_create(f2_panel);
    lv_img_set_src(f2_icon_bg, &circle_bg);
    lv_obj_set_style_img_recolor(f2_icon_bg, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(f2_icon_bg, 255, 0);
    lv_obj_center(f2_icon_bg);

    lv_obj_t* f2_icon = lv_img_create(f2_icon_bg);
    lv_img_set_src(f2_icon, &security);
    lv_obj_center(f2_icon);

    lv_obj_add_flag(f2_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(f2_icon, func_click, LV_EVENT_CLICKED, f2_icon_bg);
}

static void panel_func3_create(lv_obj_t* parent)
{
    f3_panel = lv_obj_create(parent);
    lv_obj_set_align(f3_panel, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_add_style(f3_panel, &panel_style, 0);

    lv_obj_t* f3_icon_bg = lv_img_create(f3_panel);
    lv_img_set_src(f3_icon_bg, &circle_bg);
    lv_obj_set_style_img_recolor(f3_icon_bg, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(f3_icon_bg, 255, 0);
    lv_obj_center(f3_icon_bg);

    lv_obj_t* f3_icon = lv_img_create(f3_icon_bg);
    lv_img_set_src(f3_icon, &printer);
    lv_obj_center(f3_icon);

    lv_obj_add_flag(f3_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(f3_icon, ui_event_scr_by_click, LV_EVENT_CLICKED, (void*)Scr_temp);
}

static void panel_func4_create(lv_obj_t* parent)
{
    f4_panel = lv_obj_create(parent);
    lv_obj_set_align(f4_panel, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_add_style(f4_panel, &panel_style, 0);

    lv_obj_t* f4_icon_bg = lv_img_create(f4_panel);
    lv_img_set_src(f4_icon_bg, &circle_bg);
    lv_obj_set_style_img_recolor(f4_icon_bg, lv_color_white(), 0);
    lv_obj_set_style_img_recolor_opa(f4_icon_bg, 255, 0);
    lv_obj_center(f4_icon_bg);

    lv_obj_t* f4_icon = lv_img_create(f4_icon_bg);
    lv_img_set_src(f4_icon, &weather);
    lv_obj_center(f4_icon);

    lv_obj_add_flag(f4_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(f4_icon, ui_event_scr_by_click, LV_EVENT_CLICKED, (void*)Scr_weather);
}


// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.2
// LVGL VERSION: 8.2
// PROJECT: New_Scr

#include "scr_light.h"
#include "ui_share.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_scr_light;
static lv_obj_t * ui_Panel1;
static lv_obj_t * ui_Image3;
static lv_obj_t * ui_Panel1_copy;
static lv_obj_t * ui_Image2;
static lv_obj_t * ui_Panel1_copy_copy;
static lv_obj_t * ui_Image4;
static lv_obj_t * ui_Panel1_copy_copy_copy;
static lv_obj_t * ui_Image1;
static lv_obj_t * ui_Panel2;
static lv_obj_t * ui_Label1;
static lv_obj_t * ui_Label2;
static lv_obj_t * ui_Label3;
static lv_obj_t * ui_Label4;
static lv_obj_t * ui_Label5;

///////////////////// ANIMATIONS ////////////////////

static void room_change(uint32_t y)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui_Panel2);
    lv_anim_set_exec_cb(&a, (void*)lv_obj_set_y);
    lv_anim_set_values(&a, lv_obj_get_y(ui_Panel2), y);
    lv_anim_set_time(&a, 300);
    lv_anim_start(&a);
}

///////////////////// FUNCTIONS ////////////////////

static void ui_event_Label1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        room_change(165);
    }
}
static void ui_event_Label2(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        room_change(125);
    }
}
static void ui_event_Label3(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        room_change(85);
        // _ui_anim_callback_set_y(ui_Panel2, 85);
        // _ui_basic_set_property(ui_Panel2, _UI_BASIC_PROPERTY_POSITION_Y,  85);
    }
}
static void ui_event_Label4(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        room_change(45);
    }
}

static void clicked_event(lv_event_t* e)
{
    lv_obj_t* ta = lv_event_get_target(e);
    if (!lv_obj_has_state(ta, LV_STATE_CHECKED)) {
        lv_obj_set_style_shadow_opa(ta, 0, 0);
        lv_obj_set_style_border_opa(ta, 150, 0);
        lv_obj_set_style_border_side(ta, LV_BORDER_SIDE_FULL, 0);
        lv_obj_set_style_border_width(ta, 1, 0);
        lv_obj_set_style_border_color(ta, lv_color_hex(0x5b5b5b), 0);
    }
    else {
        lv_obj_set_style_shadow_opa(ta, 255, 0);
        lv_obj_set_style_border_opa(ta, 0, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_screen_light_init(void)
{

    // Screen1

    ui_scr_light = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_scr_light, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_scr_light, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui_scr_light, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen2);

    lv_obj_set_style_bg_color(ui_scr_light, lv_color_hex(0xDFDFDF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_scr_light, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_scr_light, lv_color_hex(0xDDAEC1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_scr_light, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_scr_light, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_scr_light, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Panel1

    ui_Panel1 = lv_obj_create(ui_scr_light);

    lv_obj_set_width(ui_Panel1, 85);
    lv_obj_set_height(ui_Panel1, 78);

    lv_obj_set_x(ui_Panel1, -100);
    lv_obj_set_y(ui_Panel1, 56);

    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Panel1, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0xF1E1C2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel1, lv_color_hex(0xFCBC98), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel1, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image3

    ui_Image3 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image3, &living3);

    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image3, 0);
    lv_obj_set_y(ui_Image3, 0);

    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);

    // Panel1_copy

    ui_Panel1_copy = lv_obj_create(ui_scr_light);

    lv_obj_set_width(ui_Panel1_copy, 85);
    lv_obj_set_height(ui_Panel1_copy, 78);

    lv_obj_set_x(ui_Panel1_copy, 10);
    lv_obj_set_y(ui_Panel1_copy, -42);

    lv_obj_set_align(ui_Panel1_copy, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Panel1_copy, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(ui_Panel1_copy, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1_copy, lv_color_hex(0xE1DAE6), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel1_copy, lv_color_hex(0xF6C4ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel1_copy, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1_copy, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel1_copy, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel1_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel1_copy, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel1_copy, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel1_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel1_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image2

    ui_Image2 = lv_img_create(ui_Panel1_copy);
    lv_img_set_src(ui_Image2, &living2);

    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image2, 0);
    lv_obj_set_y(ui_Image2, 0);

    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);

    // Panel1_copy_copy

    ui_Panel1_copy_copy = lv_obj_create(ui_scr_light);

    lv_obj_set_width(ui_Panel1_copy_copy, 85);
    lv_obj_set_height(ui_Panel1_copy_copy, 78);

    lv_obj_set_x(ui_Panel1_copy_copy, 10);
    lv_obj_set_y(ui_Panel1_copy_copy, 56);

    lv_obj_set_align(ui_Panel1_copy_copy, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Panel1_copy_copy, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(ui_Panel1_copy_copy, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1_copy_copy, lv_color_hex(0xAFF2D8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel1_copy_copy, lv_color_hex(0x9B98ED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1_copy_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel1_copy_copy, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1_copy_copy, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel1_copy_copy, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel1_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel1_copy_copy, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel1_copy_copy, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel1_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel1_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image4

    ui_Image4 = lv_img_create(ui_Panel1_copy_copy);
    lv_img_set_src(ui_Image4, &living4);

    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image4, 0);
    lv_obj_set_y(ui_Image4, 0);

    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);

    // Panel1_copy_copy_copy

    ui_Panel1_copy_copy_copy = lv_obj_create(ui_scr_light);

    lv_obj_set_width(ui_Panel1_copy_copy_copy, 85);
    lv_obj_set_height(ui_Panel1_copy_copy_copy, 78);

    lv_obj_set_x(ui_Panel1_copy_copy_copy, -100);
    lv_obj_set_y(ui_Panel1_copy_copy_copy, -42);

    lv_obj_set_align(ui_Panel1_copy_copy_copy, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Panel1_copy_copy_copy, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_add_event_cb(ui_Panel1_copy_copy_copy, clicked_event, LV_EVENT_CLICKED, 0);
    lv_obj_add_event_cb(ui_Panel1_copy_copy, clicked_event, LV_EVENT_CLICKED, 0);
    lv_obj_add_event_cb(ui_Panel1_copy, clicked_event, LV_EVENT_CLICKED, 0);
    lv_obj_add_event_cb(ui_Panel1, clicked_event, LV_EVENT_CLICKED, 0);
    lv_obj_clear_flag(ui_Panel1_copy_copy_copy, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1_copy_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1_copy_copy_copy, lv_color_hex(0xEBF4F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1_copy_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Panel1_copy_copy_copy, lv_color_hex(0xB5C6E0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Panel1_copy_copy_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Panel1_copy_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Panel1_copy_copy_copy, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel1_copy_copy_copy, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel1_copy_copy_copy, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel1_copy_copy_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel1_copy_copy_copy, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel1_copy_copy_copy, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_Panel1_copy_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_Panel1_copy_copy_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image1

    ui_Image1 = lv_img_create(ui_Panel1_copy_copy_copy);
    lv_img_set_src(ui_Image1, &living);

    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, 0);

    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

    // Panel2

    ui_Panel2 = lv_obj_create(ui_scr_light);

    lv_obj_set_width(ui_Panel2, 118);
    lv_obj_set_height(ui_Panel2, 27);

    lv_obj_set_x(ui_Panel2, 24);
    lv_obj_set_y(ui_Panel2, 45);

    lv_obj_set_align(ui_Panel2, LV_ALIGN_TOP_RIGHT);

    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xAEABFC), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Label1

    ui_Label1 = lv_label_create(ui_scr_light);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, -5);
    lv_obj_set_y(ui_Label1, 170);

    lv_obj_set_align(ui_Label1, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Label1, "Kitchen");

    lv_obj_add_flag(ui_Label1, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(ui_Label1, ui_event_Label1, LV_EVENT_ALL, NULL);

    // Label2

    ui_Label2 = lv_label_create(ui_scr_light);

    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label2, -5);
    lv_obj_set_y(ui_Label2, 130);

    lv_obj_set_align(ui_Label2, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Label2, "Bathroom");

    lv_obj_add_flag(ui_Label2, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(ui_Label2, ui_event_Label2, LV_EVENT_ALL, NULL);

    // Label3

    ui_Label3 = lv_label_create(ui_scr_light);

    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label3, -5);
    lv_obj_set_y(ui_Label3, 90);

    lv_obj_set_align(ui_Label3, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Label3, "Bedroom");

    lv_obj_add_flag(ui_Label3, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(ui_Label3, ui_event_Label3, LV_EVENT_ALL, NULL);

    // Label4

    ui_Label4 = lv_label_create(ui_scr_light);

    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label4, -5);
    lv_obj_set_y(ui_Label4, 50);

    lv_obj_set_align(ui_Label4, LV_ALIGN_TOP_RIGHT);

    lv_label_set_text(ui_Label4, "Livingroom");

    lv_obj_add_flag(ui_Label4, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(ui_Label4, ui_event_Label4, LV_EVENT_ALL, NULL);

    // Label5

    ui_Label5 = lv_label_create(ui_scr_light);

    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label5, 0);
    lv_obj_set_y(ui_Label5, 5);

    lv_obj_set_align(ui_Label5, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_Label5, "Light Control");

}

void ui_init_light(void)
{
    lv_scr_load_anim(ui_scr_light, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
    cur_scr = Src_light;
}


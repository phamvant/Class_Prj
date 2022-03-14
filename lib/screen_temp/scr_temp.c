// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.2
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "scr_temp.h"
#include "ui_share.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen_temp;
static lv_obj_t * ui_Panel2;
static lv_obj_t * ui_Arc1;
static lv_obj_t * ui_Panel1;
static lv_obj_t * ui_Label2;
static lv_obj_t * ui_Slider1;
static lv_obj_t * ui_Label1;
static lv_obj_t * ui_Image2;
static lv_obj_t * ui_Panel3;
static lv_obj_t * ui_Image4;
static lv_obj_t * ui_Label3;
static lv_obj_t * ui_Panel3_copy;
static lv_obj_t * ui_Image1;
static lv_obj_t * ui_Label4;
static lv_obj_t * title;

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

static void event_clicked(lv_event_t* e)
{
    if (!lv_obj_has_state(ui_Panel3, LV_STATE_CHECKED)) {
        lv_obj_set_style_shadow_color(ui_Panel3, lv_color_hex(0x3bcbff), 0);
        lv_label_set_text(ui_Label3, "On");
    }
    else {
        lv_obj_set_style_shadow_color(ui_Panel3, lv_color_hex(0x6E6E6E), 0);
        lv_label_set_text(ui_Label3, "Off");
    }
}

static void event_clicked2(lv_event_t* e)
{
    if (!lv_obj_has_state(ui_Panel3_copy, LV_STATE_CHECKED)) {
        lv_obj_set_style_shadow_color(ui_Panel3_copy, lv_color_hex(0x3bcbff), 0);
        lv_label_set_text(ui_Label4, "On");
    }
    else {
        lv_obj_set_style_shadow_color(ui_Panel3_copy, lv_color_hex(0x6E6E6E), 0);
        lv_label_set_text(ui_Label4, "Off");
    }
}

static void ui_event_Arc1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_Label2, ta, "", "");
    }
}
static void ui_event_Slider1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(event == LV_EVENT_VALUE_CHANGED) {
        _ui_slider_set_text_value(ui_Label1, ta, "", "");
    }
}
static void ui_event_Image1(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    if(event == LV_EVENT_CLICKED) {
        _ui_opacity_set(ui_Screen_temp, 100);
    }
}

///////////////////// SCREENS ////////////////////
void ui_scr_temp_init(void)
{

    // Screen1

    ui_Screen_temp = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen_temp, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_Screen_temp, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui_Screen_temp, ui_event_scr_by_click, LV_EVENT_LONG_PRESSED, (void*)Screen2);

    title = lv_label_create(ui_Screen_temp);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 5);
    lv_label_set_text(title, "AC Config");

    // Panel2


    ui_Panel2 = lv_obj_create(ui_Screen_temp);

    lv_obj_set_width(ui_Panel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Panel2, LV_SIZE_CONTENT);
    lv_obj_align(ui_Panel2, LV_ALIGN_CENTER, 5, -20);

    //lv_obj_set_x(ui_Panel2, 0);
    //lv_obj_set_y(ui_Panel2, -21);

    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel2, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel2, lv_color_hex(0xAAAAAA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel2, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Arc1

    ui_Arc1 = lv_arc_create(ui_Panel2);

    lv_obj_set_width(ui_Arc1, 120);
    lv_obj_set_height(ui_Arc1, 120);

    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, 0);

    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);

    lv_arc_set_range(ui_Arc1, 0, 100);
    lv_arc_set_value(ui_Arc1, 50);
    lv_arc_set_bg_angles(ui_Arc1, 120, 60);

    lv_obj_add_event_cb(ui_Arc1, ui_event_Arc1, LV_EVENT_ALL, NULL);

    lv_obj_set_style_arc_width(ui_Arc1, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_img_src(ui_Arc1, &ui_img_1728828587, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x4040FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Arc1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Arc1, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Panel1

    ui_Panel1 = lv_obj_create(ui_Arc1);

    lv_obj_set_width(ui_Panel1, 70);
    lv_obj_set_height(ui_Panel1, 70);

    lv_obj_set_x(ui_Panel1, 1);
    lv_obj_set_y(ui_Panel1, -1);

    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_Panel1, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel1, lv_color_hex(0xA2A2A2), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel1, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Label2

    ui_Label2 = lv_label_create(ui_Panel1);

    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label2, 0);
    lv_obj_set_y(ui_Label2, 0);

    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label2, "50'C");

    // Slider1

    ui_Slider1 = lv_slider_create(ui_Screen_temp);
    lv_slider_set_range(ui_Slider1, 0, 100);
    lv_slider_set_value(ui_Slider1, 50, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider1, 0, LV_ANIM_OFF);

    lv_obj_set_width(ui_Slider1, 150);
    lv_obj_set_height(ui_Slider1, 4);

    lv_obj_set_x(ui_Slider1, 4);
    lv_obj_set_y(ui_Slider1, 84);

    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);

    lv_obj_add_event_cb(ui_Slider1, ui_event_Slider1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0x464646), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 120, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0x655EB0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Slider1, lv_color_hex(0xE4E4E7), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Slider1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Slider1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Slider1, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Slider1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Slider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Slider1, lv_color_hex(0xB0B0B0), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Slider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Slider1, lv_color_hex(0x9E9E9E), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Slider1, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Slider1, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Slider1, 1, LV_PART_KNOB | LV_STATE_DEFAULT);

    // Label1

    ui_Label1 = lv_label_create(ui_Screen_temp);

    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label1, 98);
    lv_obj_set_y(ui_Label1, 82);

    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);

    lv_label_set_text(ui_Label1, "50");

    // Image2

    ui_Image2 = lv_img_create(ui_Screen_temp);
    lv_img_set_src(ui_Image2, &ui_img_1338695112);

    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image2, -94);
    lv_obj_set_y(ui_Image2, 84);

    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);

    // Panel3

    ui_Panel3 = lv_obj_create(ui_Screen_temp);

    lv_obj_set_width(ui_Panel3, 49);
    lv_obj_set_height(ui_Panel3, 96);
    
    lv_obj_set_x(ui_Panel3, -112);
    lv_obj_set_y(ui_Panel3, -19);

    lv_obj_set_align(ui_Panel3, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_Panel3, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui_Panel3, event_clicked, LV_EVENT_CLICKED, 0);
    lv_obj_add_flag(ui_Panel3, LV_OBJ_FLAG_PRESS_LOCK);
    lv_obj_add_flag(ui_Panel3, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0xF5F5F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel3, lv_color_hex(0x6E6E6E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel3, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image4

    ui_Image4 = lv_img_create(ui_Panel3);
    lv_img_set_src(ui_Image4, &ui_img_1775583536);

    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image4, 0);
    lv_obj_set_y(ui_Image4, 10);

    lv_obj_set_align(ui_Image4, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_img_recolor(ui_Image4, lv_color_hex(0x6E6E6E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Label3

    ui_Label3 = lv_label_create(ui_Panel3);

    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label3, 0);
    lv_obj_set_y(ui_Label3, -10);

    lv_obj_set_align(ui_Label3, LV_ALIGN_BOTTOM_MID);

    lv_label_set_text(ui_Label3, "Off");

    // Panel3_copy

    ui_Panel3_copy = lv_obj_create(ui_Screen_temp);

    lv_obj_set_width(ui_Panel3_copy, 49);
    lv_obj_set_height(ui_Panel3_copy, 96);

    lv_obj_set_x(ui_Panel3_copy, 117);
    lv_obj_set_y(ui_Panel3_copy, -20);

    lv_obj_set_align(ui_Panel3_copy, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel3_copy, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(ui_Panel3_copy, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui_Panel3_copy, event_clicked2, LV_EVENT_CLICKED, 0);
    lv_obj_add_flag(ui_Panel3_copy, LV_OBJ_FLAG_PRESS_LOCK);
    lv_obj_add_flag(ui_Panel3_copy, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_set_style_bg_color(ui_Panel3_copy, lv_color_hex(0xF5F5F5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel3_copy, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Panel3_copy, lv_color_hex(0x6E6E6E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Panel3_copy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Panel3_copy, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Panel3_copy, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Panel3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Panel3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Panel3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Panel3_copy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Image1

    ui_Image1 = lv_img_create(ui_Panel3_copy);
    lv_img_set_src(ui_Image1, &ui_img_1869696579);

    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, 10);

    lv_obj_set_align(ui_Image1, LV_ALIGN_TOP_MID);

    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_Image1, ui_event_Image1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_img_recolor(ui_Image1, lv_color_hex(0x242424), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Label4

    ui_Label4 = lv_label_create(ui_Panel3_copy);

    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Label4, 0);
    lv_obj_set_y(ui_Label4, -10);

    lv_obj_set_align(ui_Label4, LV_ALIGN_BOTTOM_MID);

    lv_label_set_text(ui_Label4, "Off");

}

void ui_init_temp(void)
{
    lv_scr_load_anim(ui_Screen_temp, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0, false);
    cur_scr = Scr_temp;
}


#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // name
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.name = obj;
            lv_obj_set_pos(obj, 179, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "B6711931 Kittikun P.");
        }
        {
            // adc33label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33label = obj;
            lv_obj_set_pos(obj, 18, 29);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "ADC33");
        }
        {
            // adc34label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc34label = obj;
            lv_obj_set_pos(obj, 17, 61);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "ADC34");
        }
        {
            // adc33bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc33bar = obj;
            lv_obj_set_pos(obj, 85, 32);
            lv_obj_set_size(obj, 192, 10);
            lv_bar_set_range(obj, 0, 1023);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // adc34bar
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.adc34bar = obj;
            lv_obj_set_pos(obj, 86, 64);
            lv_obj_set_size(obj, 192, 10);
            lv_bar_set_range(obj, 0, 1023);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // adc33val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33val = obj;
            lv_obj_set_pos(obj, 279, 29);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "0");
        }
        {
            // adc34val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc34val = obj;
            lv_obj_set_pos(obj, 279, 61);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "0");
        }
        {
            // adc33led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.adc33led = obj;
            lv_obj_set_pos(obj, 261, 134);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0x0000ff));
            lv_led_set_brightness(obj, 0);
        }
        {
            // adc33_label
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.adc33_label = obj;
            lv_obj_set_pos(obj, 255, 104);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "ADC33");
        }
        {
            // adc_chart
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.adc_chart = obj;
            lv_obj_set_pos(obj, 17, 84);
            lv_obj_set_size(obj, 208, 147);
        }
        {
            // nextpage_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.nextpage_bt = obj;
            lv_obj_set_pos(obj, 233, 213);
            lv_obj_set_size(obj, 87, 27);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 1, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Next Page");
                }
            }
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_control_page() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.control_page = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 9);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "PWM Control");
        }
        {
            // pwmval
            lv_obj_t *obj = lv_spinbox_create(parent_obj);
            objects.pwmval = obj;
            lv_obj_set_pos(obj, 47, 35);
            lv_obj_set_size(obj, 53, 34);
            lv_spinbox_set_digit_format(obj, 3, 0);
            lv_spinbox_set_range(obj, 0, 255);
            lv_spinbox_set_rollover(obj, false);
            lv_spinbox_set_step(obj, 1);
            lv_spinbox_set_value(obj, 0);
        }
        {
            // incrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.incrementpwm = obj;
            lv_obj_set_pos(obj, 108, 37);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x15cc56), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x054c1e), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "+");
                }
            }
        }
        {
            // decrementpwm
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.decrementpwm = obj;
            lv_obj_set_pos(obj, 9, 37);
            lv_obj_set_size(obj, 30, 30);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xf83434), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x4c0505), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "-");
                }
            }
        }
        {
            // onpwm_sw
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.onpwm_sw = obj;
            lv_obj_set_pos(obj, 209, 40);
            lv_obj_set_size(obj, 50, 25);
        }
        {
            // off
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.off = obj;
            lv_obj_set_pos(obj, 160, 45);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "OFF");
        }
        {
            // on
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.on = obj;
            lv_obj_set_pos(obj, 275, 45);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "ON");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 11, 81);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "Pump Control");
        }
        {
            // fan_led
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.fan_led = obj;
            lv_obj_set_pos(obj, 218, 146);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0x0000ff));
            lv_led_set_brightness(obj, 0);
        }
        {
            // off_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.off_1 = obj;
            lv_obj_set_pos(obj, 220, 112);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text_static(obj, "FAN");
        }
        {
            // onmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.onmotor_bt = obj;
            lv_obj_set_pos(obj, 11, 103);
            lv_obj_set_size(obj, 100, 33);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x049c1c), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x012907), LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Open Motor");
                }
            }
        }
        {
            // offmotor_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.offmotor_bt = obj;
            lv_obj_set_pos(obj, 12, 147);
            lv_obj_set_size(obj, 100, 33);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2196f3), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xd66f0a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Closed Motor");
                }
            }
        }
        {
            // home_bt
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.home_bt = obj;
            lv_obj_set_pos(obj, 9, 204);
            lv_obj_set_size(obj, 52, 27);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 1, 1);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "Home");
                }
            }
        }
    }
    
    tick_screen_control_page();
}

void tick_screen_control_page() {
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_control_page,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 2) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_main();
    create_screen_control_page();
}
#include "event.h"
#include <Arduino.h>

lv_chart_series_t *data1;
lv_chart_series_t *data2;

void plotchart (){
  int pointcount = 50;
  int min_value = 0;
  int max_value = 1023;
  // Set type of the chart
  lv_chart_set_type(objects.adc_chart, LV_CHART_TYPE_LINE);
  // Set the number of points on the chart
  lv_chart_set_point_count(objects.adc_chart, pointcount);
  // Set the range of the Y axis
  lv_chart_set_range(objects.adc_chart, LV_CHART_AXIS_PRIMARY_Y, min_value, max_value);
  // Create a data series for the chart
  data1 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0x276CF5), LV_CHART_AXIS_PRIMARY_Y);
  data2 = lv_chart_add_series(objects.adc_chart, lv_color_hex(0xF57D27), LV_CHART_AXIS_PRIMARY_Y);
}

void updatechart_adc(lv_timer_t * timer){
    int value1 = analogRead(33);
    int value2 = analogRead(34);
    float bri =  (value1/1023.0)*255.0;

    LV_UNUSED(timer);
    lv_chart_set_next_value(objects.adc_chart , data1 , value1);
    lv_chart_set_next_value(objects.adc_chart , data2 , value2);

    lv_led_set_brightness(objects.adc33led,bri);
    lv_bar_set_value(objects.adc33bar,value1,LV_ANIM_ON);
    lv_bar_set_value(objects.adc34bar,value2,LV_ANIM_ON);
    lv_label_set_text(objects.adc33val , String(value1).c_str());
    lv_label_set_text(objects.adc34val , String(value2).c_str());
}

void event_handler (lv_event_t *e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);
    int *pLED1 = (int*)lv_event_get_user_data(e);
    int *pLED2 = (int*)lv_event_get_user_data(e);

    if(obj ==  objects.nextpage_bt){
        lv_scr_load(objects.control_page);
    }else if (obj ==  objects.home_bt){
        lv_scr_load(objects.main);
    }else if (obj ==  objects.onmotor_bt){
        digitalWrite(*pLED1,1);
    }else if (obj ==  objects.offmotor_bt){
        digitalWrite(*pLED1,0);
    }else if (obj ==  objects.incrementpwm){
        lv_spinbox_increment(objects.pwmval);
    }else if (obj ==  objects.decrementpwm){
        lv_spinbox_decrement(objects.pwmval);
    }else if (obj == objects.onpwm_sw){
        if(lv_obj_has_state(objects.onpwm_sw , LV_STATE_CHECKED)){
            int getspin = lv_spinbox_get_value(objects.pwmval);
            Serial.println("PWMVAL: "+String(getspin));
            int pwm =  (getspin/1023.0)*255.0;
            analogWrite(*pLED2,pwm);
        }else{
            analogWrite(*pLED2,0);
        }
    }
}

void readsw (lv_timer_t * timer){
    int *pSW1 = (int*)timer->user_data;
    int state = digitalRead(*pSW1);
    if(state == 0){
        lv_led_on(objects.fan_led);
    }else if (state == 1){
        lv_led_off(objects.fan_led);
    }
}
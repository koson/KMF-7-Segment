/*
 * SevenSegment.h
 *
 *  Created on: 29 เธก.เธ�. 2566
 *      Author: koson
 */

#ifndef MAIN_SEVEN_SEGMENT_H_
#define MAIN_SEVEN_SEGMENT_H_
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

class seven_segment
{
	gpio_num_t segment_gpio_pins[8];
	gpio_num_t common_gpio;
    uint8_t segment_value;
public:
    seven_segment();
	seven_segment(gpio_num_t seg_a, gpio_num_t seg_b, gpio_num_t seg_ca,
			gpio_num_t seg_da, gpio_num_t seg_ea, gpio_num_t seg_fa,
			gpio_num_t seg_ga, gpio_num_t seg_dp, gpio_num_t common
			);
    void initial();
    void enable(bool Status);
    void set_value(uint8_t val);
    uint8_t get_value();
};


#endif /* MAIN_SEVEN_SEGMENT_H_ */

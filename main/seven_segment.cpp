/*
 * seven_segment.cpp
 *
 *  Created on: 29 เธก.เธ�. 2566
 *      Author: koson
 */

#include "seven_segment.h"

//    aaaaa
//   f     b
//   f     b
//   f     b
//    ggggg
//	 e     c
//	 e     c
//	 e     c
//	 ddddd	 dp

const uint8_t ss_value[][7] =
{
	{ 1, 1, 1, 1, 1, 1, 0 },		// 0
	{ 0, 1, 1, 0, 0, 0, 0 },		// 1
	{ 1, 1, 0, 1, 1, 0, 1 },		// 2
	{ 1, 1, 1, 1, 0, 0, 1 },		// 3
	{ 0, 1, 1, 0, 0, 1, 1 },		// 4
	{ 1, 0, 1, 1, 0, 1, 1 },		// 5
	{ 1, 0, 1, 1, 1, 1, 1 },		// 6
	{ 1, 1, 1, 0, 0, 0, 0 },		// 7
	{ 1, 1, 1, 1, 1, 1, 1 },		// 8
	{ 1, 1, 1, 1, 0, 1, 1 },		// 9
};


seven_segment::seven_segment()
{
	segment_value = 0;
	common_gpio = GPIO_NUM_NC;
//
//	set_digit(0);

}

seven_segment::seven_segment(gpio_num_t seg_a, gpio_num_t seg_b,
		gpio_num_t seg_c, gpio_num_t seg_d, gpio_num_t seg_e,
		gpio_num_t seg_f, gpio_num_t seg_g, gpio_num_t seg_dp,
		gpio_num_t common)
{
	segment_gpio_pins[0] = seg_a;
	segment_gpio_pins[1] = seg_b;
	segment_gpio_pins[2] = seg_c;
	segment_gpio_pins[3] = seg_d;
	segment_gpio_pins[4] = seg_e;
	segment_gpio_pins[5] = seg_f;
	segment_gpio_pins[6] = seg_g;
	segment_gpio_pins[7] = seg_dp;
	common_gpio = common;
	segment_value = 0;
	initial();
}

void seven_segment::initial()
{
	for (int i = 0; i < 8; i++) {
		gpio_reset_pin(segment_gpio_pins[i]);
		gpio_set_direction(segment_gpio_pins[i], GPIO_MODE_OUTPUT);
	}
	gpio_reset_pin(common_gpio);
	gpio_set_direction(common_gpio, GPIO_MODE_OUTPUT);
}

void seven_segment::enable(bool Status)
{
	gpio_set_level(common_gpio, Status);
}

void seven_segment::set_value(uint8_t val)
{
	gpio_set_level(segment_gpio_pins[0], ss_value[val][0]);
	gpio_set_level(segment_gpio_pins[1], ss_value[val][1]);
	gpio_set_level(segment_gpio_pins[2], ss_value[val][2]);
	gpio_set_level(segment_gpio_pins[3], ss_value[val][3]);
	gpio_set_level(segment_gpio_pins[4], ss_value[val][4]);
	gpio_set_level(segment_gpio_pins[5], ss_value[val][5]);
	gpio_set_level(segment_gpio_pins[6], ss_value[val][6]);
}

uint8_t seven_segment::get_value()
{
	return segment_value;
}

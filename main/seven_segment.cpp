/*
 * seven_segment.cpp
 *
 *  Created on: 29 ม.ค. 2566
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
//	  ddddd	 dp

const uint8_t ss_value[][7] =
{
		{1,1,1,1,1,1,0},		// 0
		{0,1,1,0,0,0,0},		// 1
		{1,1,0,1,1,0,1},		// 2
		{1,1,1,1,0,0,1},		// 3
		{0,1,1,0,0,1,1},		// 4
		{1,0,1,1,0,1,1},		// 5
		{1,0,1,1,1,1,1},		// 6
		{1,1,1,0,0,0,0},		// 7
		{1,1,1,1,1,1,0},		// 8
		{1,1,1,1,0,1,0},		// 9
};


seven_segment::seven_segment()
{
	segment_value = 0;
	digit_gpio = GPIO_NUM_NC;
	initial();
	set_digit(0);

}

void seven_segment::initial()
{
	for (int i = 0; i < 8; i++) {
		gpio_reset_pin(segment_gpio_pins[i]);
		gpio_set_direction(segment_gpio_pins[i], GPIO_MODE_OUTPUT);
	}
}

void seven_segment::enable(bool Status)
{

}

void seven_segment::set_digit(uint8_t val)
{

}

uint8_t seven_segment::get_value()
{
	return segment_value;
}

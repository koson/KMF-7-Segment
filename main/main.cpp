#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#include "seven_segment.h"

#define SEG_A 	GPIO_NUM_23
#define SEG_B 	GPIO_NUM_22
#define SEG_C 	GPIO_NUM_1
#define SEG_D 	GPIO_NUM_3
#define SEG_E 	GPIO_NUM_21
#define SEG_F 	GPIO_NUM_19
#define SEG_G 	GPIO_NUM_18
#define SEG_DP 	GPIO_NUM_5
#define DIG_1	GPIO_NUM_17
#define DIG_2	GPIO_NUM_16


extern "C"
{
    void app_main(void);
}

seven_segment ss1(SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP, DIG_1);
seven_segment ss2(SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP, DIG_2);

void Display7Segment(int i)
{
	ss1.set_value(i / 10);
	ss1.enable(1);
	usleep(10000);
	ss1.enable(0);
	ss2.set_value(i % 10);
	ss2.enable(1);
	usleep(10000);
	ss2.enable(0);
}

void app_main(void)
{
	int i = 0;
	uint32_t j = 0;
	while (true)
    {
		if(j++ > 40)
		{
			i++;
			j = 0;
		}
		if(i > 99) i = 0;

		Display7Segment(i);
    }
}

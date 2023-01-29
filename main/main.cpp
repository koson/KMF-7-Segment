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


void app_main(void)
{
	seven_segment ss1;
	seven_segment ss2;

    while (true)
    {
    	ss1.set_digit(1);
    	ss1.enable(true);
    	sleep(1);
    	ss1.enable(false);

    	ss2.set_digit(2);
    	ss2.enable(true);
    	sleep(1);
    	ss2.enable(false);
    }
}

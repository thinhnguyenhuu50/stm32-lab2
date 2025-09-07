/*
 * software_timer.c
 *
 *  Created on: Sep 7, 2025
 *      Author: Admin
 */

#include "software_timer.h"
#include "tim.h"

int timer0_counter = 0;
int timer0_original = 0;
int timer0_flag = 0;
int TIMER_CYCLE = 10; // 10 ms period

void setTimer0(int duration){
	timer0_original = duration / TIMER_CYCLE;
	timer0_counter = timer0_original;
	timer0_flag = 0;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if(timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter == 0) {
			timer0_flag = 1;
			timer0_counter = timer0_original;
		}
	}
}

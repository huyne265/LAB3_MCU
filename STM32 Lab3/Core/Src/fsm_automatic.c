/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2024
 *      Author: ADMIN
 */
#include "fsm_automatic.h"
#include "global.h"

void initState(){
	display7SEG(0);
	display7SEG2(0);
	writeEn(1);

	HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin|GREEN_LED2_Pin, 0);
	HAL_GPIO_WritePin(GPIOA, GREEN_LED1_Pin|YEL_LED1_Pin|RED_LED2_Pin|YEL_LED2_Pin, 1);
}

void checkTime(){
	int red_time = led_buffer[0]*10 + led_buffer[1] + 1;
	int green_time = led_buffer[2]*10 + led_buffer[3] + 1;
	int yel_time = led_buffer[4]*10 + led_buffer[5] + 1;
	int yel_green_time = yel_time + green_time;

	if(red_time != yel_green_time ){
		led_buffer[1] = (yel_green_time - 1)%10;
		led_buffer[0] = (yel_green_time - 1)/10;
	}
}

void fsm_automatic_run(){
	switch(status){
		case INIT:
			checkTime();
			status = RED_GREEN;
			HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin | YEL_LED1_Pin | GREEN_LED1_Pin | RED_LED2_Pin | YEL_LED2_Pin | GREEN_LED2_Pin, 1);
			setTimer(0, (led_buffer[3] + 1)*1000 + led_buffer[2]*10000);
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case RED_GREEN:
			HAL_GPIO_WritePin(GPIOA, YEL_LED1_Pin | RED_LED2_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin | GREEN_LED2_Pin, 0);
			if(timer_flag[0] && mode == 1){
				status = RED_YEL;
				setTimer(0, (led_buffer[5] + 1)*1000 + led_buffer[4]*10000);
			}
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case RED_YEL:
			HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, 1);
			HAL_GPIO_WritePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin, 0);
			if(timer_flag[0] && mode == 1){
				status = GREEN_RED;
				display7SEG(led_buffer[3]);
				setTimer(0, (led_buffer[3] + 1)*1000 + led_buffer[2]*10000);
			}
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case GREEN_RED:
			HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin | YEL_LED2_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, GREEN_LED1_Pin | RED_LED2_Pin, 0);
			if(timer_flag[0] && mode == 1){
				status = YEL_RED;
				display7SEG(led_buffer[5]);
				setTimer(0, (led_buffer[5] + 1)*1000 + led_buffer[4]*10000);
			}
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case YEL_RED:
			HAL_GPIO_WritePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin, 0);
			HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, 1);
			if(timer_flag[0]  && mode == 1){
				status = RED_GREEN;
				display7SEG(led_buffer[1]);
				setTimer(0, (led_buffer[3] + 1)*1000 + led_buffer[2]*10000);
			}
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case INIT_2:
			setTimer(0,0);
			setTimer(1, 50);
			status = RED_2;
			HAL_GPIO_WritePin(GPIOA, GREEN_LED1_Pin | YEL_LED1_Pin | GREEN_LED2_Pin | YEL_LED2_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin | RED_LED2_Pin, 0);
			break;
		case RED_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(RED_LED1_GPIO_Port, RED_LED1_Pin);
				HAL_GPIO_TogglePin(RED_LED2_GPIO_Port, RED_LED2_Pin);
				setTimer(1, 50);
			}
			if(isButtonPressed(0)){
				status = YEL_2;
				setTimer(1, 50);
				HAL_GPIO_WritePin(GPIOA, RED_LED1_Pin | RED_LED2_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, YEL_LED1_Pin | YEL_LED2_Pin, 0);
			}
			RunSegMode2();
			break;
		case YEL_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin);
				HAL_GPIO_TogglePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin);
				setTimer(1, 50);
			}
			if(isButtonPressed(0)){
				status = GREEN_2;
				setTimer(1, 50);
				HAL_GPIO_WritePin(GPIOA, YEL_LED1_Pin | YEL_LED2_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, GREEN_LED1_Pin | GREEN_LED2_Pin, 0);
			}
			RunSegMode3();
			break;
		case GREEN_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin);
				HAL_GPIO_TogglePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin);
				setTimer(1, 50);
			}
			if(isButtonPressed(0)){
				status = INIT;
				setTimer(1, 50);
				HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, 1);
				HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, 1);
			}
			RunSegMode4();
			break;
		default:
			break;
	}
}


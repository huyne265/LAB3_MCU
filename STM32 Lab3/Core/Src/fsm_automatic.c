/*
 * fsm_automatic.c
 *
 *  Created on: Oct 5, 2024
 *      Author: ADMIN
 */
#include "fsm_automatic.h"
#include "global.h"



void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = RED_GREEN;
			HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, 1);
			HAL_GPIO_WritePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin, 1);
			HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, 1);
			HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, 1);
			HAL_GPIO_WritePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin, 1);
			HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, 1);
			setTimer(0, (led_buffer[3] + 1)*1000 + led_buffer[2]*10000);
			if(isButtonPressed(0)){
				status = INIT_2;
			}
			RunSeg();
			break;
		case RED_GREEN:
			HAL_GPIO_WritePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin, 1);
			HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, 0);

			HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, 0);
			HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, 1);
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
			HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, 1);
			HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, 0);

			HAL_GPIO_WritePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin, 1);
			HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, 0);

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
			setTimer(1, 500);
			status = RED_2;
			HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port,GREEN_LED1_Pin, 1);
			HAL_GPIO_WritePin(YEL_LED1_GPIO_Port,YEL_LED1_Pin, 1);
			HAL_GPIO_WritePin(RED_LED1_GPIO_Port,RED_LED1_Pin, 0);
			HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port,GREEN_LED2_Pin, 1);
			HAL_GPIO_WritePin(YEL_LED2_GPIO_Port,YEL_LED2_Pin, 1);
			HAL_GPIO_WritePin(RED_LED2_GPIO_Port,RED_LED2_Pin, 0);
			break;
		case RED_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(RED_LED1_GPIO_Port, RED_LED1_Pin);
				HAL_GPIO_TogglePin(RED_LED2_GPIO_Port, RED_LED2_Pin);
				setTimer(1, 500);
			}
			if(isButtonPressed(0)){
				status = YEL_2;
				HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, 1);
				HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, 1);
			}
			RunSegMode2();
			break;
		case YEL_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin);
				HAL_GPIO_TogglePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin);
				setTimer(1, 500);
			}
			if(isButtonPressed(0)){
				status = GREEN_2;
				HAL_GPIO_WritePin(YEL_LED1_GPIO_Port, YEL_LED1_Pin, 1);
				HAL_GPIO_WritePin(YEL_LED2_GPIO_Port, YEL_LED2_Pin, 1);
			}
			RunSegMode3();
			break;
		case GREEN_2:
			if(timer_flag[1]){
				HAL_GPIO_TogglePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin);
				HAL_GPIO_TogglePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin);
				setTimer(1, 500);
			}
			if(isButtonPressed(0)){
				status = INIT;
				HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, 1);
				HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, 1);
			}
			RunSegMode4();
			break;
		default:
			break;
	}
}


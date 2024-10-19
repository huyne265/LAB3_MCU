/*
 * 7segment.c
 *
 *  Created on: Oct 5, 2024
 *      Author: ADMIN
 */
#include "7segment.h"
#include "main.h"
#include "global.h"


void clear7SEG(){
	  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, 1);
}
void clear7SEG2(){
	  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, 1);
}
void writeEn(int index){
	switch(index){
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN3_Pin, 0);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin|EN4_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin|EN4_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN3_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin|EN4_Pin, 1);
			break;
	}
}
void display7SEG(int num){
    	  switch(num){
    	  	  case 0:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin, 0);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, 1);
    	  		  break;
    	  	  case 1:
    	  		  HAL_GPIO_WritePin(GPIOB, b_Pin|c_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|d_Pin|e_Pin|f_Pin|g_Pin, 1);
    	  		  break;
    	  	  case 2:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|d_Pin|e_Pin|g_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, c_Pin|f_Pin, 1);
    	  		  break;
    	  	  case 3:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin|g_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, e_Pin|f_Pin, 1);
    	  		  break;
    	  	  case 4:
    	  		  HAL_GPIO_WritePin(GPIOB, b_Pin|c_Pin|f_Pin|g_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|d_Pin|e_Pin, 1);
    	  		  break;
    	  	  case 5:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|c_Pin|d_Pin|f_Pin|g_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, b_Pin|e_Pin, 1);
    	  		  break;
    	  	  case 6:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, b_Pin, 1);
    	  		  break;
    	  	  case 7:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin, 0);
    	  		  HAL_GPIO_WritePin(GPIOB, d_Pin|e_Pin|f_Pin|g_Pin, 1);
    	  		  break;
    	  	  case 8:
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, 0);
    	  		  break;
    	  	  case 9:
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, 1);
    	  		  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin|f_Pin|g_Pin, 0);
    	  		  break;
    	  	  default:
    	  		  clear7SEG();
    	  		  break;
    	  	  }
}
void display7SEG2(int mode){
	switch(mode){
		case 0:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin, 0);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, 1);
			break;
		case 1:
	  		  HAL_GPIO_WritePin(GPIOB, b2_Pin|c2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, 1);
			break;
	  	  case 2:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|d2_Pin|e2_Pin|g2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, c2_Pin|f2_Pin, 1);
	  		  break;
	  	  case 3:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|g2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, e2_Pin|f2_Pin, 1);
	  		  break;
	  	  case 4:
	  		  HAL_GPIO_WritePin(GPIOB, b2_Pin|c2_Pin|f2_Pin|g2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|d2_Pin|e2_Pin, 1);
	  		  break;
	  	  case 5:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|c2_Pin|d2_Pin|f2_Pin|g2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, b2_Pin|e2_Pin, 1);
	  		  break;
	  	  case 6:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, b2_Pin, 1);
	  		  break;
	  	  case 7:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin, 0);
	  		  HAL_GPIO_WritePin(GPIOB, d2_Pin|e2_Pin|f2_Pin|g2_Pin, 1);
	  		  break;
	  	  case 8:
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|e2_Pin|f2_Pin|g2_Pin, 0);
	  		  break;
	  	  case 9:
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, 1);
	  		  HAL_GPIO_WritePin(GPIOB, a2_Pin|b2_Pin|c2_Pin|d2_Pin|f2_Pin|g2_Pin, 0);
	  		  break;
		default:
			break;
	}
}

void displayBuffer(int index){
	switch(index){
		case RED_GREEN:
			display7SEG2(temp[0]);
			display7SEG(temp[2]);
			break;
		case RED_YEL:
			display7SEG2(temp[0]);
			display7SEG(temp[4]);
			break;
		case GREEN_RED:
			display7SEG2(temp[2]);
			display7SEG(temp[0]);
			break;
		case YEL_RED:
			display7SEG2(temp[4]);
			display7SEG(temp[0]);
			break;
		default:
			break;
	}
}
void displayBuffer2(int index){
	switch(index){
		case RED_GREEN:
			display7SEG2(temp[1]--);
			display7SEG(temp[3]--);
			break;
		case RED_YEL:
			display7SEG2(temp[1]--);
			display7SEG(temp[5]--);
			break;
		case GREEN_RED:
			display7SEG2(temp[3]--);
			display7SEG(temp[1]--);
			break;
		case YEL_RED:
			display7SEG2(temp[5]--);
			display7SEG(temp[1]--);
			break;
		default:
			break;
		}
}
void RunSeg(){
	if(temp[1] < 0 && temp[0] >= 1){
		temp[1] = 9;
		temp[0]--;
	}else if(temp[1] < 0) {
		temp[1] = led_buffer[1];
		temp[0] = led_buffer[0];
	}

	if(temp[3] < 0 && temp[2] >= 1){
		temp[3] = 9;
		temp[2]--;
	}else if(temp[3] < 0) {
		temp[3] = led_buffer[3];
		temp[2] = led_buffer[2];
	}

	if(temp[5] < 0 && temp[4] >= 1){
		temp[5] = 9;
		temp[4]--;
	}else if(temp[5] < 0) {
		temp[5] = led_buffer[5];
		temp[4] = led_buffer[4];
	}

	if(timer_flag[2]){
		setTimer(2,1000);
		writeEn(1);
		displayBuffer(status);
	}
	else if(timer_flag[3]){
		setTimer(3,1000);
		writeEn(2);
		displayBuffer2(status);
	}
}

void RunSegMode2(){
	if(isButtonPressed(1)){
		temp[1]++;
		if(temp[1] == 10 && temp[0] == 9) {
			temp[0] = 0;
			temp[1] = 0;
		}
		if(temp[1] > 9 ){
			temp[1] = 0;
			temp[0]++;
		}
	}
	else if(isButtonPressed(2)){
		led_buffer[0] = temp[0] ;
		led_buffer[1] = temp[1];
	}
	if(timer_flag[2]){
		setTimer(2,100);
		writeEn(1);
		display7SEG2(0);
		display7SEG(temp[0]);
	}
	else if(timer_flag[3]){
		setTimer(3,100);
		writeEn(2);
		display7SEG2(2);
		display7SEG( temp[1] );
	}
}
void RunSegMode3(){
	if(isButtonPressed(1)){
		temp[5]++;
		if(temp[5] == 10 && temp[4] == 9){
			temp[5] = 0;
			temp[4] = 0;
		}
		if(temp[5] > 9){
			temp[5] = 0;
			temp[4]++;
		}
	}
	else if(isButtonPressed(2)){
		led_buffer[5] = temp[5];
		led_buffer[4] = temp[4];
	}
	if(timer_flag[2]){
		setTimer(2,100);
		writeEn(1);
		display7SEG2(0);
		display7SEG(temp[4]);
	}
	else if(timer_flag[3]){
		setTimer(3,100);
		writeEn(2);
		display7SEG2(3);
		display7SEG(temp[5]);
	}
}
void RunSegMode4(){
	if(isButtonPressed(1)){
		temp[3]++;
		if(temp[3] == 10 && temp[2] == 9){
			temp[3] = 0;
			temp[2] = 0;
		}
		if(temp[3] > 9){
			temp[3] = 0;
			temp[2]++;
		}
	}
	else if(isButtonPressed(2)){
		led_buffer[3] = temp[3];
		led_buffer[2] = temp[2];
	}
	if(timer_flag[2]){
		setTimer(2,100);
		writeEn(1);
		display7SEG2(0);
		display7SEG(temp[2]);
	}
	else if(timer_flag[3]){
		setTimer(3,100);
		writeEn(2);
		display7SEG2(4);
		display7SEG(temp[3]);
	}
}


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
	  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
}
void writeEn(int index){
	switch(index){
		case 1:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
			break;
		case 2:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 0);
			break;
		default:
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
			HAL_GPIO_WritePin(EN4_GPIO_Port, EN4_Pin, 1);
			break;
	}
}
void display7SEG(int num){
    	  switch(num){
    	  	  case 0:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    	  		  break;
    	  	  case 1:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    	  		  break;
    	  	  case 2:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 3:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 4:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 5:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 6:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 7:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
    	  		  break;
    	  	  case 8:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  case 9:
    	  		  HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
    	  		  HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
    	  		  HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
    	  		  break;
    	  	  default:
    	  		  clear7SEG();
    	  		  break;
    	  	  }
}

void displayMode(int mode){
	switch(mode){
		case 0:
			  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
			  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 1:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 2:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 3:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 4:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 5:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 6:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 7:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
			break;
		case 8:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		case 9:
	  		  HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, GPIO_PIN_SET);
	  		  HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, GPIO_PIN_RESET);
	  		  HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void updateBuffer(){
	if(timer_flag[4]){
		setTimer(4, 1000);
		switch(status){
			case RED_GREEN:
				temp[1]--;
				temp[3]--;
//				if(temp[1] < 0 && temp[0] >= 1){
//					temp[1] = 9;
//					temp[0]--;
//				}
//				if(temp[3] < 0 && temp[2] >= 1){
//					temp[3] = 9;
//					temp[2]--;
//				}
				break;
			case RED_YEL:
				temp[1]--;
				temp[5]--;
//				if(temp[1] < 0 && temp[0] >= 1){
//					temp[1] = 9;
//					temp[0]--;
//				}
//				if(temp[5] < 0 && temp[4] >= 1){
//					temp[5] = 9;
//					temp[4]--;
//				}
				break;
			case GREEN_RED:
				temp[3]--;
				temp[1]--;
//				if(temp[1] < 0 && temp[0] >= 1){
//					temp[1] = 9;
//					temp[0]--;
//				}
//				if(temp[3] < 0 && temp[2] >= 1){
//					temp[3] = 9;
//					temp[2]--;
//				}
				break;
			case YEL_RED:
				temp[5]--;
				temp[1]--;
//				if(temp[5] < 0 && temp[4] >= 1){
//					temp[5] = 9;
//					temp[4]--;
//				}
//				if(temp[1] < 0 && temp[0] >= 1){
//					temp[1] = 9;
//					temp[0]--;
//				}
				break;
			default:
				break;
		}
	}
}


void displayBuffer2(int index){
	switch(index){
		case RED_GREEN:
			displayMode(temp[1]--);
			display7SEG(temp[3]--);
			break;
		case RED_YEL:
			displayMode(temp[1]--);
			display7SEG(temp[5]--);
			break;
		case GREEN_RED:
			displayMode(temp[3]--);
			display7SEG(temp[1]--);
			break;
		case YEL_RED:
			displayMode(temp[5]--);
			display7SEG(temp[1]--);
			break;
		default:
			break;
		}
}
void displayBuffer(int index){
	switch(index){
		case RED_GREEN:
			displayMode(temp[0]);
			display7SEG(temp[2]);
			break;
		case RED_YEL:
			displayMode(temp[0]);
			display7SEG(temp[4]);
			break;
		case GREEN_RED:
			displayMode(temp[2]);
			display7SEG(temp[0]);
			break;
		case YEL_RED:
			displayMode(temp[4]);
			display7SEG(temp[0]);
			break;
		default:
			break;
	}
}

// int temp[6] = {0,4,0,2,0,1};
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
//	updateBuffer();
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
		setTimer(2,1000);
		writeEn(1);
		displayMode(0);
		display7SEG(temp[0]);
	}
	else if(timer_flag[3]){
		setTimer(3,1000);
		writeEn(2);
		displayMode(2);
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
		setTimer(2,1000);
		writeEn(1);
		displayMode(0);
		display7SEG(temp[4]);
	}
	else if(timer_flag[3]){
		setTimer(3,1000);
		writeEn(2);
		displayMode(3);
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
		setTimer(2,1000);
		writeEn(1);
		displayMode(0);
		display7SEG(temp[2]);
	}
	else if(timer_flag[3]){
		setTimer(3,1000);
		writeEn(2);
		displayMode(4);
		display7SEG(temp[3]);
	}
}


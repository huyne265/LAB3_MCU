/*
 * button.c
 *
 *  Created on: Sep 29, 2024
 *      Author: ADMIN
 */
#include "button.h"
#include "main.h"
#include "global.h"

#define NUM_BUTTON 3

int KeyReg0[NUM_BUTTON];
int KeyReg1[NUM_BUTTON];
int KeyReg2[NUM_BUTTON];
int KeyReg3[NUM_BUTTON];

int TimeOutForKeyPress[NUM_BUTTON];
int button_pressed[NUM_BUTTON];
int button_long_pressed[NUM_BUTTON];
int button_flag[NUM_BUTTON];

void setButton(int i){
		 KeyReg0[i] = NORMAL_STATE;
		 KeyReg1[i] = NORMAL_STATE;
		 KeyReg2[i] = NORMAL_STATE;
		 KeyReg3[i] = NORMAL_STATE;

		 TimeOutForKeyPress[i] =  500;
		 button_pressed[i] = 0;
		 button_long_pressed[i] = 0;
		 button_flag[i] = 0;
}


GPIO_TypeDef* button_ports[] = {Button1_GPIO_Port,Button2_GPIO_Port,Button3_GPIO_Port};
uint16_t button_pins[] = {Button1_Pin, Button2_Pin, Button3_Pin};

int isButtonPressed( int index ){
	if(button_flag[index] == 1){
		if(index == 0) {
			mode++;
			setTimer(2, 50); // for 7SEG
			setTimer(3, 100); //for 7SEG

			for(int i = 0 ; i < 6; i++) temp[i] = led_buffer[i];
		}
		if(mode > 4) {
			status = INIT;
			mode = 1;
			setTimer(2, 10); // for 7SEG
			setTimer(3, 510); //for 7SEG
		}
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButton1LongPressed(int index){
	if(button_long_pressed[index] == 1){
		button_long_pressed[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button_flag[index] = 1;
}

void getKeyInput(){
	for(int i = 0; i < NUM_BUTTON; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];

  // Add your key
	  KeyReg0[i] = HAL_GPIO_ReadPin(button_ports[i], button_pins[i]);

	  if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
		if (KeyReg2[i] != KeyReg3[i]){
		  KeyReg3[i] = KeyReg2[i];

		  if (KeyReg3[i] == PRESSED_STATE){
			TimeOutForKeyPress[i] = 500;
			//subKeyProcess();
			button_flag[i] = 1;
		  }

		}else{
			TimeOutForKeyPress[i] --;
			if (TimeOutForKeyPress[i] == 0){
				TimeOutForKeyPress[i] = 500;
				if (KeyReg3[i] == PRESSED_STATE){
					//subKeyProcess();
					button_flag[i] = 1;
				}
			}
		}
	  }
	}
}





/*
 * button.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonPressed(int index);
int isButtonLongPressed(int index);
void getKeyInput();
void subKeyProcess();

#endif /* INC_BUTTON_H_ */

/*
 * global.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "software_timer.h"
#include "7segment.h"
#include "fsm_automatic.h"

#define INIT 1
#define RED_GREEN 2
#define RED_YEL 5
#define YEL_RED 3
#define GREEN_RED 4

#define RED_GREEN_2 24
#define RED_YEL_2 25
#define YEL_RED_2 23
#define GREEN_RED_2 22


#define INIT_2 11
#define RED_2 12
#define YEL_2 13
#define GREEN_2 14


extern int status;
extern int counter;
extern int mode;
extern int led_buffer[6];
extern int temp[6];

#endif /* INC_GLOBAL_H_ */

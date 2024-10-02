/*
 * software_timer.h
 *
 *  Created on: Sep 29, 2024
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[];
extern int timer_counter[];

void setTimer(int index, int duration);
int isTimerExpired(int index);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

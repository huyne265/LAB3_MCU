/*
 * 7segment.h
 *
 *  Created on: Oct 5, 2024
 *      Author: ADMIN
 */

#ifndef INC_7SEGMENT_H_
#define INC_7SEGMENT_H_

void clear7SEG();
void clear7SEG2();
void display7SEG(int num);
void writeEn(int index);
void updateBuffer();
void displayBuffer(int index);
void displayBuffer2(int index);
void display7SEG2(int mode);

void RunSeg();
void RunSegMode2();
void RunSegMode3();
void RunSegMode4();

#endif /* INC_7SEGMENT_H_ */

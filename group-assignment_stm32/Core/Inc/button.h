/*
 * input_reading.h
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "software_timer.h"

#define NO_OF_BUTTONS 3
#define NORMAL_STATE SET
#define PRESSED_STATE RESET

int button_flag[NO_OF_BUTTONS];

void initSomeVariables();
void getKeyInput();
int isButtonPressed(int index);
//-----------------
void isB2Nor();
extern int ac_flagB2;
extern int KeyRegB20 ;
extern int KeyRegB21 ;
extern int KeyRegB22 ;
extern int KeyRegB23 ;
#endif /* INC_BUTTON_H_ */

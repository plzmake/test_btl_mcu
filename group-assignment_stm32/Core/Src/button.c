/*
 * input_reading.c
 *
 *  Created on: Nov 4, 2022
 *      Author: tamqu
 */

#include "button.h"

int KeyReg0[NO_OF_BUTTONS];
int KeyReg1[NO_OF_BUTTONS];
int KeyReg2[NO_OF_BUTTONS];
int KeyReg3[NO_OF_BUTTONS];

int button_flag[NO_OF_BUTTONS];

int TimeOutForKeyPress[NO_OF_BUTTONS];
//init all KeyReg

void initSomeVariables() { //call this function in main.c
	for (int i=0; i<NO_OF_BUTTONS; i++) {
		button_flag[i] = 0; //flags
		KeyReg0[i] = NORMAL_STATE;
		KeyReg1[i] = NORMAL_STATE;
		KeyReg2[i] = NORMAL_STATE;
		KeyReg3[i] = NORMAL_STATE;
		TimeOutForKeyPress[i] = 300; //Auto change the buttons's state
	}
}

void getKeyInput() {
	for (int i=0; i<NO_OF_BUTTONS; i++) {
		switch(i) {
			case 0:
				KeyReg2[i] = KeyReg1[i];
				KeyReg1[i] = KeyReg0[i];
				KeyReg0[i] = HAL_GPIO_ReadPin(A1_GPIO_Port, A1_Pin);
				break;
			case 1:
				KeyReg2[i] = KeyReg1[i];
				KeyReg1[i] = KeyReg0[i];
				KeyReg0[i] = HAL_GPIO_ReadPin(A2_GPIO_Port,A2_Pin);
				break;
			case 2:
				KeyReg2[i] = KeyReg1[i];
				KeyReg1[i] = KeyReg0[i];
				KeyReg0[i] = HAL_GPIO_ReadPin(A3_GPIO_Port, A3_Pin);
				break;
			default:
				//todo
				break;
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
			  KeyReg3[i] = KeyReg2[i];
			  if (KeyReg3[i] == PRESSED_STATE){
				TimeOutForKeyPress[i] = 300;
				button_flag[i] = 1;
			  }
			} else{
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					if (KeyReg3[i] == PRESSED_STATE){
						TimeOutForKeyPress[i] = 100;
						button_flag[i] = 1;
					 }
//					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}

	}
}

int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
//------------------
int KeyRegB20 = NORMAL_STATE;
int KeyRegB21 = NORMAL_STATE;
int KeyRegB22 = NORMAL_STATE;
int KeyRegB23 = NORMAL_STATE;
int TimeForKeyPress2 =  100;
int ac_flagB2 =0;
void isB2Nor(){
 	KeyRegB20 = KeyRegB21;
 			  			KeyRegB21 = KeyRegB22;
 			  			KeyRegB22 = HAL_GPIO_ReadPin(A0_GPIO_Port, A0_Pin);
 			  			if ((KeyRegB20 == KeyRegB21)&&(KeyRegB21 == KeyRegB22)){
 			  			if (KeyRegB22 != KeyRegB23){
 			  					  KeyRegB23 = KeyRegB22;

 			  			if (KeyRegB22 == PRESSED_STATE){
 			  				TimeForKeyPress2 = 100;
 			  				ac_flagB2 = ac_flagB2 + 1;// CODE ch???c n??ng sau khi nh???n tr??n 30s
 			  				if(ac_flagB2 == 2){ac_flagB2 =0;}
 			  				// n??t nh???n th??? 2

 			  				}}else{
 			  					TimeForKeyPress2 --;
 			  					        if (TimeForKeyPress2 == 0){
 			  					          KeyRegB23 = NORMAL_STATE;
 			  					        }
 			  				}

 			  			}
 }

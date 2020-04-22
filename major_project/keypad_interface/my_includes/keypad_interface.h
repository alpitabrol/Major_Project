/*
 * keypad_interface.h
 *
 *  Created on: Apr. 9, 2020
 *      Author: devil
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "wiringPi.h"
#include<iostream>
#include <string.h>
#define ROWS 4
#define COLS 3
//using namespace std;




int rowVal = -1;
int colVal = -1;
int c=0,r=0;
//assigning the pins attached from keypad to raspberry pi
int rowPins[ROWS] = {21,22,23,24};
int colPins[COLS] = {25,27,28};
char keys[ROWS][3] =
{
   {'1', '2', '3'},
   {'4', '5', '6'},
   {'7', '8', '9'},
   {'*', '0', '#'}
};



int findrow();
int findCol();
void reset_vals();
int get_key();



#endif /* KEYPAD_INTERFACE_H_ */

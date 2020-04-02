#include "wiringPi.h"
#include<iostream>
#include <string.h>
#define ROWS 4
#define COLS 3

using namespace std;


//defining universal variables
int rowVal = -1, colVal = -1;
int c=0,r=0;

//assigning the pins attached from keypad to raspberry pi
int rowPins[ROWS] = {21,22,23,24};
int colPins[COLS] = {25,27,28};

char keys[ROWS][COLS] = {
   {'1', '2', '3'},
   {'4', '5', '6'},
   {'7', '8', '9'},
   {'*', '0', '#'}
};

//function for scanning rows for pushed button
int findRow()
{

   for (r = 0; r < ROWS; r++)
   {
      if (digitalRead(rowPins[r]) == LOW)
         return r;
   }

   return -1;
}

//function for scanning columns for pushed button
int findCol()
{
   for (c = 0; c < COLS; c++)
   {
      if (digitalRead(colPins[c]) == HIGH)
         return c;
   }

   return -1;
}

// Reinitialize all rows and columns as input
void reset_vals()
{
	for (r = 0; r < ROWS; r++)
		   {
		      pinMode(rowPins[r], INPUT);
		      pullUpDnControl(rowPins[r], PUD_UP);
		   }

	for (c = 0; c < COLS; c++)
		   {
		      pinMode(colPins[c], INPUT);
		      digitalWrite(colPins[c], PUD_UP);
		   }
}


//program to check if any key pressed
int get_key()
{

	//Set all columns as output low
	for (c = 0; c < COLS; c++)
	   {
	      pinMode(colPins[c], OUTPUT);
	      digitalWrite(colPins[c], LOW);
	   }

	//Set all rows as input
	for (r = 0; r < ROWS; r++)
	   {
	      pinMode(rowPins[r], INPUT);
	      pullUpDnControl(rowPins[r], PUD_UP);
	   }

	// Calling function for scanning rows for pushed button
	rowVal = findRow();

	//exiting if no button pressed
	if (rowVal<0 || rowVal>3)
	{
		reset_vals();
		return 0;
	}

	//Convert columns to input
	for (c = 0; c < COLS; c++)
		   {
		      pinMode(colPins[c], INPUT);
		      pullUpDnControl(colPins[c], PUD_DOWN);
		   }

	//Switch the pressed button row found from scan to output
	pinMode(rowPins[rowVal], OUTPUT);
	digitalWrite(rowPins[rowVal], HIGH);

	// Calling function for scanning rows for pushed button
	colVal = findCol();

	//exiting if no button pressed
	if (colVal<0 || colVal>2)
	{
		reset_vals();
		return 0;
	}

	//Calling function for reinitialize all rows and columns as input
	reset_vals();

	 //Return the value of the key pressed
	return keys[rowVal][colVal];

}

//Main function
int main(void)
{
	 wiringPiSetup();

	 char digit;
	 char code_seq[6]= "";
	 char shopping_list[10][2];





	 while(1)
	 {
	   while (!digit)
	   {
		   digit = get_key();
	   }
	  cout<<digit<<endl;
	  // printf("%c \n",digit);
	 delay(500);
	 digit ='\0';
	 }
	  return 0;

}
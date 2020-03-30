#include "wiringPi.h"
#include <stdio.h>



#define ROWS 4
#define COLS 3
int rowVal = -1, colVal = -1;
int c=0,r=0;
int rowPins[ROWS] = {26,24,23,22};
int colPins[COLS] = {21,19,10};

char keys[ROWS][COLS] = {
   {'1', '2', '3'},
   {'4', '5', '6'},
   {'7', '8', '9'},
   {'*', '0', '#'}
};

int findRow()
{
   for (r = 0; r < ROWS; r++)
   {
      if (digitalRead(rowPins[r]) == LOW)
         return r;
   }

   return -1;
}

int findCol()
{
   for (c = 0; c < COLS; c++)
   {
      if (digitalRead(colPins[c]) == HIGH)
         return c;
   }

   return -1;
}


void reset_vals()
{
	for (r = 0; r < ROWS; r++)
		   {
		      pinMode(rowPins[r], INPUT);
		      pullUpDnControl(rowPins[r], PUD_UP);
		   }

	for (c = 0; c < COLS; c++)
		   {
		      pinMode(colPins[c], OUTPUT);
		      digitalWrite(colPins[c], LOW);
		   }
}

int get_key()
{
	for (c = 0; c < COLS; c++)
	   {
	      pinMode(colPins[c], OUTPUT);
	      digitalWrite(colPins[c], LOW);
	   }

	for (r = 0; r < ROWS; r++)
	   {
	      pinMode(rowPins[r], INPUT);
	      pullUpDnControl(rowPins[r], PUD_UP);
	   }



	rowVal = findRow();

	if (rowVal<0 || rowVal>3)
	return 0;

	for (c = 0; c < COLS; c++)
		   {
		      pinMode(colPins[c], INPUT);
		      pullUpDnControl(colPins[c], PUD_UP);
		   }

	pinMode(rowPins[rowVal], OUTPUT);
	digitalWrite(rowPins[rowVal], HIGH);


	colVal = findCol();

	if (colVal<0 || colVal>2)
	return 0;

	reset_vals();
	return keys[rowVal][colVal];

}


int main(void)
{
	 wiringPiSetup () ;

	   int digit =0;

	   while (!digit)
	   {
		   digit = get_key();
	   }
	  printf("%d /n",digit);

	  return 0;

}

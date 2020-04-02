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
	 int check = 1, start_shopping = 0 , weight_code=1;
	 string code = "";
	 char digit= '\0';
	 string temp_list[20][2];
	 string shopping_list[20][2];
	 int temp_list_row = 0;
	 cout<<"Enter 1111# for Start Shopping.\n"<<endl;

	 while(check)
	 {
		 while (!digit)
		 {
			 digit = get_key();
		 }
		 cout<<"digit pressed: "<<digit<<endl;

		 if(digit == '#' && (code.length()== 4 || code.length()==5) )
		 {
			 if (start_shopping==0 && code == "1111")
			 {
				 code = "";
				 digit = '\0';
				 start_shopping = 1;
				 cout<<"Shopping Started"<<endl;
			 }

			 else if (code == "0000")
			 {
				 check = 0;
				 code = "";
				 digit = '\0';
				 start_shopping = 0;

				 for(int i=0 ; i <temp_list_row  ; i++)
				 {
					 for(int j=0 ; j<2 ; j++)
					 {
						 shopping_list[i][j] = temp_list[i][j];
					 }
				 }
				 cout<<"Shopping Ended :)"<<endl;
			 }

			 else if (start_shopping==1 && (code.length() == 4 || code.length() == 5))
						 {

							 temp_list[temp_list_row][0] = code;
							 digit = '\0';
							 cout<<"Enter weight(in lbs) for the Code Entered "<<code<<endl;//<<": ";

							 weight_code=1;

							while(weight_code)
							{
								delay(500);
								while (!digit)
							 	 {
							 		 digit = get_key();
							 	 }
								if(digit=='1'||digit=='2'||digit=='3'||digit=='4'||digit=='5'||digit=='6'||digit=='7'||digit=='8'||digit=='9')
								{
								 temp_list[temp_list_row][1] = digit;
								 cout<<"Weight Entered: "<<digit<<endl;

								cout<<"Enter the code for next item or 0000# for finishing shopping"<<endl;
								 weight_code = 0;
								 digit='\0';
								 code = "";
								 temp_list_row++;
								}
								else
								{
									cout<<"not a correct weight, enter correct weight"<<endl;
									digit='\0';
								}
							}

						 }

			 else
			 {
				 code = "";
				 digit = '\0';
			 }
		 }

		 else if (digit == '*' || digit == '#')
		 {
			 digit = '\0';
			 code = "";
		 }

		 else
		 {
			code = code + digit;
			digit = '\0';
			cout<<"Code so far: "<<code<<endl;
		 }


		   delay(500);


	 }

cout<<"Item's Code	Weight(lbs)"<<endl;
for(int i=0;i<temp_list_row;i++)
{
	for(int j=0 ; j < 2 ; j++)
	{
		cout<<shopping_list[i][j]<<" 		";
	}
cout<<endl;
}


return 0;

}

#include <iostream>
#include "../my_includes/SocketClient.h"
#include "../my_includes/keypad_interface.h"

using namespace std;
using namespace exploringRPi;

//function for scanning rows for pushed button
int findrow() {

	for (r = 0; r < ROWS; r++) {
		if (digitalRead(rowPins[r]) == LOW)
			return r;
	}

	return -1;
}

//function for scanning columns for pushed button
int findCol() {
	for (c = 0; c < COLS; c++) {
		if (digitalRead(colPins[c]) == HIGH)
			return c;
	}

	return -1;
}

// Reinitialize all rows and columns as input
void reset_vals() {
	for (r = 0; r < ROWS; r++) {
		pinMode(rowPins[r], INPUT);
		pullUpDnControl(rowPins[r], PUD_UP);
	}

	for (c = 0; c < COLS; c++) {
		pinMode(colPins[c], INPUT);
		digitalWrite(colPins[c], PUD_UP);
	}
}

//program to check if any key pressed
int get_key() {

//Set all columns as output low
	for (c = 0; c < COLS; c++) {
		pinMode(colPins[c], OUTPUT);
		digitalWrite(colPins[c], LOW);
	}

//Set all rows as input
	for (r = 0; r < ROWS; r++) {
		pinMode(rowPins[r], INPUT);
		pullUpDnControl(rowPins[r], PUD_UP);
	}

// Calling function for scanning rows for pushed button
	rowVal = findrow();

//exiting if no button pressed
	if (rowVal < 0 || rowVal > 3) {
		reset_vals();
		return 0;
	}

//Convert columns to input
	for (c = 0; c < COLS; c++) {
		pinMode(colPins[c], INPUT);
		pullUpDnControl(colPins[c], PUD_DOWN);
	}

//Switch the pressed button row found from scan to output
	pinMode(rowPins[rowVal], OUTPUT);
	digitalWrite(rowPins[rowVal], HIGH);

// Calling function for scanning rows for pushed button
	colVal = findCol();

//exiting if no button pressed
	if (colVal < 0 || colVal > 2) {
		reset_vals();
		return 0;
	}

//Calling function for reinitialize all rows and columns as input
	reset_vals();

//Return the value of the key pressed
	return keys[rowVal][colVal];

}

int main(int argc, char *argv[]) {

	wiringPiSetup();
	int check = 1, start_shopping = 0, weight_code = 1;
	string code = "";
	char digit = '\0';
	string temp_list[20][2];
	string shopping_list[20][2];
	int temp_list_row = 0;

	cout << "Bonjour! I am a Keypad for Nutrtitonal Tracker 1.0\n"
			<< "I feed on PLU codes,make sure you enter a lot.\n\n"
			<< "To begin your shopping,press 1111#" << endl;

	while (check) {
		while (!digit) {
			digit = get_key();
		}

		if (digit == '#' && (code.length() == 4 || code.length() == 5)) {
			if (start_shopping == 0 && code == "1111") {
				code = "";
				digit = '\0';
				start_shopping = 1;
				cout
						<< "Yeah!It's time to track some nutrition!! Bang on with numbers!!"
						<< endl;
			}

			else if (code == "0000") {
				check = 0;
				code = "";
				digit = '\0';
				start_shopping = 0;

				for (int i = 0; i < temp_list_row; i++) {
					for (int j = 0; j < 2; j++) {
						shopping_list[i][j] = temp_list[i][j];
					}
				}
				cout << "\nOuch! I ate a lot." << endl;
			}

			else if (start_shopping == 1
					&& (code.length() == 4 || code.length() == 5)) {

				temp_list[temp_list_row][0] = code;
				digit = '\0';
				cout << "Please don't forgot to enter  the weight(lbs) for code"
						<< code << endl; //<<": ";

				weight_code = 1;

				while (weight_code) {
					delay(500);
					while (!digit) {
						digit = get_key();
					}
					if (digit == '1' || digit == '2' || digit == '3'
							|| digit == '4' || digit == '5' || digit == '6'
							|| digit == '7' || digit == '8' || digit == '9') {
						temp_list[temp_list_row][1] = digit;
						cout << "Weight Entered: " << digit << endl;

						cout
								<< "Either enter the next code or end my system with 0000# :("
								<< endl;
						weight_code = 0;
						digit = '\0';
						code = "";
						temp_list_row++;
					} else {
						cout << "not a correct weight, enter correct weight"
								<< endl;
						digit = '\0';
					}
				}
			}

			else {
				code = "";
				digit = '\0';
			}
		}

		else if (digit == '*' || digit == '#') {
			digit = '\0';
			code = "";
		}

		else {
			code = code + digit;
			digit = '\0';
			cout << "Code so far: " << code << endl;
		}
		delay(500);
	}
	int entered_items = 0;
	cout << "PLU Codes	Weight(lbs)" << endl;
	for (int i = 0; i < temp_list_row; i++) {
		for (int j = 0; j < 2; j++) {
			cout << shopping_list[i][j] << " 		";
			entered_items = i + 1;
		}
		cout << endl;
	}

	if (argc != 2) {
		cout << "Incorrect usage: " << endl;
		cout << "   client server_name" << endl;
		return 2;
	}

	cout << "Now, transmitting the shopping list to server." << endl;
	SocketClient sc(argv[1], 54321);
	sc.connectToServer();

	string msg = "";
	for (int i = 0; i < entered_items; i++) {
		for (int j = 0; j < 2; j++) {
			msg += shopping_list[i][j];
			msg += "#";
		}
	}
	sc.send(msg);

	cout << "Processing for Nutritional Tracker 1.0 Ended." << endl;
}

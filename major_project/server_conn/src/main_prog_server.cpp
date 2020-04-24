#include <iostream>
#include "../my_includes/SocketServer.h"
#include <string.h>
#include <sstream>
#include <fstream>
#include<sstream>
#include "../my_includes/html_page_2.h"
using namespace std;
using namespace exploringRPi;

int main(int argc, char *argv[]) {

	SocketServer server(54321);
	server.listen();
	string msg = "";

	msg = server.receive(1024);

	int rec_msg_size = msg.size();
	char msg_char_array[rec_msg_size + 1];

	strcpy(msg_char_array, msg.c_str());

	string msg_to_str[200];
	string temp_str = "";
	int msg_str_counter = 0;

	for (int i = 0; i < rec_msg_size; i++) {
		if (msg_char_array[i] == '#') {
			msg_to_str[msg_str_counter] = temp_str;
			msg_str_counter++;
			temp_str = "";
		} else
			temp_str += msg_char_array[i];
	}

	string user_input_code[20];
	string user_input_weight[20];

	int code_counter = 0, weight_counter = 0;

	for (int i = 0; i < msg_str_counter; i++) {
		if (i % 2 == 0) {
			user_input_code[code_counter] = msg_to_str[i];
			code_counter++;
		} else {
			user_input_weight[weight_counter] = msg_to_str[i];
			weight_counter++;
		}
	}

	string data[306][6];
	ifstream file(
			"/home/devil/Desktop/NUTRITIONAL-TRACKER/major_project/server_conn/Debug/data.csv");

	for (int row = 0; row < 306; ++row) {
		string line;
		getline(file, line);
		if (!file.good())
			break;

		stringstream iss(line);

		for (int col = 0; col < 6; ++col) {
			string val;
			getline(iss, val, ',');
			if (!iss.good())
				break;

			stringstream convertor(val);
			convertor >> data[row][col];
		}
	}

	string user_input_info[code_counter][7];
	int user_input_info_counter = 0;
	int temp_code_weight_counter = 0;
	for (int i = 1; i < 306; ++i) {
		if (data[i][0] == user_input_code[temp_code_weight_counter]) {
			for (int x = 0; x < 6; ++x) {
				user_input_info[user_input_info_counter][x] = data[i][x];
			}
			user_input_info[user_input_info_counter][6] =
					user_input_weight[temp_code_weight_counter];
			temp_code_weight_counter++;
			user_input_info_counter++;
		}
	}

	string second_page_info[code_counter][7];

	int portions_bought[code_counter];
	int pieces_bought;
	int sum_of_protions = 0;
	for (int i = 0; i < code_counter; ++i) {

		if (stoi(user_input_info[i][4]) == 1) {
			portions_bought[i] = stoi(user_input_info[i][5])
					* stoi(user_input_info[i][6]);
		} else {

			pieces_bought = stoi(user_input_info[i][6])
					* stoi(user_input_info[i][4]);

			portions_bought[i] = pieces_bought / stoi(user_input_info[i][5]);

		}
		sum_of_protions += portions_bought[i];
	}

	string portion_bought_string[code_counter];

	for (int i = 0; i < code_counter; ++i) {
		portion_bought_string[i] = to_string(portions_bought[i]);
	}

	for (int i = 0; i < code_counter; ++i) {
		second_page_info[i][0] = user_input_info[i][0];     //plu code
		second_page_info[i][1] = user_input_info[i][1];      //name
		second_page_info[i][2] = user_input_info[i][2];     //variety
		second_page_info[i][3] = user_input_info[i][3];     //size
		second_page_info[i][4] = user_input_info[i][6];    //weight bought
		second_page_info[i][6] = portion_bought_string[i]; //number of portions bought

		if (stoi(user_input_info[i][4]) == 1) {
			string temp = user_input_info[i][5];

			temp = "1/" + temp;

			second_page_info[i][5] = temp;

			temp = "";
		} else {
			second_page_info[i][5] = user_input_info[i][5]; //pieces in a portion
		}
	}

	int days_to_go = sum_of_protions / 5;
	int portions_to_go = sum_of_protions % 5;

	html_page(code_counter, second_page_info, days_to_go, portions_to_go);

	return 0;
}


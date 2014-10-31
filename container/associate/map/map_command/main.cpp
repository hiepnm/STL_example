/*
 * main.cpp
 *
 *  Created on: May 15, 2014
 *      Author: hiepnm
 */


#include "appcommand.hpp"
PrintStudentListCmd prn_cmd;
QuitCmd quit_cmd;
CCommandSet command_set;
bool QuitCmd::isRun = true;

void initialize() {
	command_set.insert_command(&prn_cmd);
	command_set.insert_command(&quit_cmd);
}
int main(int argc, char **argv) {
	initialize();
	std::string command_str;
	std::vector<std::string> str_vec;
	while(QuitCmd::isRun) {
		std::cout << "Lenh>";
		std::cin >> command_str;
		command_set.execute(command_str);
	}
	return 0;
}



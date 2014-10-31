/*
 * CCommandSet.cpp
 *
 *  Created on: May 13, 2014
 *      Author: hiepnm
 */

#include "CCommandSet.h"
#include <stdio.h>
CCommandSet::CCommandSet():isRun(false) {
	// TODO Auto-generated constructor stub

}
void CCommandSet::insert_command(CCommand* p_command) {
	(*this)[p_command->get_code()] = p_command;				//insert a command pointer
}
void CCommandSet::remove_command(std::string cmd_code) {
	erase(cmd_code);										// remove a commnad pointer
}
void CCommandSet::extract(std::string cmd_str) {
	current_cmd_code.clear();
	std::string::iterator it = cmd_str.begin();
	while(it!=cmd_str.end()) {
		std::string word("");
		while(*it==' '&&it!=cmd_str.end())
			it++;
		while(*it!=' '&&it!=cmd_str.end())
			word+=(*it++);
		current_cmd_argv.push_back(word);
	}
	current_cmd_code = current_cmd_argv[0];
	current_cmd_argv.erase(current_cmd_argv.begin());
}
int CCommandSet::execute(std::string cmd_str) {
	extract(cmd_str);
	iterator cmd_it = find(current_cmd_code);			// O(1): directive access
	if (cmd_it != end()) {								//found
		return (cmd_it->second)->execute(current_cmd_argv);
	}
	std::cout << "Khong co lenh " << current_cmd_code << " trong tap lenh" << std::endl;//not found
	return -1;

}
CCommandSet::~CCommandSet() {
	// TODO Auto-generated destructor stub
}


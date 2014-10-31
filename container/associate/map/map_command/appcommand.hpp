/*
 * appcommand.h
 *	some commands to use in app
 *  Created on: May 13, 2014
 *      Author: hiepnm
 */

#ifndef APPCOMMAND_H_
#define APPCOMMAND_H_

#include "Command.h"
#include "CCommandSet.h"
class PrintStudentListCmd: public CCommand
{
public:
	PrintStudentListCmd();
	virtual ~PrintStudentListCmd();
	int execute(std::vector<std::string> cmd_argv = std::vector<std::string>());
};

class QuitCmd: public CCommand
{
public:
	static bool isRun;
public:
	QuitCmd();
	virtual ~QuitCmd();
	int execute(std::vector<std::string> cmd_argv = std::vector<std::string>());
};

PrintStudentListCmd::PrintStudentListCmd():CCommand("print", std::vector<std::string>()) {

}
int PrintStudentListCmd::execute(std::vector<std::string> cmd_argv) {
	if (cmd_argv.size() > 0) {
		std::cout << "Tham so khong hop le" << std::endl;
		return 1;
	}
	std::cout << "Yeu cau in dan sach da hoan thanh" << std::endl;
	return 0;
}
PrintStudentListCmd::~PrintStudentListCmd() {

}
QuitCmd::QuitCmd():CCommand("quit", std::vector<std::string>()) {

}
int QuitCmd::execute(std::vector<std::string> cmd_argv) {
	if (cmd_argv.size() > 0) {
		std::cout << "Tham so khong hop le" << std::endl;
		return 1;
	}
	std::cout << "Tam biet" << std::endl;
	isRun = false;
	return 0;
}
QuitCmd::~QuitCmd(){

}
#endif /* APPCOMMAND_H_ */

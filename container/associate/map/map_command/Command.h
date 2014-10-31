/*
 * Command.h
 *	a abstract class, define the basic concepts of a command.
 *  Created on: May 13, 2014
 *      Author: hiepnm
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>
//#include <algorithm>

class CCommand {
public:
	CCommand();
	CCommand(std::string cmd_code, std::vector<std::string> cmd_argv);
	std::string get_code();
	virtual int execute(std::vector<std::string>cmd_argv=std::vector<std::string>()) = 0;
	virtual ~CCommand();
protected:
	std::string code;
	int argc;
	std::vector<std::string> argv;
private:


};

#endif /* COMMAND_H_ */

















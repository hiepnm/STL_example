/*
 * Command.cpp
 *
 *  Created on: May 13, 2014
 *      Author: hiepnm
 */

#include "Command.h"

CCommand::CCommand():argc(0)
{
	// TODO Auto-generated constructor stub

}
CCommand::CCommand(std::string cmd_code, std::vector<std::string> cmd_argv):
		code(cmd_code), argc(cmd_argv.size())
{
}
std::string CCommand::get_code() {
	return code;
}
CCommand::~CCommand() {
	// TODO Auto-generated destructor stub
}


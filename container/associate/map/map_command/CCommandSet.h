/*
 * CCommandSet.h
 *	store a set of command
 *  Created on: May 13, 2014
 *      Author: hiepnm
 */

#ifndef CCOMMANDSET_H_
#define CCOMMANDSET_H_

#include "Command.h"

class CCommandSet: public std::map<std::string, CCommand*> {	// a command set extends std::map
public:
	typedef std::map<std::string, CCommand*>::iterator iterator;
	bool isRun;

	CCommandSet();
	virtual ~CCommandSet();
	void insert_command(CCommand* p_command);			// insert a command pointer to set
	void remove_command(std::string cmd_code);			// remove a command pointer from set using command name
	int execute(std::string cmd_str);					// execute a command in set
private:
	std::vector<std::string> current_cmd_argv;			// current command argument
	std::string current_cmd_code;						// current command name
	void extract(std::string cmd_str);					// parse a command line to arguments and name

};

#endif /* CCOMMANDSET_H_ */

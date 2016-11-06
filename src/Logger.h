/*
 * Logger.h
 *
 *  Created on: Nov 6, 2016
 *      Author: justingriggs
 */

#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include <iostream>
#include <string>
#include "Robot.h"

namespace std {

class Logger {
public:
	Logger();
	//SetLogInterval(int period);  //set the logging period in msec
	//


private:
	string m_filepathbase = "/home/lvuser/";
	string m_filename;
};

} /* namespace std */

#endif /* SRC_LOGGER_H_ */

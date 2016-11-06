/*
 * Logger.h
 *
 *  Created on: Nov 6, 2016
 *      Author: justingriggs
 */

#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Robot.h"

namespace std {

class Logger {
public:
	Logger();
	Logger(string filename);
	void SetLogInterval(int period);  	//set the logging period in msec
	void CreateNewCSVFile();			//create a new CSV log file
	string CurrentDateTime();

private:
	string m_filepathbase = "/home/lvuser/";
	string m_filename;
	fstream* m_filestream;
	int m_period;
};

} /* namespace std */

#endif /* SRC_LOGGER_H_ */

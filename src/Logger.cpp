/*
 * Logger.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: justingriggs
 */

#include <Logger.h>

using namespace std;

Logger::Logger() {
	// TODO Auto-generated constructor stub

	m_filestream->open(m_filepathbase+CurrentDateTime()+".csv", fstream::out);
}


Logger::Logger(string filename) {
	// TODO Auto-generated constructor stub

	m_filename = filename;
	m_filestream->open(m_filepathbase+m_filename+".csv", fstream::out);
}

void Logger::SetLogInterval(int period) {
	period = m_period;
}

//void Logger::CreateNewCSVFile() {
//	if(!m_filestream->is_open()) {
//
//	}
//		//create a file
//}

string Logger::CurrentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

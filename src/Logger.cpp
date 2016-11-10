/*
 * Logger.cpp
 *
 *  Created on: Nov 6, 2016
 *      Author: justingriggs
 */

#include <Logger.h>

using namespace std;


Logger::Logger() {
	m_timer = new Timer();
	m_timer->Start();
	CreateNewFile("log"+CurrentDateTime());

	if(!m_filestream.is_open()) {
		cout << m_filepathbase+CurrentDateTime()+".csv" << " Log File failed to open!" << endl;
	}
}


Logger::Logger(string filename) {
	m_timer = new Timer();
	m_timer->Start();
	m_filenamebase = filename;
	CreateNewFile(m_filenamebase);

	if(!m_filestream.is_open()) {
		cout << m_filepathbase+CurrentDateTime()+".csv" << " Log File failed to open!" << endl;
	}
}


void Logger::SetLogInterval(double period) {
	m_period = period;
}

void Logger::CreateNewFile(string filename) {
	m_filestream.open(m_filepathbase+filename+".csv", fstream::out | fstream::in);
	m_filestream << "Start of Log at " << CurrentDateTime() << "\n";
}

void Logger::CloseFile() {
	m_filestream.close();
}

string Logger::CurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


void Logger::WriteToFile(string name, string value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);
	m_filestream << time << "," << name << "," << value << "\n";
}


void Logger::AddtoBuffer(string name, string value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	data.name = name;
	data.value = value;
	logbuffer.push(data);

}


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
	string name = m_filepathbase+filename+".csv";
	m_filestream.open(name);
	m_filestream << "Start of Log at " << CurrentDateTime() << "\n";
	cout << "created file " << name << endl;
}

void Logger::CloseFile() {
	m_filestream.close();
	cout << "log file closed" << endl;
}

string Logger::CurrentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}


void Logger::AddtoBuffer(string name, string value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	data.name = name;
	data.value = value;
	logbuffer.push(data);
}


void Logger::AddtoBuffer(string name, double value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	data.name = name;
	data.value = to_string(value);;
	logbuffer.push(data);
}


void Logger::AddtoBuffer(string name, int value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	//data.timestamp = CurrentDateTime();
	data.name = name;
	data.value = to_string(value);
	logbuffer.push(data);
}


void Logger::AddtoBuffer(string name, float value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	//data.timestamp = CurrentDateTime();
	data.name = name;
	data.value = to_string(value);
	logbuffer.push(data);
}

void Logger::AddtoBuffer(string name, bool value) {
	logkey data;
	data.timestamp = Timer::GetFPGATimestamp();
	//data.timestamp = CurrentDateTime();
	data.name = name;
	data.value = to_string(value);
	logbuffer.push(data);
}


void Logger::WriteBuffertoFile() {
	//cout << "writing log buffer" << endl;
	while(!logbuffer.empty()) {
		logkey data = logbuffer.front();
		WritetoFile(data.timestamp, data.name,data.value);
		logbuffer.pop();
	}
}


void Logger::WritetoFile(string name, string value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);

	m_filestream << str_time << "," << name << "," << value << "\n";
}


void Logger::WritetoFile(double time, string name, string value) {
	m_filestream << time << "," << name << "," << value << "\n";
}


void Logger::WritetoFile(string name, double value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);
	//string str_time = CurrentDateTime(); //for testing

	m_filestream << str_time << "," << name << "," << value << "\n";
}


void Logger::WritetoFile(string name, int value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);
	//string str_time = CurrentDateTime(); //for testing

	m_filestream << str_time << "," << name << "," << value << "\n";
}


void Logger::WritetoFile(string name, float value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);
	//string str_time = CurrentDateTime(); //for testing

	m_filestream << str_time << "," << name << "," << value << "\n";
}


void Logger::WritetoFile(string name, bool value) {
	double time = Timer::GetFPGATimestamp();
	string str_time = to_string(time);
	//string str_time = CurrentDateTime();  //for testing

	m_filestream << str_time << "," << name << "," << value << "\n";
}


int Logger::GetBufferSize() {
	return logbuffer.size();
}


void Logger::FlushBuffer() {
	while(!logbuffer.empty())
		logbuffer.pop();
}

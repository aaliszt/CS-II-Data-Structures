// File:        logentry.cpp  
// Date:        3 / 24 / 2016
// Author:     	Aaron Liszt 
// Description: Class implementation for a log entry.

#include <iostream>
#include <vector>
#include <cassert>
#include "string.hpp" 
#include "logentry.hpp"

//////////////////////////////////////////////////////////
// REQUIRES: str contains an int, and size = length of str
// ENSURES: the int value in str is returned as an int 
int stoi(String str, int size){
	int val = 0;
	int temp = 0;
	for(int i = 0; i < size; ++i){         // While i < str.length() convert the characters in str to ints
		temp = int(str[i]) - int('0'); // Converts individual character to int
		val = val * 10;                // Add another digit when val has more than one digit
		val += temp;                   // Add the most recent int to the end of val
	}
	return val;
} 
		
//////////////////////////////////////////////////////////
// REQUIRES: String s contains a valid date
// ENSURES: day, month, and year are initialized to the values in s
Date::Date(String s) {
	std::vector<String> vec = s.split(':'); 
	String temp = vec[0]; 				// Front of vec contains date
	std::vector<String> vec2 = temp.split('[');     // Remove excess [
	String date = vec2[0];		                // Now we have the date with some '/' characters
	std::vector<String> vec3 = date.split('/');     // Split at each /    
	day = vec3[0];                                  // Then put each member of vec3 with the proper variable
	month = vec3[1];
	year = stoi(vec3[2], vec3[2].length());
}

//////////////////////////////////////////////////////////
// REQUIRES: String s contains a valid time
// ENSURES: hour, minute, and second are initialized to the values in s
Time::Time(String s) {
	std::vector<String> vec = s.split(':');
	hour = stoi(vec[1], vec[1].length());    // Back of vec has time, convert each String to an int
	minute = stoi(vec[2], vec[2].length());  // and assign the to the proper variables 
	second = stoi(vec[3], vec[3].length());
}	

////////////////////////////////////////////////////////// 
// REQUIRES: 
// ENSURES: All LogEntry member variables are initialized to the values in s, or LogEntry is empty(if s is invalid)
LogEntry::LogEntry(String s) {
	std::vector<String> vec = s.split(' ');
	
	if(vec.size() != 10){ // If size != 10 the logEntry is invalid
		host = "";    // Set all members to their default values
		date = Date();
		time = Time();
		request = "";
		status = "";
		number_of_bytes = 0;
	}
	else{
		host = vec[0];
		date = Date(vec[3]); // vec[3] contains both time and date
		time = Time(vec[3]); // send each to their String ctor to be spilt an initialized
	
		String front = vec[5];                    // vec[5] == Front of request
		std::vector<String> f = front.split('"'); // Remove the quotation mark from the front of the request
		request = request + f[0] + " " + vec[6];  // Store the request with proper spacing
		String back = vec[7];                     // vec[7] == End of request
		std::vector<String> b = back.split('"');  // Remove the quotation mark from the end of the request
		request = request + " " + b[0];           // Store the request with proper spacing
	
		status = vec[8];    // vec[8] contains status number
	
		if(vec[9] == '-') // '-' represents 0 bytes
			number_of_bytes = 0;
		else
			number_of_bytes = stoi(vec[9], vec[9].length());
	}
}

//////////////////////////////////////////////////////////
// REQUIRES: LogEntry is valid
// ENSURES: LogEntry is put into out with the same format as the input file
std::ostream& operator<<(std::ostream& out, const LogEntry& log){
	if(log.isEmpty())//If log is empty then it was not valid(output nothing)
		return out;
	
	// Writes LogEntry to out with the same format as the input files 
	out << log.host;
	out << " - - ";
	out << "[" << log.date.getDay() << "/" << log.date.getMonth() << "/" << log.date.getYear();
	out << ":" << log.time.getHour() << ":" << log.time.getMinute() << ":" << log.time.getSecond() << " ";
	out << "-0400] \"" << log.request << "\" " << log.status << " " << log.number_of_bytes;
	out << std::endl;
	return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:
// ENSURES: returns a vector of LogEntrys from in
std::vector<LogEntry> parse(std::istream& in) {
	std::vector<LogEntry> result;
	String line;
	char ch;
	LogEntry log;

	while(!in.eof()){ // Read in all LogEntrys
		in.get(ch);	
		if(in.eof()) break;
		
		if(ch == '\n'){// If we are starting a new line then we must add the previous line to the vector
			log = LogEntry(line);
			result.push_back(log);
			line = "";
		}
		else
			line = line + ch;
	}
	return result;
}

////////////////////////////////////////////////////////// 
// REQUIRES: 
// ENSURES: All LogEntrys in vec are output(one per line)
void output_all(std::ostream& out, const std::vector<LogEntry> &vec) {
	for(int i = 0; i < (int)vec.size(); ++i)
		out << vec[i];   
}

////////////////////////////////////////////////////////// 
// REQUIRES: 
// ENSURES: All hosts of LogEntrys in vec are output(one per line)
void by_host(std::ostream& out, const std::vector<LogEntry> &vec) {
	for(int i = 0; i < (int)vec.size(); ++i){
		if(vec[i].getHost() != "") 	// Ignore invalid LogEntries
			out << vec[i].getHost() << std::endl;
	}
}

////////////////////////////////////////////////////////// 
// REQUIRES: 
// ENSURES: count = total number of bytes of all LogEntrys in vec
int byte_count(const std::vector<LogEntry> &vec) {
	int count = 0;
	for(int i = 0; i < (int)vec.size(); ++i)
		count = count + vec[i].getBytes();

	return count;
}


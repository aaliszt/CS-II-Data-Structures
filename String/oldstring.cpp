// Aaron Liszt
// CS 23001
// string.cpp
// Defines funtions from string.hpp

#include <iostream>
#include "string.hpp"
#include <cassert>

// Default Constructor
// Initializes the char array to 0
String::String(){ str[0] = '\0'; }

// Character Constructor
// Initializes the char array to a single char
String::String(char ch){ str[0] = ch; str[1] = '\0'; }

// Character Array Constructor
// Initializes the char array to another char array
String::String(const char s[]){
	int i = 0;
	while(s[i] != '\0'){
		str[i] = s[i];
		++i;

		if(i >= capacity()-1)// If we reach capacity()-1 (255) then we are at the last index and need to add a null terminator
			break;
	}
	str[i] = '\0';
}

// Output Operator
// Displays the String
std::ostream& operator<<(std::ostream& out, const String &rhs){
	out << rhs.str;
	return out;
}

// Input Operator
// Reads input one word at a time
std::istream& operator>>(std::istream &in, String &rhs){
	char temp[STRING_CAPACITY];
	in >> temp;
	rhs = String(temp);
	return in;
}

// Addtition Operators
// Combines two Strings
String String::operator+(const String &rhs)const{
	if(length() == capacity()-1)// If this is at capacity we cannot add to it
		return *this;
	if(rhs.length() == capacity()-1)// If rhs is at capacity we cannot add to it
		return rhs;

	String result(str);
	int offset = length();
	int i = 0;

	while(rhs.str[i] != '\0' && i < capacity()){
		result.str[offset + i] = rhs.str[i]; // Starts at the end of this and adds rhs  
		++i;
	}

	result.str[offset + i] = '\0';
	return result;
}
String operator+(const char lhs[], const String &rhs){ return String(lhs) + rhs; }
String operator+(const char lhs, const String &rhs){ return String(lhs) + rhs; }

// Substring
// Returns a substring between a given starting and ending index
String String::substr(int start, int end)const{
	String result;
	assert(0 <= start);
	assert(start <= end);
	assert(end < length());
	
	for(int i = start; i <= end; ++i)
		result.str[i - start] = str[i]; // Gets the substring out of string
	
	result.str[end - start + 1] = '\0';
	return result;
}

// Find String 
// Looks for a substring inside a String and return true if found
bool String::findstr(const String &find)const{
	if(find.length() == 1 && str[0] == find.str[0])// If find is one char and == this then just return true
		return true;

	char start = find.str[0];
	char end = find.str[find.length()-1];
	bool search = false;
	bool found = false;
	int startI = 0;
	
	for(int i = 0; i < length(); ++i){
		if(str[i] == start) // If find the first char we must start looking at the next chars
			search = true;

		if(search && str[i] != find.str[startI]){// If we are looking at the substring and the chars do not match then our search was not succesful
			search = false;
			startI = 0;
		}

		if(search && str[i] == find.str[startI]) // Increment startI if we find another char consistent with find
			++startI;

		if(search && str[i] == end && startI == find.length())// If we reach the last char in find then we have found the substring in this
			return true;
	}
	return found;
}		

// Find Char
// Looks for a character in a String and returns true if found
bool String::findchar(const char &find)const{
	for(int i = 0; i < length(); ++i){
		if(str[i] == find)
			return true;
	}
	return false;
}

// Equality Operators
// Checks if two String's are equal
bool String::operator==(const String &rhs)const{
	int i = 0;
	while((str[i] != '\0') && (str[i] == rhs.str[i]))
		++i;
	return str[i] == rhs.str[i];
}
bool operator==(const char s[], const String &lhs){ return lhs == s; }
bool operator==(const char ch, const String &lhs){ return lhs == ch; }

// Subscript Operators
// Returns the value at index i in str
char String::operator[](int i)const{
	assert(i >= 0);
	assert(i <= STRING_CAPACITY);
	return str[i];
}
char& String::operator[](int i){return str[i]; }

// Other Relational Operators
// Compares Strings 
bool String::operator<(const String &rhs)const{
	int i = 0;
	while((str[i] != '\0') && (rhs.str[i] != '\0') && (str[i] == rhs.str[i]))
		++i;
	return str[i] < rhs.str[i];
}
bool operator<(const char s[], const String &s1){ return !(s1 < s); }
bool operator<(const char ch, const String &s1){ return !(s1 < ch); }
bool operator<=(const String &lhs, const String &rhs){ return ((lhs == rhs) || (lhs < rhs)); }
bool operator!=(const String &lhs, const String &rhs){ return !(lhs == rhs); }
bool operator>=(const String &lhs, const String &rhs){ return ((lhs == rhs) || !(lhs < rhs)); }
bool operator>(const String &lhs, const String &rhs){ return !(lhs < rhs); }

// Length
// Returns the length of the String
int String::length()const{
	int L = 0;
	while(str[L] != '\0')
		++L;
	return L;
}

// Capacity
// Returns the capacity of the String
int String::capacity()const{ return STRING_CAPACITY; }

// Aaron Liszt
// CS 23001
// string.cpp
// Defines funtions from string.hpp

#include <iostream>
#include "string.hpp"
#include <cassert>

// Default Constructor
// Initializes the pointer s and Capacity to 256
String::String(){ 
	Capacity = DEFAULT_STRING_CAPACITY;
	s = new char[Capacity]; 
	s[0] = '\0';
}

// Character Constructor
// Initializes the pointer s to a character and Capacity to 256
String::String(char ch){
	Capacity = DEFAULT_STRING_CAPACITY;
	s = new char[Capacity];
	s[0] = ch;
	s[1] = '\0';
}

// Character Array Constructor
// Initializes the pointer s to a character array and Capacity to 256
String::String(const char *str){
	Capacity = DEFAULT_STRING_CAPACITY;
	s = new char[Capacity];

	int i = 0;
	while(str[i] != '\0'){
		s[i] = str[i];
		++i;
		if(i >= capacity()-1)
			resetCapacity(capacity()*2);
			
	}
	s[i] = '\0';
}

// Capacity and Character Array Constructor
// Initializes s to a character array and Capacity to a given Capacity n
String::String(int n, const char *str){
	assert(n > 0); // A pointer to an array of size 0 is undefined
	Capacity = n;
	s = new char[Capacity];
	
	int i = 0;
	while(str[i] != '\0'){
		s[i] = str[i];
		++i;
	}
	s[i] = '\0';
}

// Capacity Constructor
// Initializes string to a given Capacity n
String::String(int n){
	assert(n > 0); // A pointer to an array of size 0 is undefined
	Capacity = n;
	s = new char[Capacity];
	s[0] = '\0';
}

// Destructor
// Deallocates memory in String
String::~String(){ delete[] s; }

// Copy Constructor
// Makes temporary copies of this
String::String(const String& actual){
	Capacity = actual.Capacity;
	s = new char[Capacity];
	for(int i = 0; i < Capacity; ++i)
		s[i] = actual.s[i];
}

// Assignment operator
// Sets this equal to rhs
String& String::operator=(String rhs){
	swap(rhs);
	return *this;
}

// Swap
// Constant time swap
void String::swap(String& rhs){
	char *temp = s;
	s = rhs.s;
	rhs.s = temp;
	int ctemp = Capacity;
	Capacity = rhs.Capacity;
	rhs.Capacity = ctemp;
}

// resetCapacity
// Changes the capacity of s to n
void String::resetCapacity(int n){
	assert(n > -1);

	char *temp = new char[n];
	Capacity = n;

	if(n == 0){// If n is zero return an empty character array
		delete[] s;
		s = temp;
	}
	else{
		int i = 0;
		while(s[i] != '\0' && i < n - 1){
			temp[i] = s[i];
			++i;
		}
		temp[i] = '\0';
		delete[] s;
		s = temp;
	}	 
}

// Output Operator
// Displays the String
std::ostream& operator<<(std::ostream& out, const String &rhs){
	out << rhs.s;
	return out;
}

// Input Operator
// Reads input one word at a time
std::istream& operator>>(std::istream &in, String &rhs){
  std::cerr << "HERE\n";
	char ch = '@';
	int newCap = 0;
	rhs = "";

	while(ch != ' ' && ch != '\n' && ch != '\t' && ch != '\v' && ch != '\r' && ch != '\f' && !in.eof()){// Run while ch != whitespace and end of file
		in.get(ch);
		if(in.eof()) break;
		if((ch == ' ' || ch == '\n' || ch== '\t') && rhs == ""){// Ensures that rhs is never null, moves past extra spaces 
		  while(ch == ' ' || ch == '\n' || ch == '\t'){
		    if(in.eof()) break;
				in.get(ch);
		  } 
		  if(in.eof()) break;
		}
		if(rhs.length() >= rhs.capacity()){// Resize input when it reached capacity
			newCap = rhs.capacity() * 2;
			rhs.resetCapacity(newCap);
		}
		if(ch != ' ' && ch != '\n' && ch != '\t' && ch != '\r' && ch != '\f' && ch != '\v')// Add ch to temp if it is not whitespace
			rhs = rhs + ch;
	}
	rhs[rhs.capacity()-1] = '\0';
	return in;
}

// Addtition Operators
// Combines two Strings
String String::operator+(const String &rhs)const{
	int newCap = DEFAULT_STRING_CAPACITY;
	if(DEFAULT_STRING_CAPACITY <= length() + rhs.length()){// If the combined lengths are greater than the default cap, result needs a new capacity
		while(newCap <= length() + rhs.length())
			newCap = newCap + DEFAULT_STRING_CAPACITY;
	}
	
	String result(newCap, s);
	int offset = length();
	int i = 0;

	while(rhs.s[i] != '\0'){
		result.s[offset + i] = rhs.s[i]; // Starts at the end of this and adds rhs  
		++i;
	}

	result.s[offset + i] = '\0';
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
		result.s[i - start] = s[i]; // Gets the substring out of string
	
	result.s[end - start + 1] = '\0';
	return result;
}

// Find String 
// Looks for a substring inside a String and return true if found
bool String::findstr(const String &find)const{
	if(find.length() == 1 && s[0] == find.s[0])// If find is one char and == this then just return true
		return true;

	char start = find.s[0];
	char end = find.s[find.length()-1];
	bool search = false;
	bool found = false;
	int startI = 0;
	
	for(int i = 0; i < length(); ++i){
		if(s[i] == start) // If find the first char we must start looking at the next chars
			search = true;

		if(search && s[i] != find.s[startI]){// If we are looking at the substring and the chars do not match then our search was not succesful
			search = false;
			startI = 0;
		}

		if(search && s[i] == find.s[startI]) // Increment startI if we find another char consistent with find
			++startI;

		if(search && s[i] == end && startI == find.length())// If we reach the last char in find then we have found the substring in this
			return true;
	}
	return found;
}		

// Find Char
// Looks for a character in a String and returns true if found
bool String::findchar(const char &find)const{
	for(int i = 0; i < length(); ++i){
		if(s[i] == find)
			return true;
	}
	return false;
}

// Equality Operators
// Checks if two String's are equal
bool String::operator==(const String &rhs)const{
	int i = 0;
	while((s[i] != '\0') && (s[i] == rhs.s[i]))
		++i;
	return s[i] == rhs.s[i];
}
bool operator==(const char s[], const String &lhs){ return lhs == s; }
bool operator==(const char ch, const String &lhs){ return lhs == ch; }

// Subscript Operators
// Returns the value at index i in the array
char String::operator[](int i)const{
	assert(i >= 0);
	assert(i < length());
	return s[i];
}
char& String::operator[](int i){return s[i]; }

// Other Relational Operators
// Compares Strings 
bool String::operator<(const String &rhs)const{
	int i = 0;
	while((s[i] != '\0') && (rhs.s[i] != '\0') && (s[i] == rhs.s[i]))
		++i;
	return s[i] < rhs.s[i];
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
	while(s[L] != '\0')
		++L;
	return L;
}

// Capacity
// Returns the Capacity of the String
int String::capacity()const{ return Capacity; }

// Split
// Returns a vector of Strings split at a given char
std::vector<String> String::split(char ch) const{
	std::vector<String> vecS;

	if(!(findchar(ch))){ // If ch is not in the string, return the string
		vecS.push_back(*this);
		return vecS;
	}
	
	String temp;
		
	for(int i = 0; i < length(); ++i){
	
		if(s[i] != ch){ //If we are not at ch add the character to the temporary string
			temp = temp + s[i];
		}
		if(s[i] == ch && temp != '\0'){ // If we are at ch and the temporary string is not null 
			vecS.push_back(temp);   // Add the temp string to the vector
			temp = "";              // Reset the temp string to an empty string
		}
	}

	if(temp != '\0')//Add temp to the vector when we reach the end of the string 
		vecS.push_back(temp);
	
	return vecS;
}

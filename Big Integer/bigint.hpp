/**
 * Aaron Liszt
 * bigint.hpp
 * CS 23001
 */
// Layout for the bigint class, provides function prototypes for
// member functions and member variables of the bigint class.

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>

static const int MAX_SIZE = 200;

class bigint{
public:
	// Constructors
	bigint();
	bigint(int);
	bigint(const char[]);

	// Operators
	bool operator==(const bigint&)const;
	int operator[](int)const;
	bigint operator+(const bigint&)const;
	bigint operator*(const bigint&)const;
	bigint timesDigit(int)const;
	bigint times10(int)const;
	friend std::ostream& operator<<(std::ostream&, const bigint&);
	friend std::istream& operator>>(std::istream&, bigint&); 

private:
	int bigintArray[MAX_SIZE];
};

#endif


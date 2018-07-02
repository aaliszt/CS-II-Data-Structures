/**
 * Aaron Liszt
 * bigint.cpp
 * CS23001
 */
// Defines member funtions of the bigint class

#include "bigint.hpp"
#include <iostream>

// Default Constructor
// Initializes the bigint to 0
bigint::bigint(){
	for(int i = 0; i < MAX_SIZE; ++i)
		bigintArray[i] = 0;
}

// Int Constructor
// Takes an int and puts it into a bigint  
bigint::bigint(int num){
	int temp = num;
	for(int i = 0; i < MAX_SIZE; ++i){
		bigintArray[i] = temp % 10; // Gets the last digit in the int and adds it
		temp /= 10; 		   // to the bigint then removes the last digit from the int
	}
}	

// Character String Constructor 
// Takes a string of characters and puts them into a bigint
bigint::bigint(const char charArray[]){

	int size = 0;
	while(charArray[size] != '\0') // Gets the size of the character array
		++size;

	for(int i = 0; i < size; ++i)
		bigintArray[i] = int(charArray[size - 1 - i]) - int('0'); // Puts the charater array into the bigint
		
	for(int i = size; i < MAX_SIZE; ++i)
		bigintArray[i] = 0; // Fills the rest of the bigint with zeros
}

// Addition Operator
// Adds two bigint's together and returns the resulting bingint
bigint bigint::operator+(const bigint& rhs)const{
	bigint result;
	int digitSum = 0;
	bool carryOne = false;
	
	for(int i = 0; i < MAX_SIZE; ++i){
		if(carryOne) // If carryOne is true the previous digitSum was >= 10 thus we must carry a one to this sum
			digitSum = bigintArray[i] + rhs.bigintArray[i] + 1;
		else
			digitSum = bigintArray[i] + rhs.bigintArray[i];

		result.bigintArray[i] = digitSum % 10; 

		if(digitSum >= 10)// If digitSum >= 10 then we must carry a 1 to the next digitSum
			carryOne = true;
		else
			carryOne = false;
	}
	return result;
}

// Multiplication Operator
// Multiplies two bigint's together and returns the resulting bigint
bigint bigint::operator*(const bigint& rhs)const{
	bigint product;
	bigint temp;
	for(int i = 0; i < MAX_SIZE; ++i){
		temp = this->timesDigit(rhs.bigintArray[i]);
		product = product + temp.times10(i);
	}
	return product;
}

// Times Digit
// Multiplies a bigint by a single digit int
bigint bigint::timesDigit(int num)const{
	bigint result;
	
	if(num == 0)
		return result;
	if(num == 1)
		return *this;

	int carry = 0;
	int product = 0;
	for(int i = 0; i < MAX_SIZE; ++i){
		if(carry != 0)// When carry is greater than zero we must add to the next multiplication
			product = bigintArray[i] * num + carry;
		else
			product = bigintArray[i] * num;
		
		result.bigintArray[i] = product % 10;// Gets the last digit of product
		carry = product / 10;// Gets the first digit of product
	}
	return result;
}

// Times Ten
// Multiplies a bigint by 10^i
bigint bigint::times10(int num)const{
	bigint product;
	
	if(num == 0)// 10^0 = 1
		return *this;

	for(int i = 0; i < MAX_SIZE; ++i){
		if(i < num)// When i < num we must insert zeros
			product.bigintArray[i] = 0;
		else// Otherwise we must put the bigint back into the array
			product.bigintArray[i] = this->bigintArray[i - num]; 
	}
	return product;
}

// Equality Operator	 
// Checks if two bigints are equal and returns true if so otherwise returns false
bool bigint::operator==(const bigint& rhs)const{
	for(int i = 0; i < MAX_SIZE; ++i){
		if(bigintArray[i] != rhs.bigintArray[i])
			return false;
	}
	return true;
}

// Subscript Operator
// Returns the digit at index i in bigintArray
int bigint::operator[](int i)const{ return bigintArray[i]; }

// Output operator
// Writes bigints to an output stream
std::ostream& operator<<(std::ostream& os, const bigint& bi){

	int digits = 0;
	bool atNum = false;

	for(int i = MAX_SIZE-1; i > -1; --i){
		if(bi.bigintArray[i] != 0) // If we have reached a nonzero digit we are at the number
			atNum = true;	   // that needs to be put into the output stream
		if(atNum){
			os << bi.bigintArray[i];
			++digits; // When we begin adding to the output stream we must
		}		  // keep track of the number of digits in the stream.
		if(digits == 50){ // When the number of digits is 50 we must start a new line.
			os << std::endl;
			digits = 0;
		}
	}

	if(!atNum)// If no nonzero digits where found then bigint is zero
		os << 0;
	
	return os; 		
}

// Input Operator
// Takes data from an input stream and puts it into a bigint
std::istream& operator>>(std::istream& is, bigint& bi){
	char temp[MAX_SIZE];
	
	for(int i = 0; i < MAX_SIZE; ++i){
		char ch;
		is >> ch;
		if(ch != ';')
			temp[i] = ch;
		else{ //If we are at the end of the number we must break out of the loop
			temp[i] = '\0';
			break;
		}
	}
	bi = bigint(temp);
	return is;
}

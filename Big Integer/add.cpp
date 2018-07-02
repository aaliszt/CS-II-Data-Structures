/**
 * Aaron Liszt
 * add.cpp
 * CS 23001
 */
// Reads data from files into bigints

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main(){
	std::ifstream in("data1-1.txt");
	if(!in.is_open()){
		std::cerr << "Could not open data1-1.txt, exiting." << std::endl;
		exit(1);
	}
	
	bigint numOne;
	bigint numTwo;
	bigint result;
	
	while(!in.eof()){	
		in >> numOne;
		if(in.eof()) break; // Stops output of random data due to whitespace before the eof
		in >> numTwo;
	
		std::cout << "Bigint one is: " << numOne << std::endl << std::endl;
		std::cout << "Bigint two is: " << numTwo << std::endl;

		result = numOne + numTwo;

		std::cout <<"Sum of addition: " << result << std::endl << std::endl;
	}
	in.close();
	return 0;
}

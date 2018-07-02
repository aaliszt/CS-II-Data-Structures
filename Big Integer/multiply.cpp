/**
 * Aaron Liszt
 * multiply.cpp
 * CS 23001
 */
// Reads data from files to bigints and multiplies them

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main(){
	std::ifstream in("data1-2.txt");
	if(!in.is_open()){
		std::cerr << "Could not open file data1-2.txt, exiting." << std::endl;
		exit(1);
	}
	
	bigint numOne;
	bigint numTwo;
	bigint product;
	
	while(!in.eof()){
		in >> numOne;
		if(in.eof()) break;// Stops output of random data due to whitespace in the end of the file
		in >> numTwo;
		
		std::cout << std::endl;
		std::cout << "Bigint one is: " << numOne << std::endl << std::endl;
		std::cout << "Bigint two is: " << numTwo << std::endl;
		
		product = numOne * numTwo;

		std::cout << "The product is: " << product << std::endl;
	}
	in.close();
	return 0;
}

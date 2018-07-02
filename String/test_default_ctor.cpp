// String class test program
// TESTS: Default Constuctor

#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
	{
		//SETUP
		
		//TEST
		String str;
	
		//VERIFY
		assert(str == '\0');
	}
	std::cout << "Done testing default ctor." << std::endl;
}

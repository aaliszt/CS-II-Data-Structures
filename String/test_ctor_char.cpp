// Aaron Liszt 
// TESTS: Character constructor

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		char ch = '\0';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == '\0');	
	}
	{
		// SETUP
		char ch = 'a';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == 'a');
		std::cout << "a == " << str << std::endl;	
	}
	{
		// SETUP
		char ch = '1';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == '1');
		std::cout << "1 == " << str << std::endl;
	}
	{
		// SETUP
		char ch = ' ';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == ' ');	
	}
	{
		// SETUP
		char ch = '0';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == '0');	
		std::cout << "0 == " << str << std::endl;
	}
	{
		// SETUP
		char ch = '\t';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == '\t');	
	}
	{
		// SETUP
		char ch = '\n';

		// TESTS
		String str(ch);
		
		// VERIFY
		assert(str == '\n');	
	}
	std::cout << "Done testing char ctor." << std::endl;
}

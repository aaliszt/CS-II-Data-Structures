// Aaron Liszt
// TESTS: Subscript operator

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// TEST
		String s;
		
		// VERIFY
		assert(s[0] == '\0');
	}
	{
		// TEST
		String s('a');
		
		// VERIFY
		assert(s[0] == 'a');
	}
	{
		// TEST
		String s("abc123");
		
		// VERIFY
		assert(s[5] == '3');
	}
	{
		// TEST
		String s("     ");
		
		// VERIFY
		assert(s[3] == ' ');
	}
	{
		// TEST
		String s("1000000000000000000000000000000000000000000000000000000000001");
		
		// VERIFY
		assert(s[60] == '1');
	}
	{
		// TEST
		String s("Tests tests   tests test   test test. test %#$%#$%#$%#%#$%");
		
		// VERIFY
		assert(s[27] == 't');
	}
	{
		// TEST
		String s("WOOOOOOOOOOOOOOOOOOoooOOOoOOOoooOOoooOOOoOOOooooOOOOOOOoOOOOOOooooOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOoooOooOOOOOOOOOOooOOOOOOOOOOOOOOOOOOOOOOOOoO");
		
		// VERIFY
		assert(s[100] == 'o');
	}
	std::cout << "Done testing subscript." << std::endl;
}

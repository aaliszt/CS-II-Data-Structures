// Aaron Liszt
// TESTS: Substring

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		String s("a");
		String sub;

		// TESTS
		sub = s.substr(0,0);

		// VERIFY
		assert(sub == "a");
	}
	{
		// SETUP
		String s("abc");
		String sub;

		// TESTS
		sub = s.substr(0,2);

		// VERIFY
		assert(sub == "abc");
	}
	{
		// SETUP
		String s("abcdefghijklmnop");
		String sub;

		// TESTS
		sub = s.substr(3,6);

		// VERIFY
		assert(sub == "defg");
	}
	{
		// SETUP
		String s("Cat Bat Mat Rat Vat Fat Dat Pat Sat Nat");
		String sub;

		// TESTS
		sub = s.substr(24, 34);

		// VERIFY
		assert(sub == "Dat Pat Sat");
	}
	{
		// SETUP
		String s("BOOOOOOOOOOOOOOOOM");
		String sub;

		// TESTS
		sub = s.substr(17, 17);

		// VERIFY
		assert(sub == "M");
	}
	std::cout << "Done testing substring." << std::endl;
}

// Aaron Liszt
// TESTS: Length method

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// TEST
		String s;

		// VERIFY
		assert(0 == s.length());
	}
	{
		// TEST
		String s("5");

		// VERIFY
		assert(1 == s.length());
	}
	{
		// TEST
		String s("abcde");

		// VERIFY
		assert(5 == s.length());
	}
	{
		// TEST
		String s("          ");

		// VERIFY
		assert(10 == s.length());
	}
	{
		// TEST
		String s("abcdefghijklmnopqrstuvwxyz1234567890");

		// VERIFY
		assert(36 == s.length());
	}
	{
		// TEST
		String s;

		// VERIFY
		assert(256 == s.capacity());
	}
	std::cout << "Done testing length." << std::endl;
}

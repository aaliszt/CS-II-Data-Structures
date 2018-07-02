// Aaron Liszt
// TESTS: Equality operator

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		const char s1[1] = { '\0' };
		String s2;

		//VERIFY
		assert(s1 == s2);
		assert(s2 == s1);
	}
	{
		// SETUP
		const char s1[6] = { '1', '2', '3', '4', 'a'};
		String s2(s1);

		//VERIFY
		std::cout << "1234a == " << s2 << std::endl;
		assert(s1 == s2);
		assert(s2 == s1);
	}
	{
		// SETUP
		const char s1[2] = { 'e' };
		String s2(s1);

		//VERIFY
		std::cout << "e == " << s2 << std::endl;
		assert(s1 == s2);
		assert(s2 == s1);
	}
	{
		// SETUP
		const char s1[9] = { 'e', '3', '1', 'q', 'x', 'y', '/', ' ' };
		String s2(s1);

		//VERIFY
		std::cout << "e31qxy/  == " << s2 << std::endl;
		assert(s1 == s2);
		assert(s2 == s1);
	}
	{
		// SETUP
		char ch = '\0';
		String s;

		// VERIFY
		assert(ch == s);
		assert(s == ch);
	}
	{
		// SETUP
		char ch = ' ';
		String s(ch);

		// VERIFY
		assert(ch == s);
		assert(s == ch);
	}
	{
		// SETUP
		char ch = '%';
		String s(ch);

		// VERIFY
		assert(ch == s);
		assert(s == ch);
		std::cout << "% == " << s << std::endl;
	}
	{
		// SETUP
		char ch = 'z';
		String s(ch);

		// VERIFY
		assert(ch == s);
		assert(s == ch);
		std::cout << "z == " << s << std::endl;
	}
	{
		// SETUP
		char ch = '0';
		String s(ch);

		// VERIFY
		assert(ch == s);
		assert(s == ch);
		std::cout << "0 == " << s << std::endl;
	}
	std::cout << "Done testing equality." << std::endl;

}

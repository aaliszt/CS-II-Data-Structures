// Aaron Liszt
// TESTS: Addition

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		String lhs;
		String rhs;
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == '\0');
	}
	{
		// SETUP
		String lhs("a");
		String rhs("a");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "aa");
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs;
		String rhs('a');
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == 'a');
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs("abc");
		String rhs("def");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "abcdef");
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs("   ");
		String rhs("   ");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "      ");
	}
	{
		// SETUP
		String lhs("DANK");
		String rhs(" MEMES");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "DANK MEMES");
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs("Flowy, Toriel, Sans, Payparus, Undyne, Alphys, ");
		String rhs("Mettaton, Asgore, Asriel, Chara.");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "Flowy, Toriel, Sans, Payparus, Undyne, Alphys, Mettaton, Asgore, Asriel, Chara.");
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		String rhs("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");

	}
	{
		// SETUP
		String lhs("Wow that passes.");
		String rhs(" ~!@#$%^&*())?GHDFBN:_SE+GH'dghokwet][]");
		String result;
		
		// TEST
		result = lhs + rhs;

		// VERIFY
		assert(result == "Wow that passes. ~!@#$%^&*())?GHDFBN:_SE+GH'dghokwet][]");
		std::cout << lhs << " + " << rhs << " = " << result << std::endl;
	}
	{
		// SETUP
		String lhs("And so I cry somtimes when I'm lying in bed Just to get it all out what's in my head and I, I am feeling a little peculiar And so I wake in the morning and I step outside And I take A deep breath and I get real high And I scream from the top of my lungs, What's goin on");
		String rhs(" And I say HEYAYAYAYAYAY HEYAYA I said hey, what's goin' on And I say HEYAYAYAYA HEYAYA I said hey, what's goin' on");
		String result;
		
		// TEST
		result = lhs + rhs;
		
		// VERIFY
		assert(result == "And so I cry somtimes when I'm lying in bed Just to get it all out what's in my head and I, I am feeling a little peculiar And so I wake in the morning and I step outside And I take A deep breath and I get real high And I scream from the top of my lungs, What's goin on And I say HEYAYAYAYAYAY HEYAYA I said hey, what's goin' on And I say HEYAYAYAYA HEYAYA I said hey, what's goin' on");
		
	}
	{
		// SETUP
		char ch = '1';
		const String s;
		String result;

		// TEST
		result = ch + s;
		
		// VERIFY
		assert(result == '1');
		result = s + ch;
		assert(result == '1');
	}
	{
		// SETUP
		const char ch = '1';
		const String s('a');
		String result;

		// TEST
		result = ch + s;
	
		// VERIFY
		assert(result == "1a");
		result = s + ch;
		assert(result == "a1");
	}
	{
		// SETUP
		char ch = '0';
		const String s(" TESTS");
		String result;

		// TEST
		result = ch + s;
		
		// VERIFY
		assert(result == "0 TESTS");
		result = s + ch;
		assert(result == " TESTS0");
	}
	{
		// SETUP
		const char c[DEFAULT_STRING_CAPACITY] = { 'a' };
		String s;
		String result;
		
		// TEST
		result = c + s;

		// VERIFY
		assert(result == 'a');
		result = s + c;
		assert(result == 'a');
	}
	{
		// SETUP
		const char c[DEFAULT_STRING_CAPACITY] = { 'a' };
		String s("1");
		String result;
		
		// TEST
		result = c + s;

		// VERIFY
		assert(result == "a1");
		result = s + c;
		assert(result == "1a");
	}
	{
		// SETUP
		const char c[DEFAULT_STRING_CAPACITY] = { 'a', 'b', 'c' };
		String s("def");
		String result;
		
		// TEST
		result = c + s;

		// VERIFY
		assert(result == "abcdef");
		result = s + c;
		assert(result == "defabc");
	}	 
	std::cout << "Done testing addition." << std::endl;
}


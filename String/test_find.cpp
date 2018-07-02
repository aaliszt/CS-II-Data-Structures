// Aaron Liszt
// TESTS: findstr, findchar

#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		// SETUP
		String s("a");
		bool found = false;

		// TEST
		found = s.findstr("a");
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("aa");
		bool found = false;

		// TEST
		found = s.findstr("a");
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("aaaa");
		bool found = false;

		// TEST
		found = s.findstr("aaaa");
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("Find somthing in this string this string pls pls.");
		bool found = false;

		// TEST
		found = s.findstr(" pls");
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("I can't be what you want from me - well alright.");
		bool found = false;

		// TEST
		found = s.findstr("I can");
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("aaaa");
		bool found = false;

		// TEST
		found = s.findstr("aaaaaaaa");
	
		// VERIFY 
		assert(found == false);
	}
	{
		// SETUP
		String s("Don't need em");
		bool found = false;

		// TEST
		found = s.findstr("needs");
	
		// VERIFY 
		assert(found == false);
	}
	{
		// SETUP
		String s("Fuck the fame and all the hype G I just wanna know if my father would ever like me.");
		bool found = false;

		// TEST
		found = s.findstr("likes");
	
		// VERIFY 
		assert(found == false);
	}
	{
		// SETUP
		String s("a");
		bool found = false;

		// TEST
		found = s.findchar('a');
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("Plausible");
		bool found = false;

		// TEST
		found = s.findchar('e');
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("LMAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
		bool found = false;

		// TEST
		found = s.findchar('Z');
	
		// VERIFY 
		assert(found == false);
	}
	{
		// SETUP
		String s("What the?!");
		bool found = false;

		// TEST
		found = s.findchar(' ');
	
		// VERIFY 
		assert(found == true);
	}
	{
		// SETUP
		String s("HA-HAAAAAAAAAAAAA");
		bool found = false;

		// TEST
		found = s.findchar(' ');

		// VERIFY
		assert(found == false);
	}
	std::cout << "Done testing find methods." << std::endl;
}

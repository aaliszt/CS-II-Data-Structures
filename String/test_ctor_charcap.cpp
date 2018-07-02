// Aaron Liszt
// TESTS: Cap/Character Array Constructor

#include <iostream>
#include "string.hpp"
#include <cassert>

int main(){
	{
		// SETUP
		String s(1, "");
	
		// VERIFY
		assert(s == '\0');
		assert(1 == s.capacity());
	}
	{
		// SETUP
		String s(2, "a");
	
		// VERIFY
		assert(s == "a");
		assert(2 == s.capacity());
	}
	{
		// SETUP
		String s(4, "abc");
	
		// VERIFY
		assert(s == "abc");
		assert(4 == s.capacity());
	}
	{
		// SETUP
		String s(481, "Leedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle Lee");
		
		// VERIFY
		assert(s == "Leedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle LeeLeedle Leedle Leedle Lee");
		assert(481 == s.capacity());
	}
	std::cout << "Done testing char cap ctor."  << std::endl;
}

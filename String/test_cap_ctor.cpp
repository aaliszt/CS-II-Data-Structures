// Aaron Liszt
// TESTS: Capacity Constructors

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		String s(1);
		
		// VERIFY
		assert( 1 == s.capacity());
	}
	{
		// SETUP
		String s(1);
		
		// VERIFY
		assert( 1 == s.capacity());
		assert(s == '\0');
	}
	{
		// SETUP
		String s(56);
		
		// VERIFY
		assert( 56 == s.capacity());
		assert(s == '\0');
	}
	{
		// SETUP
		String s(300);
		
		// VERIFY
		assert( 300 == s.capacity());
		assert(s == '\0');
	}
	{
		// SETUP
		String s(1000);
		
		// VERIFY
		assert( 1000 == s.capacity());
		assert(s == '\0');
	}
	std::cout << "Done testing capacity constructors." << std::endl;
}

// Aaron Liszt
// TESTS: Split

#include <iostream>
#include <cassert>
#include "string.hpp"

int main(){
	{
		//SETUP
		String s;
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == s);
		assert(result.size() == 1);
	}
	{
		//SETUP
		String s("computer");
		std::vector<String> result;
			
		//TEST
		result = s.split('p');
		//VERIFY
		assert(result[0] == "com");
		assert(result[1] == "uter");
		assert(result.size() == 2);
	}
	{
		//SETUP
		String s("abc ef gh");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "abc");
		assert(result[1] == "ef");
		assert(result[2] == "gh");
		assert(result.size() == 3);
	}
	{
		//SETUP
		String s("abc  ef  gh");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "abc");
		assert(result[1] == "ef");
		assert(result[2] == "gh");
		assert(result.size() == 3);
	}
	{
		//SETUP
		String s("ab c de");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "ab");
		assert(result[1] == "c");
		assert(result[2] == "de");
		assert(result.size() == 3);
	}
	{
		//SETUP
		String s("ab  c  de");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "ab");
		assert(result[1] == "c");
		assert(result[2] == "de");
		assert(result.size() == 3);
	}
	{
		//SETUP
		String s("c");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "c");
		assert(result.size() == 1);
	}	
	{
		//SETUP
		String s("  ab c");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "ab");
		assert(result[1] == "c");
		assert(result.size() == 2);
	}			
	{
		//SETUP
		String s("abc   ");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "abc");
		assert(result.size() == 1);
	}			
	{
		//SETUP
		String s("a b c ");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "a");
		assert(result[1] == "b");
		assert(result[2] == "c");
		assert(result.size() == 3);
	}			
	{
		//SETUP
		String s("     ");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result.size() == 0);
	}			
	{
		//SETUP
		String s("abc");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "abc");
		assert(result.size() == 1);
	}			
	{
		//SETUP
		String s("S Sp Spa Spac Space Spac");
		std::vector<String> result;
		
		//TEST
		result = s.split(' ');

		//VERIFY
		assert(result[0] == "S");
		assert(result[1] == "Sp");
		assert(result[2] == "Spa");
		assert(result[3] == "Spac");
		assert(result[4] == "Space");
		assert(result[5] == "Spac");
		assert(result.size() == 6);
	}			
	std::cout << "Done testing split." << std::endl;
}


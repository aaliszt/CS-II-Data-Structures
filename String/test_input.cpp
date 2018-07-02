// Aaron Liszt
// TESTS: Input operator

#include "string.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>

int main(){
	std::ifstream in("input.txt");
	if(!in.is_open()){
		std::cerr << "Could not open input.txt, exiting." << std::endl;
		exit(1);
	}
	
	String s1;

	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "This");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "is");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "a");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "text");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "file");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "that");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "tests");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "the");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "input");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "method");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "of");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "string.hpp");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "and");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "checks");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "if");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "it");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "reads");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "in");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "one");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "word");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "at");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "a");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "time.");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "It");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "should");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "skip");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "all");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "spaces");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "and");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "read");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "in");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "each");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "word.");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "Here");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "is");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "a");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "316");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "character");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "string");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "with");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "no");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "spaces:");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789EndofLongString.");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "Here");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "is");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "a");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "string");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "that");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "is");
	}
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "703");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "characters:");
	} 	
	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789END");
	} 	
 	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "Test");
	}
 	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "TEST");
	}
 	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "Test...");
	}
 	if(!in.eof())
	{
		in >> s1;
		assert(s1 == "ENDOFFILE.");
	}
	std::cout << "Done testing input." << std::endl;
	in.close();
	return 0;
}

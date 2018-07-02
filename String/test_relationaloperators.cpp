// Aaron Liszt
// TESTS: <, <=, >, >=, !=

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// TEST
		String s1('a');
		String s2('c');

		// VERIFY
		assert(s1 < s2);
	}	
	{
		// TEST
		String s1("accept");
		String s2("access");
		String s3("acceptance");

		// VERIFY
		assert(s1 < s2);
		assert(s3 < s2);
		assert(s1 < s3);
	}	
	{
		// TEST
		String s1("aa");
		String s2("aaa");

		// VERIFY
		assert(s1 < s2);
	}
	{
		// TEST
		String s1("9");
		String s2("10");

		// VERIFY
		assert(s2 < s1);
	}	
	{
		// TEST
		String s1("a");
		String s2("A");

		// VERIFY
		assert(s2 < s1);
	}
	{
		// TEST
		const char s1('a');
		String s2('c');

		// VERIFY
		assert(s1 < s2);
	}	
	{
		// TEST
		const char s1[7] = {'a', 'c', 'c', 'e', 's', 's'};
		String s2("accept");

		// VERIFY
		assert(s2 < s1);
	}	
	{
		// TEST
		const char s1[3] = { 'a', 'a'};
		String s2("aaa");

		// VERIFY
		assert(s1 < s2);
	}
	{
		// TEST
		const char ch = 'a';
		String s('c');

		// VERIFY
		assert(ch < s);
	}
	{
		// TEST
		const char ch = '1';
		String s('9');

		// VERIFY
		assert(ch < s);	
	}
	{
		// TEST
		String lhs("a");
		String rhs("a");

		// VERIFY
		assert(lhs <= rhs);	
	}
	{
		// TEST
		String lhs("abc");
		String rhs("abc");

		// VERIFY
		assert(lhs <= rhs);	
	}
	{
		// TEST
		String lhs("a");
		String rhs("c");

		// VERIFY
		assert(lhs <= rhs);	
	}
	{
		// TEST
		String lhs("a");
		String rhs("c");

		// VERIFY
		assert(lhs != rhs);	
	}
	{
		// TEST
		String lhs("a");
		String rhs(" a");

		// VERIFY
		assert(lhs != rhs);	
	}
	{
		// TEST
		String lhs;
		String rhs("c");

		// VERIFY
		assert(lhs != rhs);	
	}
	{
		// TEST
		String lhs("a b c");
		String rhs("abc");

		// VERIFY
		assert(lhs != rhs);	
	}
	{
		// TEST
		String lhs("access");
		String rhs("accept");

		// VERIFY
		assert(lhs != rhs);	
	}
	{
		// TEST
		String lhs("c");
		String rhs("a");

		// VERIFY 
		assert(lhs >= rhs);
	}
	{
		// TEST
		String lhs("a");
		String rhs("a");

		// VERIFY 
		assert(lhs >= rhs);
	}
	{
		// TEST
		String lhs("abc");
		String rhs("abc");

		// VERIFY 
		assert(lhs >= rhs);
	}
	{
		// TEST
		String lhs("access");
		String rhs("accept");

		// VERIFY 
		assert(lhs >= rhs);
	}
	{
		// TEST
		String lhs("c");
		String rhs("a");
		
		// VERIFY
		assert(lhs > rhs);
	}
	{
		// TEST
		String lhs("c");
		String rhs("a");
		
		// VERIFY
		assert(lhs > rhs);
	}
	{
		// TEST
		String lhs("access");
		String rhs("accept");
		
		// VERIFY
		assert(lhs > rhs);
	}
	{
		// TEST
		String lhs("9");
		String rhs("0");
		
		// VERIFY
		assert(lhs > rhs);
	}

		
	std::cout << "Done testing relational operators." << std::endl;
}

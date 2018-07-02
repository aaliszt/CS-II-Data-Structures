// Aaron Liszt
// TESTS: PoP & Push

#include "string/string.hpp"
#include "stack.hpp"
#include <iostream>

int main(){
	{
		//SETUP
		Stack<int> s;
		s.push(1);

		//TEST
		int i = s.pop();

		//VERIFY
		assert(i == 1);	
	}
	{
		//SETUP
		Stack<int> s;
		s.push(1);
		s.push(2);
		s.push(3);

		//TEST
		int i = s.pop();
		int j = s.pop();
		int k = s.pop();

		//VERIFY
		assert(i == 3);
		assert(j == 2);
		assert(k == 1);	
	}
	{
		//SETUP
		Stack<int> s;
		for(int i = 0; i < 100; ++i)
			s.push(i);

		//TEST
		for(int i = 0; i < 100; ++i){
			int num = s.pop();
			assert(num == 99 - i);
		}
	}
	{
		//SETUP
		Stack<String> s;
		s.push("a");

		//TEST
		String str = s.pop();

		//VERIFY
		assert(str == "a");	
	}
	{
		//SETUP
		Stack<String> s;
		s.push("a");
		s.push("b");
		s.push("c");

		//TEST
		String str1 = s.pop();
		String str2 = s.pop();
		String str3 = s.pop();

		//VERIFY
		assert(str1 == "c");	
		assert(str2 == "b");	
		assert(str3 == "a");
	}	
	{
		//SETUP
		Stack<String> s;
		for(int i = 0; i < 100; ++i)
			s.push("abc123");

		//TEST
		for(int i = 0; i < 100; ++i){
			String str = s.pop();
			assert(str == "abc123");
		}
	}
	{
		//SETUP
		Stack<String> s;
		s.push("a");
		s.push("ab");
		s.push("abc");
		s.push("abcd");
		s.push("abcde");
		s.push("012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");

		//TEST
		String str1 = s.pop();
		String str2 = s.pop();
		String str3 = s.pop();
		String str4 = s.pop();
		String str5 = s.pop();
		String str6 = s.pop();

		//VERIFY
		assert(str6 == "a");	
		assert(str5 == "ab");	
		assert(str4 == "abc");	
		assert(str3 == "abcd");	
		assert(str2 == "abcde");	
		assert(str1 == "012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789");
	}
	std::cout << "Done testing pop." << std::endl;
}

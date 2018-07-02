// Aaron Liszt
// TESTS: Assignmnet operator

#include "stack.hpp"
#include "string/string.hpp"
#include <iostream>

int main(){
	{
		//SETUP
		Stack<int> s1;
		Stack<int> s2;

		//TEST
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());
		s2 = s1;
		assert(s1.isEmpty());
		assert(s2.isEmpty());		
	}
	{
		//SETUP
		Stack<int> s1;
		Stack<int> s2;
		s1.push(1);

		//TEST
		s2 = s1;
		assert(s2.pop() == 1);
		assert(s2.isEmpty());
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());		
	}
	{
		//SETUP
		Stack<int> s1;
		Stack<int> s2;
		s1.push(1);
		s1.push(10);
		s1.push(100);
		s2.push(1);

		//TEST
		s2 = s2;
		assert(s2.pop() == 1);
		assert(s2.isEmpty());
		s2 = s1;
		assert(s2.pop() == 100);
		assert(s2.pop() == 10);
		assert(s2.pop() == 1);
		assert(s2.isEmpty());
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());		
	}
	{
		//SETUP
		Stack<String> s1;
		Stack<String> s2;

		//TEST
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());
		s2 = s1;
		assert(s1.isEmpty());
		assert(s2.isEmpty());				
	}
	{
		//SETUP
		Stack<String> s1;
		Stack<String> s2;
		s1.push("");		
		s2.push("");

		//TEST
		s1 = s2;
		assert(s2.pop() == "");
		assert(s2.isEmpty());
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());				
	}
	{
		//SETUP
		Stack<String> s1;
		Stack<String> s2;
		s1.push("a");
		s1.push("ab");
		s1.push("abc");
		s1.push("abcd");
	
		//TEST
		s2 = s1;
		assert(s2.pop() == "abcd");
		assert(s2.pop() == "abc");
		assert(s2.pop() == "ab");
		assert(s2.pop() == "a");
		assert(s2.isEmpty());
		s2.push("word");
		s2 = s1;
		assert(s2.pop() == "abcd");
		assert(s2.pop() == "abc");
		assert(s2.pop() == "ab");
		assert(s2.pop() == "a");
		assert(s2.isEmpty());
		s1 = s2;
		assert(s1.isEmpty());
		assert(s2.isEmpty());				
	}
	std::cout << "Done testing assignment." << std::endl;
}

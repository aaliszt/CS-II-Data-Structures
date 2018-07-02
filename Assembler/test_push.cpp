// Aaron Liszt
// TESTS: Push & Pop 

#include "string/string.hpp"
#include "stack.hpp"
#include <iostream>

int main(){
	{
		//SETUP
		Stack<int> s;
		
		//TEST
		s.push(1);
	
		//VERIFY
		assert(!s.isEmpty());
		assert(1 == s.pop());	
	}
	{
		//SETUP
		Stack<int> s;
		
		//TEST
		s.push(1);
		s.push(2);
		s.push(3);
	
		//VERIFY
		assert(!s.isEmpty());
		assert(3 == s.pop());	
		assert(2 == s.pop());	
		assert(1 == s.pop());	
	}
	{
		//SETUP
		Stack<String> s;
		
		//TEST
		s.push("");
	
		//VERIFY
		assert(!s.isEmpty());
		assert("" == s.pop());	
	}
	{
		//SETUP
		Stack<String> s;
		
		//TEST
		s.push("a");
	
		//VERIFY
		assert(!s.isEmpty());
		assert("a" == s.pop());	
	}
	{
		//SETUP
		Stack<String> s;
		
		//TEST
		s.push("Stack!");
		s.push(" ");
		s.push("a");
		s.push(" ");
		s.push("am");
		s.push(" ");
		s.push("I");
		s.push(" ");
		s.push("Hi");
	
		//VERIFY
		assert(!s.isEmpty());
		assert("Hi" == s.pop());	
		assert(" " == s.pop());	
		assert("I" == s.pop());	
		assert(" " == s.pop());	
		assert("am" == s.pop());	
		assert(" " == s.pop());	
		assert("a" == s.pop());	
		assert(" " == s.pop());	
		assert("Stack!" == s.pop());	
	}
	{
		//SETUP
		Stack<double> d;
		
		//TEST
		d.push(1.1);
		d.push(1.2);
		d.push(1.3);
		d.push(1.4);
		d.push(1.5);
		d.push(3.1415926535);
	
		//VERIFY
		assert(!d.isEmpty());
		assert(3.1415926535 == d.pop());
		assert(1.5 == d.pop());	
		assert(1.4 == d.pop());	
		assert(1.3 == d.pop());	
		assert(1.2 == d.pop());	
		assert(1.1 == d.pop());		
	}
	{
		//SETUP
		Stack<char> s;
		
		//TEST
		s.push('a');
		s.push('b');
		s.push('x');
		s.push('y');
	
		//VERIFY
		assert(!s.isEmpty());
		assert('y' == s.pop());	
		assert('x' == s.pop());	
		assert('b' == s.pop());	
		assert('a' == s.pop());	
	}
	{
		//SETUP
		Stack<String> s;
		
		//TEST
		s.push("");
		s.pop();
		s.push("");
		s.push("a");
		//VERIFY
		assert(!s.isEmpty());
		assert("a" == s.pop());
		assert("" == s.pop());	
	}
	{
		//SETUP
		Stack<String> s;
		
		//TEST
		s.push("a");
		s.push("b");
		s.push("c");
		s.push("d");
		s.push("e");
		assert(s.pop() == "e");
		assert(s.pop() == "d");
		assert(s.pop() == "c");
		s.push("f");
		s.push("g");
		assert(s.pop() == "g");
	
		//VERIFY
		assert(!s.isEmpty());
		assert("f" == s.pop());
		assert("b" == s.pop());
		assert("a" == s.pop());	
	}
	{
		//SETUP
		Stack<int> s;
		
		//TEST
		s.push(0);
	
		//VERIFY
		assert(!s.isEmpty());
		assert(0 == s.pop());	
	}
	std::cout << "Done testing push." << std::endl;
}

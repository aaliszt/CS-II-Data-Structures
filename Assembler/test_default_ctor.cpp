// AARON LISZT
// TESTS: Default Constructor & IsEmpty

#include "string/string.hpp"
#include "stack.hpp"
#include <iostream>

int main(){
	{
		//TEST
		Stack<int> s;
	
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<String> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<char> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<double> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<bool> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<long> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<float> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	{
		//TEST
		Stack<short> s;
		
		//VERIFY
		assert(s.isEmpty());
	}
	std::cout << "Done testing default constructor." << std::endl;	
}

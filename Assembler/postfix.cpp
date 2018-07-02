// Aaron Liszt
// CS23001
// postfix.cpp
// Description: Reads in infix expressions from a file and converts them to postfix,
// then puts them in an specified output file or displays them to the screen.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "stack.hpp"
#include "string/string.hpp"

//Infix to Postfix
//Converts fully parenthesized infix expressions to postfix expressions
String infixToPostfix(String str){
	
	std::vector<String> vec = str.split(' ');
	Stack<String> stk;
	String right = "";
	String oper = "";
	String left = "";
	for(int i = 0; i < (int)vec.size(); ++i){
		if(vec[i] == ")"){
			right = stk.pop();
			oper = stk.pop();
			left = stk.pop();
			stk.push(left + right + oper);
			right = ""; // Reset the strings to be blank
			left = "";
			oper = "";
		}
		if(vec[i] != "(" && vec[i] != ";" && vec[i] != ")") // Do not push and left or right parenthesis onto the stack
			stk.push(vec[i] + " ");                     // Also ignore the semicolon at the end of the expression
	}
	return stk.pop();
}

int main(int args, char* argv[]){
	if(args != 3 && args != 2){// If there ar not two or three arguments the command line input was invalid
		std::cout << "Error: Invalid input, try \"postfix input output(optional)\", exiting." << std::endl;
		exit(1);
	}
	
	std::ifstream inputFile(argv[1]);
	if(!inputFile.is_open()){
		std::cout << "Input file did not open properly, exiting." << std::endl;
		exit(1);
	}

	if(args == 2){// If no output file is specified output defaults to the screen
		String temp = "";
		String str = "";
		String result = "";
		while(!inputFile.eof()){
			inputFile >> temp;
			if(inputFile.eof()) break;

			if(temp == ";"){ 
				str = str + " ;";
				std::cout << "Infix: " << str << std::endl; // Infix expression
				result = infixToPostfix(str); 
				std::cout << "Postfix: " << result << std::endl << std::endl;  // Postfix expression
				str = ""; 
			}
			else                            // Add the entire line to the string
				str = str + temp + " "; // Add spaces back in so the String can be split
		}
	}
	else{// If there were not two arguments there must be three
		std::ofstream outputFile(argv[2]);
		if(!outputFile.is_open()){
			std::cout << "Output file did not open properly, exiting." << std::endl;
			exit(1);
		}
		
		String temp = "";
		String str = "";
		String result = "";
		while(!inputFile.eof()){
			inputFile >> temp;
			if(inputFile.eof()) break;

			if(temp == ";"){
				str = str + " ;";
				outputFile << "Infix: " << str << std::endl;
				result = infixToPostfix(str);
				outputFile << "Postfix: " << result << std::endl << std::endl;
				str = "";
			}
			else
				str = str + temp + " ";
		}	
	}
	inputFile.close();
	return 0;
}

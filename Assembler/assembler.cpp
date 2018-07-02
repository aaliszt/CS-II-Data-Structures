// Aaron Liszt
// CS23001
// assembler.cpp
// Description: Reads in infix expressions from a file and converts them to postfix,
// then uses that postfix to produce assembly text, finally puts them in an specified 
// output file or displays them to the screen.

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
	for(int i = 0; i < (int)vec.size(); ++i){ // Loop through every token
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

//Evaluate
//Outputs assembly to an ofstream
String evaluate(String L, String t, String R, int num, std::ostream& out){
	char ch = num + '0'; // Converts int to a char
	String result = "TMP" + String(ch); // Result is TMPn

	out << "    LD      " << L << std::endl;

	if(t == "+")					// If token was add "+"
		out << "    AD      " << R << std::endl;
	else if(t == "-")				// If token was subtract "-"
 		out << "    SB      " << R << std::endl;
	else if(t == "*")				// If token was multiply "*"
		out << "    ML      " << R << std::endl;
	else                                            // If token was divide "/"
		out << "    DV      " << R << std::endl;

	out << "    ST      " << result << std::endl;
	return result;	
}

//Postfix to Assembly
//Converts Postfix expressions to assembly
String postfixToAssembly(String str, std::ostream& out){
	std::vector<String> vec = str.split(' ');
	Stack<String> stk;
	String token = "";
	String right = "";
	String left = "";
	int tempNum = 1;

	for(int i = 0; i < (int)vec.size(); ++i){
		token = vec[i];
		if(token != "+" && token != "-" && token != "*" && token != "/")
			stk.push(token);
		else{
			right = stk.pop();
			left = stk.pop();
			stk.push(evaluate(left, token, right, tempNum, out));
			++tempNum;  // Increment tempNum to keep tract of new temporary value
			right = "";
			left = "";
		}
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
				postfixToAssembly(result, std::cout); // Assembly 
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
				postfixToAssembly(result, outputFile);			
				str = "";
			}
			else
				str = str + temp + " ";
		}	
	}
	inputFile.close();
	return 0;
}

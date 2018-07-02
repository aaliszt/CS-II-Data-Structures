/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by: Aaron Liszt
 *
 */

#include "ASTree.hpp"


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    tree = new AST(*(actual.tree));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    src.tree->print(out);
    return out;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::mainHeader(std::vector<std::string>& profileNames) {
    tree->mainHeader(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
//
void srcML::mainReport(std::vector<std::string>& profileNames) {
        tree->mainReport(profileNames);
}

/////////////////////////////////////////////////////////////////////
//  Inserts a filename.count() into each function body.
//
void srcML::funcCount(const std::string& profilename) {
    tree->funcCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Inserts a filename.count() for each statement.
//
void srcML::lineCount(const std::string& profilename) {
    tree->lineCount(profilename);
}

/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}

/////////////////////////////////////////////////////////////////////
/// Destructor for AST
///
AST::~AST(){
	for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i)
		delete *i;
}

/////////////////////////////////////////////////////////////////////
// Copy Constructor for AST
//
AST::AST(const AST& actual) {
	text = actual.text;
	tag = actual.tag;
	closeTag = actual.closeTag;
	nodeType = actual.nodeType;
	for (std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i) 
			child.push_back(new AST(*(*i)));
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for AST
//
void AST::swap(AST& rhs) {
	std::string tempTxt = rhs.text;
	rhs.text = text;
	text = tempTxt;

	std::string tempTag = rhs.tag;
	rhs.tag = tag;
	tag = tempTag;

	std::string tempC = rhs.closeTag;
	rhs.closeTag = closeTag;
	closeTag = tempC;

	nodes tempN = rhs.nodeType;
	rhs.nodeType = nodeType;
	nodeType = tempN;

	std::list<AST*> temp = child;
	child = rhs.child;
	rhs.child = temp;
}

/////////////////////////////////////////////////////////////////////
// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Returns a pointer to child[i] where (child[i]->tag == tagName)
//
// IMPORTANT for part 3
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}

/////////////////////////////////////////////////////////////////////
// Returns the full name of a <name> node.
//
// IMPORTANT for part 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables in a main file.
//
void AST::mainHeader(std::vector<std::string>& profileNames) {
	for(std::list<AST*>::iterator it = child.begin(); it != child.end(); ++it){
		if((*it)->tag == "function"){// When we find the first function tag stop and insert code
			child.insert(it, new AST(token, "\n"));
			child.insert(it, new AST(token, "#include \"profile.hpp\"\n")); // Add include derective

			for(int i = 0; i < (int)profileNames.size(); ++i){// Go through filenames and insert code to create profile objects
				std::string filename = profileNames[i];
	
				for(int j = 0; j < (int)filename.size(); ++j){// Replace _ with . in filenames
					if(filename[j] == '_' && filename[j+1] == 'c')
						filename[j] = '.';
				}
				child.insert(it, new AST(token, "profile " + profileNames[i] + "(\"" + filename + "\");" + "\n"));
			}
			child.insert(it, new AST(token, "\n"));
			break;// Leave the loop after we insert the code(stops multiple insertion)
		}
	}
}

/////////////////////////////////////////////////////////////////////
//  Adds in the includes and profile variables for non-main files
//
void AST::fileHeader(const std::string& profileName) {
	for(std::list<AST*>::iterator it = child.begin(); it != child.end(); ++it){
		if((*it)->tag == "function"){
			child.insert(it, new AST(token, "\n"));
			child.insert(it, new AST(token, "#include \"profile.hpp\"\n")); // Add include derective
			child.insert(it, new AST(token, "extern profile " + profileName + ";" + "\n"));// Add extern statement
			child.insert(it, new AST(token, "\n"));
			break;//Leave loop after inserting code
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Adds in the report to the main.
// Assumes only one return at end of main body.
//
void AST::mainReport(std::vector<std::string>& profileNames) {
	for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i){
		if((*i)->tag == "function" && (*i)->getChild("name")->getName() == "main"){ // If we reach a function named main 
			AST* main = (*i)->getChild("block");
			std::list<AST*>::iterator it = main->getChild("return")->child.begin(); // Put an iterator at the front of the return block in main
			for(int n = 0; n < (int)profileNames.size(); ++n)
				child.insert(it, new AST(token, "std::cout << " + profileNames[n] + " << std::endl;\n    "));
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each function is executed.
//  Assumes no nested functions.
//
void AST::funcCount(const std::string& profileName) {
	for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i){
		if((*i)->tag == "function" || (*i)->tag == "constructor" || (*i)->tag == "destructor"){ // If we reach a function, constructor, or destructor we must add code 
			std::string funcName = (*i)->getChild("name")->getName(); // Get function name
			AST* body = (*i)->getChild("block"); // Get a pointer to the main block of the function
			std::list<AST*>::iterator it = body->child.begin(); // Put an iterator at the start of the main block
			child.insert(++it, new AST(token, " " + profileName + ".count(__LINE__, \"" + funcName + "\");"));
		}
	}
}

/////////////////////////////////////////////////////////////////////
// Adds in a line to count the number of times each statement is executed.
//   No breaks, returns, throw etc.
//   Assumes all construts (for, while, if) have { }.
//
void AST::lineCount(const std::string& profileName) {    
    // Recursively check for expr_stmt
	for(std::list<AST*>::iterator i = child.begin(); i != child.end(); ++i){
		if((*i)->tag == "expr_stmt"){ // When we reach an expression statment we must insert
			std::list<AST*>::iterator it = i; // Copy iterator i to prevent double insertion
			child.insert(++it, new AST(token, " " + profileName + ".count(__LINE__);"));
		}
		else // If we are not at an expression statment continue recursing
			(*i)->lineCount(profileName);
	}
}

/////////////////////////////////////////////////////////////////////
// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end(); ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}

/////////////////////////////////////////////////////////////////////
// Print an AST 
// REQUIRES: indent >= 0
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin();
         i != child.end(); ++i) {
        switch ((*i)->nodeType) {
            case category:
                (*i)->print(out);
                break;
            case token:
                out << (*i)->text;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    return out;
}

    
    
    

/////////////////////////////////////////////////////////////////////
// Utilities
//

// IMPORTANT for part 3
bool isStopTag(std::string tag) {
    if (tag == "decl_stmt"            ) return true;
    if (tag == "argument_list"        ) return true;
    if (tag == "init"                 ) return true;
    if (tag == "condition"            ) return true;
    if (tag == "cpp:include"          ) return true;
    if (tag == "macro"                ) return true;
    if (tag == "comment type\"block\"") return true;
    if (tag == "comment type\"line\"" ) return true;
    return false;
}

//For reading

/////////////////////////////////////////////////////////////////////
// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
//
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">");}
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<");}
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&");}
    return s;
}

/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}

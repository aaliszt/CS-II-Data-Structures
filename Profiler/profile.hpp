/*
 *  profile.hpp
 *
 *  Created by Jonathan Maletic.
 *  Copyright 2016 Kent State University. All rights reserved.
 *
 *  Modified by: Aaron Liszt
 *
 */

#ifndef INCLUDES_PROFILE_H_
#define INCLUDES_PROFILE_H_

#include <iostream>
#include <cassert>
#include <string>
#include <map>

std::string intToString(int);

////////////////////////////////////////////////////////////////////////
//  A map of line numbers or line number function names and the number
//   of times each was called.
// 
//
class profile {
public:
           profile (std::string fn="") : fname(fn)               {};
    void   count   (const int line, const std::string& funcName) { stmt[intToString(line) + "\tFunction:\t" + funcName + "\t"] += 1; }
    void   count   (const int line)                              { stmt[intToString(line) + "\tFunction:\tNONE                \t"] += 1; }
    friend std::ostream& operator<< (std::ostream&, const profile&);
private:
    std::string                 fname;
    std::map<std::string, int>  stmt;    // (line# X times called)
};


#endif

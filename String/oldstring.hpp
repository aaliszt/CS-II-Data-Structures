// Aaron Liszt
// CS 23001
// string.hpp
// Interface definition of String class

#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

const int STRING_CAPACITY = 256;

class String {
public:
    String        ();
    String        (char);
    String        (const char[]);
    
    String  substr        (int, int)                const;
    bool    findstr       (const String&)	    const;
    bool    findchar      (const char&)             const;
    char&   operator[]    (int);
    char    operator[]    (int)                     const;
    int     capacity      ()                        const;
    int     length        ()                        const;
    bool    operator==    (const String&)           const;
    bool    operator<     (const String&)           const;
    String  operator+     (const String&)           const;

    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    char str[STRING_CAPACITY];
};


String  operator+       (const char[],  const String&);
String  operator+       (char,          const String&);
bool    operator==      (const char[],  const String&);
bool    operator==      (char,          const String&);
bool    operator<       (const char[],  const String&);
bool    operator<       (char,          const String&);
bool    operator<=      (const String&, const String&);
bool    operator!=      (const String&, const String&);
bool    operator>=      (const String&, const String&);
bool    operator>       (const String&, const String&);

#endif


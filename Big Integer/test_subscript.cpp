// bigint Test Program
//
// Tests:  subscript, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(4000);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 4000);
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi;

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 0);
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("12351345324");

        // Test 
        int digit = bi[10];

        // Verify
        assert(bi    == "12351345324");
        assert(digit == 1);
    }
    {
        // Setup
        bigint bi("1238345837");

        // Test 
        int digit = bi[6];

        // Verify
        assert(bi    == "1238345837");  //Wrong.  Add test cases.
        assert(digit == 8);
    }
    
    //Add test cases!!

    std::cout << "Done testing subscript." << std::endl;
}


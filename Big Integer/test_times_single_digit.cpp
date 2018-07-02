// bigint Test Program
//
// Tests:  times_10, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("1235134523435");

        // Test 
        bi = bi.timesDigit(0);

        // Verify
        assert(bi == 0);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(2345256);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 2345256);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(25);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 50);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(36);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 324);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(25000);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 50000);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(2354123);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 21187107);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(9);

        // Test 
        bi = bi.timesDigit(9);

        // Verify
        assert(bi == 81);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("124356798");

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == "248713596");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("999999999");

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == "4999999995");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("126372839384657");

        // Test 
        bi = bi.timesDigit(8);

        // Verify
        assert(bi == "1010982715077256");
    }


    //Add test cases as needed.
    
    std::cout << "Done testing bigint * single digit" << std::endl;

}

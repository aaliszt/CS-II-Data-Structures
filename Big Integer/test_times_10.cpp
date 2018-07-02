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
        bigint bi(3);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == 3);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == 30);
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times10(25);

        // Verify
        assert(bi == "10000000000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(200);

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "2000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12345);

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "123450000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("12345678910");

        // Test 
        bi = bi.times10(50);

        // Verify
        assert(bi == "1234567891000000000000000000000000000000000000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(0);

        // Test 
        bi = bi.times10(0);

        // Verify
        assert(bi == "0");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("102039492349");

        // Test 
        bi = bi.times10(1);

        // Verify
        assert(bi == "1020394923490");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(555);

        // Test 
        bi = bi.times10(25);

        // Verify
        assert(bi == "5550000000000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times10(80);

        // Verify
        assert(bi == "100000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(1);

        // Test 
        bi = bi.times10(199);

        // Verify
        assert(bi == "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(12345);

        // Test 
        bi = bi.times10(10);

        // Verify
        assert(bi == "123450000000000");
    }
    
    //Add test cases as needed.

    std::cout << "Done testing times10" << std::endl;
}


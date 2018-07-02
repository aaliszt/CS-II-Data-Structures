// bigint Test Program
//
// Tests:  int constructor, uses ==
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(9);
      bigint right(9);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 9);
      assert(result == 18);
    }
    {
      //------------------------------------------------------
      // Setup
      bigint left(19);
      bigint right(19);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 19);
      assert(right  == 19);
      assert(result == 38);
    }
    {
      //------------------------------------------------------
      // Setup
      bigint left(199);
      bigint right(199);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left ==  199);
      assert(right  == 199);
      assert(result == 398);
    }
    {
      //------------------------------------------------------
      // Setup
      bigint left(11111);
      bigint right("99999999999999999999999999999999999999999999999999");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 11111);
      assert(right == "99999999999999999999999999999999999999999999999999");
      assert(result == "100000000000000000000000000000000000000000000011110");
    }
    {
      //------------------------------------------------------
      // Setup
      bigint left("1879465321012279853475324858234852345723845823458");
      bigint right("123514959195931495934959234959293459923459923495");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left == "1879465321012279853475324858234852345723845823458");
      assert(right == "123514959195931495934959234959293459923459923495");
      assert(result == "2002980280208211349410284093194145805647305746953");
    }
    {
      //------------------------------------------------------
      // Setup
      bigint left("6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666");
      bigint right("55555555555555555555555555555555555555555555555555");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left ==   "6666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666");
      assert(right ==  "55555555555555555555555555555555555555555555555555");
      assert(result == "6666666666666666666666666666666666666666666666666722222222222222222222222222222222222222222222222221");
    }

    //Add test cases as needed.
    
    std::cout << "Done with testing addition." << std::endl;
}


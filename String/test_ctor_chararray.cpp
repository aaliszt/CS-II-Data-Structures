// Aaron Liszt
// TEST: Char array constructor

#include "string.hpp"
#include <iostream>
#include <cassert>

int main(){
	{
		// SETUP
		const char s[1] = { '\0' };
		
		// TEST
		String str(s);

		// VERIFY
		assert(str == '\0');
	}
	{
		// SETUP
		
		// TEST
		String str("a");

		// VERIFY
		assert(str == "a");
		std::cout << "a == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("abc");

		// VERIFY
		assert(str == "abc");
		std::cout << "abc == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("abc123");
		
		// VERIFY
		assert(str == "abc123");
		std::cout << "abc123 == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("abcdefghijklmnopqrstuvwxyz12345678910");
		
		// VERIFY
		assert(str == "abcdefghijklmnopqrstuvwxyz12345678910");
		std::cout << "abcdefghijklmnopqrstuvwxyz12345678910 == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("I don't like Strings.");
		
		// VERIFY
		assert(str == "I don't like Strings.");
		std::cout << "I dont't like Strings. == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("A          A");
		
		// VERIFY
		assert(str == "A          A");
		std::cout << "A          A == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("          ");
		
		// VERIFY
		assert(str == "          ");
	}
	{
		// SETUP
		
		// TEST
		String str("DAMN DANIEL - BACK AT IT AGAIN WITH THE WHITE VANS");
		
		// VERIFY
		assert(str == "DAMN DANIEL - BACK AT IT AGAIN WITH THE WHITE VANS");
		std::cout << "DAMN DANIEL - BACK AT IT AGAIN WITH THE WHITE VANS  == " << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA");
		
		// VERIFY
		assert(str == "HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA");
		std::cout << "HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHA == " << std::endl << str << std::endl;
	}
	{
		// SETUP
		
		// TEST
		String str("156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Character");
		// VERIFY
		assert(str == "156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Characters!!!156Character");
		
	}
	{
		// SETUP
		
		// TEST
		String str("microprogrammingmissapropriatingmarginalizationsmasculinizationsmicrocrystallineminiaturizationsmultiprogrammingnewsworthinessesnoncommunicatingnondeterministicnoninstitutionalintramolecularlyinterhemeshpericinterjectionallyintermidiatenessinterconnection");
		// VERIFY
		assert(str == "microprogrammingmissapropriatingmarginalizationsmasculinizationsmicrocrystallineminiaturizationsmultiprogrammingnewsworthinessesnoncommunicatingnondeterministicnoninstitutionalintramolecularlyinterhemeshpericinterjectionallyintermidiatenessinterconnection");

	}

	std::cout << "Done testing char array ctor." << std::endl;
}

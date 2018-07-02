###############################################################
# String & Oracle
#
# CS II Kent State University
# Make file for string class and testing oracle 
# J. Maletic 2016
#
#

###############################################################
# Variables
CPP     = clang++
OPTIONS = -g -Wall -W -Wunused -Wuninitialized -Wshadow -std=c++11


# Names of your test files - add them in as you build them.
# Names must start with "test_"
MYTESTS = test_default_ctor test_ctor_chararray test_ctor_char test_subscript test_equal test_length test_relationaloperators test_substring test_find test_add test_resize test_input test_cap_ctor test_ctor_charcap test_split

# Names of test oracle files 
CTOR = testoracle_ctor_default testoracle_ctor_int testoracle_ctor_char testoracle_ctor_charArray_int testoracle_ctor_charArray
REL  = testoracle_equal testoracle_lessThan
COPY = testoracle_ctor_copy testoracle_assign
OPS  = testoracle_concat
SUPER = testoracle_assign_resize testoracle_copy_resize testoracle_reset_capacity testoracle_concat_resize testoracle_input

###############################################################
# Compile just the string
# Compile and run all provided test oracles on string
# Compile and run all your tests on string
# Compile and run the project
msg:
	@echo 'Targets are:'
	@echo '  string'
	@echo '  oracle'
	@echo '  tests'
	@echo '  logview'
	@echo '  clean'



###############################################################
# Compile string 
#
string.o: string.hpp string.cpp
	$(CPP) -c $(OPTIONS) string.cpp -o string.o

string: string.o
	

###############################################################
# Run all of your tests
# 
# You will need to ADD your other below:
# For example: ./test_plus
#
tests: $(MYTESTS)
	./test_default_ctor
	./test_ctor_char
	./test_ctor_chararray
	./test_subscript
	./test_equal
	./test_length
	./test_relationaloperators
	./test_add
	./test_resize
	./test_input
	./test_substring
	./test_find
	./test_cap_ctor
	./test_ctor_charcap
	./test_split    
    
    
###############################################################
# Compile all test programs
#
test_%: string.o test_%.o
	$(CPP) string.o test_$*.o -o test_$*

test_%.o: string.hpp test_%.cpp
	$(CPP) $(OPTIONS) -c test_$*.cpp



###############################################################
# Run test oracle
# Comment out one's you don't want.
#
oracle: $(CTOR) $(REL) $(COPY) $(OPS) $(SUPER)
	./testoracle_ctor_default
	./testoracle_ctor_int
	./testoracle_ctor_char 
	./testoracle_ctor_charArray
	./testoracle_ctor_charArray_int 
	./testoracle_equal 
	./testoracle_lessThan
	./testoracle_ctor_copy 
	./testoracle_assign
	./testoracle_concat
	./testoracle_assign_resize
	./testoracle_copy_resize
	./testoracle_reset_capacity
	./testoracle_concat_resize
	./testoracle_input
    

###############################################################
# Compile all test programs
#
testoracle_%: string.o testoracles/testoracle_%.o
	$(CPP) string.o testoracles/testoracle_$*.o -o testoracle_$*
    



###############################################################
# Compile Project 
#

logview.o: logview.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logview.cpp -o logview.o
    
logentry.o: logentry.cpp logentry.hpp string.hpp
	$(CPP) -c $(OPTIONS) logentry.cpp -o logentry.o

logview: logview.o string.o logentry.o 
	$(CPP) $(OPTIONS) logview.o string.o logentry.o -o logview


###############################################################
# clean 
# Removes all .o files and all executables
#
clean:
	rm -f *.o
	rm -f $(CTOR) $(REL) $(COPY) $(OPS)
	rm -f $(MYTESTS)
	rm -f logview



CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: LinearProbingTest.cpp
	echo     ------------compiling LinearProbingTest.ccp to create executable program hash1----------------
	g++ $(CXXFLAGS)  -ggdb  LinearProbingTest.cpp   -o   linear
clean:
	echo ----------------removing executable program linear--------------------
	/bin/rm linear

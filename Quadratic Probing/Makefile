CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: QuadraticProbingTest.cpp
	echo     ------------compiling QuadraticProbingTest.ccp to create executable program hash1----------------
	g++ $(CXXFLAGS)  -ggdb  QuadraticProbingTest.cpp   -o   quadratic
clean:
	echo ----------------removing executable program quadratic--------------------
	/bin/rm quadratic

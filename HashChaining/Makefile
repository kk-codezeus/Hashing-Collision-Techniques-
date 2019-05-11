CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: HashChainingTest.cpp
	echo     ------------compiling HashChainingTest.ccp to create executable program hash1----------------
	g++ $(CXXFLAGS)  -ggdb  HashChainingTest.cpp   -o   hashchain
clean:
	echo ----------------removing executable program hashchain--------------------
	/bin/rm hashchain

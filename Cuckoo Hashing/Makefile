CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

main: CuckooHashingTest.cpp
	echo     ------------compiling CuckooHashingTest.ccp to create executable program hash1----------------
	g++ $(CXXFLAGS)  -ggdb  CuckooHashingTest.cpp   -o   cuckoo
clean:
	echo ----------------removing executable program cuckoo--------------------
	/bin/rm cuckoo

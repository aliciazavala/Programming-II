lab10: main.o Executive.o Pokemon.o 
	g++ -std=c++11 -g -Wall main.o Executive.o Pokemon.o -o lab10

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

Executive.o: Executive.h Executive.cpp Pokemon.h BinarySearchTree.h BinarySearchTree.cpp BNode.h BNode.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab10

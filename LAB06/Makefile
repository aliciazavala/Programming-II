lab6: main.o Executive.o Matrix.o
	g++ -std=c++11 -g -Wall main.o Executive.o Matrix.o -o lab6

main.o: main.cpp Executive.h Matrix.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp 

Matrix.o: Matrix.h Matrix.cpp	
	g++ -std=c++11 -g -Wall -c Matrix.cpp 

clean: 
	rm *.o lab6
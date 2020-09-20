lab5: main.o Executive.o Function.o Command.o PrecondViolatedExcep.o
	g++ -g -std=c++11 -Wall main.o Executive.o Function.o Command.o PrecondViolatedExcep.o -o lab5

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Function.h Command.h Queue.h Queue.cpp QueueInterface.h Stack.h Stack.cpp StackInterface.h LinkedList.h LinkedList.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

Function.o: Function.h Function.cpp
	g++ -g -std=c++11 -Wall -c Function.cpp

Command.o: Command.h Command.cpp
	g++ -g -std=c++11 -Wall -c Command.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -g -std=c++11 -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o lab5

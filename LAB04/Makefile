lab04: main.o Executive.o Student.o PrecondViolatedExcep.o
	g++ -g -std=c++11 -Wall main.o Executive.o Student.o PrecondViolatedExcep.o -o lab04

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Student.h LinkedList.h LinkedList.cpp ListInterface.h SLNode.h PrecondViolatedExcep.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Student.o: Student.h Student.cpp 
	g++ -g -std=c++11 -Wall -c Student.cpp

PrecondViolatedExcep.h: PrecondViolatedExcep.h PrecondViolatedExcep.cpp 
	g++ -g -std=c++11 -Wall -c PrecondViolatedExcep.cpp 
clean:
	rm *.o lab04
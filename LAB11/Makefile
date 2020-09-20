lab11: main.o Executive.o Staff.o 
	g++ -std=c++11 -g -Wall main.o Executive.o Staff.o -o lab11

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Heap.h Heap.cpp PriorityQueue.h PriorityQueue.cpp EmptyHeap.h EmptyPriorityQueue.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

Staff.o: Staff.h Staff.cpp
	g++ -std=c++11 -g -Wall -c Staff.cpp
clean:
	rm *.o lab11

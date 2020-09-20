lab9: main.o Executive.o
	g++ -std=c++11 -g -Wall main.o Executive.o -o lab9

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp bubbleSort.h insertionSort.h mergeSort.h quickSort.h selectionSort.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab9

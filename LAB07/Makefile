lab7: main.o ElectricField.o 
	g++ -std=c++11 -g -Wall main.o ElectricField.o -o lab7

main.o: main.cpp ElectricField.h 
	g++ -std=c++11 -g -Wall -c main.cpp

ElectricField.o: ElectricField.h ElectricField.cpp
	g++ -std=c++11 -g -Wall -c ElectricField.cpp 

clean: 
	rm *.o lab7
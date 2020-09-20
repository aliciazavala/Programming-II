lab2: main.o Executive.o Employee.o Manager.o
	g++ -std=c++11 -g -Wall main.o Executive.o Employee.o Manager.o -o lab2

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Manager.h Employee.h Map.h Map.cpp 
	g++ -std=c++11 -g -Wall -c Executive.cpp 

Employee.o: Employee.h Employee.cpp
	g++ -std=c++11 -g -Wall -c Employee.cpp 
	
Manager.o: Manager.h Manager.cpp Employee.h
	g++ -std=c++11 -g -Wall -c Manager.cpp 
clean: 
	rm *.o lab2
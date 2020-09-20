Fantasy: main.o Player.o Menu.o Executive.o
	g++ -std=c++11 -g -Wall main.o Player.o Menu.o Executive.o -o Fantasy

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Menu.h Player.h 
	g++ -std=c++11 -g -Wall -c Executive.cpp 

Menu.o: Menu.h Menu.cpp Player.h
	g++ -std=c++11 -g -Wall -c Menu.cpp 

Player.o: Player.h Player.cpp
	g++ -std=c++11 -g -Wall -c Player.cpp 

clean: 
	rm *.o Fantasy
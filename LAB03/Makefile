lab03: main.o Executive.o Circle.o Rectangle.o Triangle.o ShapeContainer.o 
	g++ -g -std=c++11 -Wall main.o Executive.o Circle.o Rectangle.o Triangle.o ShapeContainer.o -o lab03

main.o: main.cpp Executive.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Triangle.o Circle.o Rectangle.o ShapeContainer.o
	g++ -g -std=c++11 -Wall -c Executive.cpp

Circle.o: Circle.h Circle.cpp Shape.h
	g++ -g -std=c++11 -Wall -c Circle.cpp

Triangle.o: Triangle.h Triangle.cpp Shape.h
	g++ -g -std=c++11 -Wall -c Triangle.cpp

Rectangle.o: Rectangle.h Rectangle.cpp Shape.h
	g++ -g -std=c++11 -Wall -c Rectangle.cpp

ShapeContainer.o: ShapeContainer.h ShapeContainer.cpp Shape.h Triangle.h Rectangle.h Circle.h
	g++ -g -std=c++11 -Wall -c ShapeContainer.cpp

clean:
	rm *.o lab03

blob: main.o BlobFinder.o BlobReader.o
	g++ -std=c++11 -g -Wall main.o BlobFinder.o BlobReader.o -o blob

main.o: main.cpp BlobFinder.h 
	g++ -std=c++11 -g -Wall -c main.cpp

BlobFinder.o: BlobFinder.h BlobFinder.cpp
	g++ -std=c++11 -g -Wall -c BlobFinder.cpp 

BlobReader.o: BlobReader.h BlobReader.cpp
	g++ -std=c++11 -g -Wall -c BlobReader.cpp 

clean: 
	rm *.o blob
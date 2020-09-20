/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef Executive_h
#define Executive_h
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "ShapeContainer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Executive{
	private:
		int totalShapes;
		ifstream inFile;
		int index;
		Shape* temp;

	public:
		Executive(string filename);
		void run();
		~Executive();

};
#endif



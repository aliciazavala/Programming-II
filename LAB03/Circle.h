/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef Circle_h
#define Circle_h
#include "Shape.h"
#include <string>
#include <iostream>

class Circle: public Shape{
	private:
		double m_radius;
	public:
		Circle(double radius);
		string shapeName()const;
		double area()const;
		~Circle();
};
#endif

/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef Rectangle_h
#define Rectangle_h
#include "Shape.h"
#include <string>

class Rectangle: public Shape{
	private:
		double m_length;
		double m_width;

	public:
		Rectangle(double l, double w);
		string shapeName()const;
		double area()const;
		~Rectangle();
};
#endif

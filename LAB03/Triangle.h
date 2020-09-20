/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef Triangle_h
#define Triangle_h
#include "Shape.h"
#include <string>

class Triangle: public Shape{
	private:
		double m_base;
		double m_height;
	public:
		Triangle(double base, double height);
		string shapeName()const;
		virtual double area()const;
		~Triangle();

};
#endif

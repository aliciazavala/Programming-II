/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#include "Shape.h"
#include "Circle.h"
#include <iostream>
#include <string>

using namespace std;

Circle::Circle(double radius){
    m_radius = radius;
}

string Circle::shapeName()const{
    return("Circle");
}

double Circle::area()const{
    return((3.141592)*(m_radius*m_radius));
}
Circle::~Circle(){
}

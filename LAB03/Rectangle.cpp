/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#include "Shape.h"
#include "Rectangle.h"
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle(double l, double w){
    m_length = l;
    m_width = w;
}

string Rectangle::shapeName()const{
    return("Rectangle");
}

double Rectangle::area()const{
    return(m_length*m_width);
}
Rectangle::~Rectangle(){
}
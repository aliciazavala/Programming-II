/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#include "Triangle.h"
#include "Shape.h"
#include <iostream>
#include <string>

using namespace std;

Triangle::Triangle(double base, double height){
    m_base = base;
    m_height = height;
}

string Triangle::shapeName()const{
    return("Triangle");
}

double Triangle::area()const {
    return(0.5*m_base*m_height);
}
Triangle::~Triangle(){
}
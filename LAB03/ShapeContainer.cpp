/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#include "ShapeContainer.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;

ShapeContainer::ShapeContainer(int size){ //initialize pointers in m_arrayOfShapes to nullptr
    m_size = size;
    m_arrayOfShapes= new Shape*[m_size];
    for (int i = 0; i<m_size; i++){
         m_arrayOfShapes[i] = nullptr;
    }
}

double ShapeContainer::area(int index) const{//throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr 
    if(index<0 || index>m_size || m_arrayOfShapes[index] == nullptr){
        throw runtime_error("Invalid index.");
    }
    else{
        return(m_arrayOfShapes[index]->area());//returns area if valid input
    }
}

string ShapeContainer::shapeName(int index) const{ //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr
    if(index<0 || index>m_size || m_arrayOfShapes[index]==nullptr){ 
        throw runtime_error("Does not exist.");
    }
    else{   
        return(m_arrayOfShapes[index]->shapeName());//returns shapename if valid input
    }
}

void ShapeContainer::add(Shape* shapePtr, int index){ //throws a std::runtime_error if index is invalid OR if shapePtr is nullptr
    if(index<0 || index>m_size || shapePtr == nullptr){
        throw runtime_error("Error. Invalid index to add shape.\n");
    }
    else{   
        m_arrayOfShapes[index] = shapePtr;//adds shape to array if valid input
    }
}
void ShapeContainer::remove(int index){ //throws a std::runtime_error if the index is invalid OR there is no object to delete
    if(index<0 || index>m_size ||m_arrayOfShapes[index]==nullptr){ 
        throw runtime_error("Invalid index to delete.");
    }
    else{   
        m_arrayOfShapes[index] = nullptr;//removes shape if valid input
    }
}

ShapeContainer::~ShapeContainer(){
    delete[] m_arrayOfShapes;
}

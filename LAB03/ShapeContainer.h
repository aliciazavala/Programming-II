/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef ShapeContainer_h
#define ShapeContainer_h
#include "Shape.h"
#include <stdexcept>
#include <string>
using namespace std;

class ShapeContainer
{
   private:
      Shape** m_arrayOfShapes;
      int m_size;

   public:
      ShapeContainer(int size); //initialize pointers in m_arrayOfShapes to nullptr
      ~ShapeContainer();
      double area(int index) const; //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr 
      string shapeName(int index) const; //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr
      void add(Shape* shapePtr, int index); //throws a std::runtime_error if index is invalid OR if shapePtr is nullptr
      void remove(int index); //throws a std::runtime_error if the index is invalid OR there is no object to delete
   
};
#endif
/*
Lab 03
Name: Alicia M. Zavala F.
Date: 09/26
KU ID: 2951680
Descripton
*/
#ifndef Shape_h
#define Shape_h
#include <string>
using namespace std;

class Shape
{
   public:
   virtual double area() const = 0;
   virtual string shapeName() const = 0;
   virtual ~Shape() {};
};
#endif


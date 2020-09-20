/*
* @author Alicia Zavala
* @date
* @file main.cpp
* @brief
*/
#include "Executive.h"
#include <iostream>

using namespace std;

int main(int argc, char* agrv[])
{
  if(argc<2)
  {
      cout<<"Incorrect number of parameters!\n";
  }
  else
  {
    Executive exec(agrv[1]);
  }
}

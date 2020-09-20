/*
* @author Alicia Zavala
* @date
* @file main.cpp
* @brief
*/
#include "Executive.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  if(argc<2)
  {
      cout<<"Incorrect number of parameters!\n";
  }
  else
  {
    Executive exec(argv[1]);
  }
}

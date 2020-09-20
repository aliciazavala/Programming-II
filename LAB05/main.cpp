/*
*@author Alicia Zavala
*@date
*@file Main
*/

#include "Executive.h"
#include <iostream>
#include <string>

int main(int argc,char* argv[])
{
  if(argc<2)
  {
    std::cout<<"Invalid number of files!!";
  }
  else
  {
    Executive exec(argv[1]);
  }

}

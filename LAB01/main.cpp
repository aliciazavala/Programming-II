/*
Lab 01
Name: Alicia M. Zavala F.
KU ID: 2951680
*/
#include "Executive.h"
#include<iostream>

int main(int argc, char* argv[]){
  if(argc < 2){
    cout << "Incorrect number of parameters!\n";
  }
  else
  {
     Executive exec(argv[1]);
     exec.run(); 
  }

  return(0);
}

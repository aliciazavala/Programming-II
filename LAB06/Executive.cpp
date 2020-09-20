#include "Executive.h"
#include "Matrix.h"

#include <iostream>
#include <fstream>
using namespace std;

Executive::Executive(string filename)
{
  inFile.open(filename);
  int n = 0;
  while (inFile >> n)
  {
  	Matrix M(inFile, n);
    M.Print();
  	double determinant = M.det(M);
    cout<<"This Matrix determinant is: "<<determinant<<"\n\n";
    M.clearArray(M);
  }
}

Executive::~Executive()
{

}

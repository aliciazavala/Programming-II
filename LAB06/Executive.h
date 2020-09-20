/*
*@author Alicia Zavala
*@date
*@file Executive.h
*@brief
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Matrix.h"

#include <iostream>
#include <fstream>
using namespace std;

class Executive
{

private:
  ifstream inFile;

public:
  /*
  * @pre
  * @post
  * @return
  */
  Executive(string filename);
  /*
  * @pre
  * @post
  * @return
  */
  ~Executive();

};

#endif

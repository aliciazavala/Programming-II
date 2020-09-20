/*
*@author Alicia Zavala
*@date
*@file Executive.h
*@brief
*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Stack.h"
#include "Queue.h"
#include "Function.h"
#include "Command.h"
#include "LinkedList.h"

#include <fstream>
using namespace std;

class Executive
{
  private:
    ifstream inFile;

  public:
    Executive(string filename);
    void run();
};

#endif

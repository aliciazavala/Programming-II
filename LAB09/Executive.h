/*
* @author Alicia Zavala
* @date 11/07/2019
* @file Executive.h
* @brief creates array in order given by user, sorts it, and prints time it took to sort
*/
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "selectionSort.h"

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <ctime> //or <time.h>
#include <stdlib.h>//random

using namespace std;

class Executive
{

private:
  int dataSize = 0;
  string startOrder;
  double* arrayS = nullptr;

public:
  /*
  * @pre data Size, starting order, sort method
  * @post initializes values, calls method to create double array size dataS with starting order, calls sort method
  * @return
  */
  Executive(int dataS, string order, string sort);
  /*
  * @pre starting order type
  * @post creates double array with starting order type
  * @return
  */
  void generateArray(string orderType);
  /*
  * @pre sort method to call
  * @post sorts array with given sorting method by user
  * @return
  */
  void sortArray(string sortType);
  /*
  * @pre
  * @post deletes items located in the heap
  * @return
  */
  ~Executive();
};
#endif


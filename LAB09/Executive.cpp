/*
* @author Alicia Zavala
* @date  11/07/2019
* @file Executive.cpp
* @brief definition of all functions from .h file. 
*/
#include "Executive.h"

#include <ctime>
#include <stdlib.h>
using namespace std;

Executive::Executive(int dataS, string order, string sort)
{
  srand48((unsigned int)time(NULL));
  //size
  dataSize = dataS;
  //generate an array
  generateArray(order);
  //sort
  sortArray(sort);

}

void Executive::generateArray(string orderType)
{
  arrayS = new double[dataSize];
  double x = 0;
  if(orderType == "random")
  {

    startOrder = "random";
    for(int i = 0; i < dataSize; i++)
    {
      x = drand48() * 100000;
      arrayS[i] = x;
    }
    //set each element of the array to a unique random number, x, in the range 0.0 ≤ x ≤ 100000.0.
    //use the drand48 in <stdlib.h> also call srand48 with a constant at the start of your program to make sure you get the same sequence of random numbers each time.
  }
  else if(orderType == "ascending")
  {
    startOrder = "sorted";
    for(int i = 0; i < dataSize; i++)
    {
      arrayS[i] = 0.001*static_cast<double>(i);
    }
  }
  else if(orderType == "descending")
  {
    startOrder = "reverse sorted";
    for(int i = 0; i < dataSize; i++)
    {
      arrayS[i] = 0.001*static_cast<double>(dataSize - i - 1);
    }
  }
}

void Executive::sortArray(string sortType)
{
  cout<< "Size of the array: "<< dataSize << "\nInitial array condition: "<<startOrder<<"\nTotal time taken to sort: ";
  if(sortType == "selection")
  {
    const clock_t begin = clock();
    selectionSort(arrayS, dataSize);
    const clock_t end = clock();
    cout<< float (end - begin) / CLOCKS_PER_SEC;
  }
  else if(sortType == "insertion")
  {
    const clock_t begin = clock();
    insertionSort(arrayS, dataSize);
    const clock_t end = clock();
    cout<< float (end - begin) / CLOCKS_PER_SEC;
  }
  else if(sortType == "bubble")
  {
    const clock_t begin = clock();
    bubbleSort(arrayS, dataSize);
    const clock_t end = clock();
    cout<< float (end - begin) / CLOCKS_PER_SEC;
  }
  else if(sortType == "merge")
  {
    const clock_t begin = clock();
    mergeSort(arrayS, dataSize);
    const clock_t end = clock();
    cout<< float (end - begin) / CLOCKS_PER_SEC;
  }
  else if(sortType == "quick")
  {
    const clock_t begin = clock();
    quickSort(arrayS,arrayS[0],arrayS[dataSize-1]);
    const clock_t end = clock();
    cout<< float (end - begin) / CLOCKS_PER_SEC;
  }
  cout<<'\n';
}

Executive::~Executive()
{
  delete[] arrayS;
}

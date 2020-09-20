/*
*@author Alicia Zavala
*@date 10/17/19
*@file Matrix.h
*@brief Matrix class that handles everything from creating matrix, deleting it and finding its determinant
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix // always a square matrix
{

private:
  int rows = 0;
  int cols = 0;
  double** grid = nullptr;
  
public:
  
  /*
  * @pre matrix size and input file
  * @post creates matrix size n and gets array from inp
  * @return none
  */
  Matrix(std::istream& inp, int n); // Create storage for n x n matrix and read its n*n values from "inp"
  /*
  * @pre copy constructor for Matrix 
  * @post creates Submatrix r,c from original matrix M
  * @return none
  */
  Matrix(const Matrix& M, int r, int c); // Create Sr,c(M); if M is nxn, the new matrix will be (n-1)x(n-1)
  /*
  * @pre Takes Matrix to find determinant
  * @post -
  * @return determinant of the matrix
  */
  double det(Matrix M) const; // implement the recursive algorithm outlined above
  /*
  * @pre none
  * @post Prints Matrix
  * @return none
  */
  void Print();
  /*
  * @pre none
  * @post clears array of a matrix
  * @return none
  */
  void clearArray(Matrix& M);
  /*
  * @pre - 
  * @post destructor for matrix class
  * @return -
  */
  ~Matrix();

};

#endif

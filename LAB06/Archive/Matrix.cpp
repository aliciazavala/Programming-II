#include "Matrix.h"

#include <math.h>
#include <iostream>
using namespace std;

Matrix::Matrix(std::istream& inp, int n)// Create storage for n x n matrix and read its n*n values from "inp"
{
  rows = n;
  cols = rows;
  grid=new double*[rows];
  
  for (int i = 0; i < rows; i++){
    grid[i] = new double[cols];
  }

  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      inp >> grid[i][j];
    }
  }

}

Matrix::Matrix(const Matrix& M, int r, int c)
{
  rows = M.rows - 1;
  cols = M.cols - 1;
  grid = new double*[rows];
  
  for (int i = 0; i < rows; i++){
    grid[i] = new double[cols];
  }
  for(int i = 0; i < rows; ++i)
  {

    for(int j=0;j<cols;j++)
    {
          
      if(i == r)
      {     
        if(j == c || j>c)
        {
          grid[i][j] = M.grid[i+1][j+1];
        }
        else
        {
          grid[i][j] = M.grid[i+1][j];
        }
      }
      else if(i > r)
      { 
        if(j == c || j > c)
        {
          grid[i][j] = M.grid[i+1][j+1];
        }
        else
        {
          grid[i][j] = M.grid[i+1][j];
        }
        
      }
    }
  } 


}


double Matrix::det(Matrix M) const
{ 
  double d = 0;
  if(M.rows == 1)
  {
    d = M.grid[0][0];
    return d;
  }  
  else if(M.rows == 2)
  {
    d = ((M.grid[0][0]* M.grid[1][1]) - (M.grid[1][0]* M.grid[0][1]));
    return d;
  }
  else
  {
    for(int i=0; i<=M.rows-1;i++)
    {
      Matrix S(M,0,i);
      d = d + (pow(-1,i)*M.grid[0][i]*det(S));
      delete[] S.grid;
    }
    return d;    
  }  
}

void Matrix::Print()
{
  cout<<"Matrix:\n\n";

  for(int i = 0; i < rows ; i++)
  {
    cout<<"|\t";
    for(int j = 0; j < cols ; j++)
    {
        cout<< grid[i][j] << '\t';
    }
    cout<<"|";
    cout<<'\n';
  }  
  
  cout<<'\n';
}
void Matrix::clearArray(Matrix& M)
{
  for(int i=0;i<rows;i++)
  {
    delete[] M.grid[i];
  }
  delete[] M.grid;
}

Matrix::~Matrix()
{
  
}

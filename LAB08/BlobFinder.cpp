#include "BlobFinder.h"
#include "BlobReader.h"

#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

BlobFinder::BlobFinder(string filename)
{
    BlobReader map(filename);
    map.findSew();
    grid = map.getGrid();
    rows = map.getRows();
    cols = map.getCols();
    startR = map.getStartR();
    startC = map.getStartC();
    sewers = map.getSewers();
    totalSewers = map.getTSew();
}

void BlobFinder::print()
{
    for(int i=0;i<rows;i++)
    {
        
        for(int j=0;j<cols;j++)
        {
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}

void BlobFinder::mark(int row, int col)
{
    if(grid[row][col] == ' ')
    {
        grid[row][col]='B';
    }
}

void BlobFinder::solver()
{
    solve(startR,startC);
}

void BlobFinder::solve(int row, int col)
{   
    move(row,col);
}

void BlobFinder::move(int row,int col)
{
    //mark
    mark(row,col);
    //check up
    if(isValid(row-1,col))
    {
        if(grid[row-1][col]==' ')
        {
            solve(row-1, col);    
        }

    }
    //check right
    if(isValid(row,col+1))
    {
        if(grid[row][col+1]==' ')
        {
            solve(row, col+1);
        }
        if(grid[row][col+1]=='@')
        {
            sew++;
            if(totalSewers> sew)
            {
                solve(sewers[sew], col+1);
            }
        }
    }
    //check down
    if(isValid(row+1,col))
    {
        if(grid[row+1][col]==' ')
        {
            solve(row+1, col);
            
        }
    }
    //check left
    if(isValid(row,col-1))
    {
        if(grid[row][col-1]==' ')
        {
            solve(row, col-1);
        }
        if(grid[row][col-1]=='@')
        {
            sew++;
            if(totalSewers> sew)
            {
                solve(sewers[sew], col-1);
            }
        }  
    }
}

bool BlobFinder::isValid(int row,int col)
{
    if(row >=0 && row < rows && col >=0 && col<cols)
    {
        return true;

    }
    return false;

}

BlobFinder::~BlobFinder()
{
      for(int i=0; i<rows;i++)
    {
        delete[] grid[i];
    }
    delete[] grid;
    delete[] sewers;
}
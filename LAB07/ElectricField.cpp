#include "ElectricField.h"

#include <iostream>
#include <string>
#include <fstream>

ElectricField::ElectricField(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    //input size
    inFile>>rows>>cols;
    //define how many cells should the tank go
    cells = (rows*cols) - 2;
    //create grid
    grid = new string*[rows];
    for(int i = 0;i < rows;i++)
    {
        grid[i]= new string[cols];
    }

    //info of grid
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            inFile >> grid[i][j];
            if(grid[i][j] == "S")
            {
                startR = i;
                startC = j;
            }
        }
    }
    
}

ElectricField::~ElectricField()
{
  for(int i=0; i<rows;i++)
  {
    delete[] grid[i];
  }

  delete[] grid;
}

void ElectricField::print()
{
    //print any grid
    //if printing solution
    if(solution == false)
    {
        cout<<"Electric Field as read:"<<'\n';
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<setw(4)<<grid[i][j];
            }
            cout<<'\n';
        }
    }
    else
    {
        if(nosol == true)
        {
                cout<<"No solution possible."<<'\n';
        }
        else
        {
            cout<<"Solution:"<<'\n';
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {

                    cout<<setw(4)<<grid[i][j];
                }
                cout<<'\n';
            }

        }
    }
}    

void ElectricField::solver()
{
    solution = true;
    solve(startR,startC);
}
void ElectricField::solve(int row, int col)
{   
    
    if(exitAround(row,col) && gone==cells)
    {
        str = to_string(gone);
        nosol=false;
        grid[row][col] = str;
        return;
    }
    if(grid[row][col] == "S")
    {   
        
        move(row,col,"+");
        move(row,col,"-");
        
    }
    if(grid[row][col] == "+")
    {
        move(row,col,"-");
    }
    if(grid[row][col] == "-")
    {
        move(row,col,"+");
    }
    
    
}

void ElectricField::move(int row,int col, string look)
{
    str = to_string(gone);
    if(grid[row][col] != "S")
    {
        grid[row][col] = str;
    }
    gone++;
    //check diag down left
    if(isValid(row+1,col-1))
    {
        if(grid[row+1][col-1]==look)
        { 
            solve(row+1, col-1);
        }
    }
    //check down
    if(isValid(row+1,col))
    {
        if(grid[row+1][col]==look)
        {
            solve(row+1, col);
            
        }
    }
    //check diag down right
    if(isValid(row+1,col+1))
    {
        if(grid[row+1][col+1]==look)
        {
            solve(row+1, col+1);
        }
    }
    //check left
    if(isValid(row,col-1))
    {
        if(grid[row][col-1]==look)
        {
            solve(row, col-1);
        }
    }
    //check right
    if(isValid(row,col+1))
    {
        if(grid[row][col+1]==look)
        {
            solve(row, col+1);
        }
    }
    //check diag up left
    if(isValid(row-1,col-1))
    {
        if(grid[row-1][col-1]==look)
        {
            solve(row-1, col-1);
        }
    }
    //check up
    if(isValid(row-1,col))
    {
        if(grid[row-1][col]==look)
        {
            solve(row-1, col);
        }
    }
    //check diag up right
    if(isValid(row-1,col+1))
    {
        if(grid[row-1][col+1]==look)
        {
            solve(row-1, col+1);
        }
    }
    if(nosol)
    {
        if(grid[row][col]!="S")
        {
                if(look=="-")
            {
                grid[row][col]="+";
            }
            else
            {
                grid[row][col]="-";
            }
        }
    gone--;
    }
    
}

bool ElectricField::isValid(int row,int col)
{
    if(row >= 0 && row < rows && col >= 0 && col<cols)
    {
        return true;

    }
    else
    {
        return false;
    }
}
bool ElectricField::exitAround(int row,int col)
{
       if(isValid(row+1,col-1))
    {
        if(grid[row+1][col-1]=="E")
        { 
            return true;
        }
    }
    //check down
    if(isValid(row+1,col))
    {
        if(grid[row+1][col]=="E")
        {
            return true;
        }
    }
    //check diag down right
    if(isValid(row+1,col+1))
    {
        if(grid[row+1][col+1]=="E")
        {
            return true;
        }
    }
    //check left
    if(isValid(row,col-1))
    {
        if(grid[row][col-1]=="E")
        {
            return true;
        }
    }
    //check right
    if(isValid(row,col+1))
    {
        if(grid[row][col+1]=="E")
        {
            return true;
        }
    }
    //check diag up left
    if(isValid(row-1,col-1))
    {
        if(grid[row-1][col-1]=="E")
        {
            return true;
        }
    }
    //check up
    if(isValid(row-1,col))
    {
        if(grid[row-1][col]=="E")
        {
            return true;
        }
    }
    //check diag up right
    if(isValid(row-1,col+1))
    {
        if(grid[row-1][col+1]=="E")
        {
            return true;
        }
    }
    return false;
}
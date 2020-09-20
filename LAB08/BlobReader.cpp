#include "BlobReader.h"

#include <string>
#include <iostream>
#include <fstream>

BlobReader::BlobReader(string filename)
{
    ifstream inFile;
    inFile.open(filename);
    if(inFile.is_open())
    {
        //input size
        inFile>>rows>>cols;
        if(rows<1)
        {
            throw runtime_error("Error reading file. Invalid number of rows.\n");
        }
        if(cols <1)
        {
            throw runtime_error("Error reading file. Invalid number of columns.\n");
        }
        //INPUT START POIMT
        inFile>>startR>>startC;
        if(startR>rows || startC>cols)
        {
            throw runtime_error("Error reading file. Invalid start point for Blob.\n");
        }
        //create grid
        grid = new char*[rows];
        for(int i = 0;i < rows;i++)
        {
            grid[i]= new char[cols];
        }

        //info of neighborhood
        std::string line;
        getline (inFile, line);
        for(int i=0;i<rows;i++)
        {
            getline (inFile, line);
            for(int j=0;j<cols;j++)
            {
                
                grid[i][j] = line[j];
            }
            
        }
    }
    else
    {
        throw runtime_error("Error trying to open file. Invalid file.\n");
    }
}
void BlobReader::findSew()
{
    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(grid[i][j] == '@')
            {
                sewers++;
            }
        }
    }
    if(sewers>0)
    {
        sew = new int[sewers];
        int k=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == '@')
                {
                    sew[k]=i;
                    k++;
                }
            }           
        }
    }
}

int BlobReader::getRows()const
{
    return(rows);
}

int BlobReader::getCols()const
{
    return(cols);
}

int BlobReader::getStartR()const
{
    return(startR);
}

int BlobReader::getStartC()const
{
    return(startC);
}

char** BlobReader::getGrid()const
{
    return(grid);
}

int* BlobReader::getSewers()const
{
    return(sew);
}

int BlobReader::getTSew()const 
{
    return(sewers);
}

BlobReader::~BlobReader()
{

}    
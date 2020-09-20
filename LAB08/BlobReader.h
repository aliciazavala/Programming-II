/*
* @author Alicia Zavala
* @date
* @file BlobReader.h
* @brief
*/

#ifndef BLOB_READER_H
#define BLOB_READER_H

#include <iostream>
#include <string>
using namespace std;
class BlobReader
{
    private:
        int rows;
        int cols;
        int startR;
        int startC;
        int sewers = 0;
        char** grid = nullptr;
        int* sew = nullptr;

    public:
        BlobReader(string filename);
        ~BlobReader();
        void findSew();
        
        int getRows()const;
        int getCols()const;
        int getStartR()const;
        int getStartC()const;
        char** getGrid()const;
        int* getSewers()const;
        int getTSew()const;
};
#endif
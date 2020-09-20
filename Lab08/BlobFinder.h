/*
* @author Alicia Zavala
* @date
* @file BlobFinder.h
* @brief
*/

#ifndef BLOB_FINDER_H
#define BLOB_FINDER_H

#include "BlobReader.h"

#include <iostream>
#include <string>

using namespace std;

class BlobFinder
{
    private:
    char** grid = nullptr;
    int* sewers = nullptr;
    int rows;
    int cols;
    int startR;
    int startC;
    int sew = 0;
    int totalSewers;

    public:
    /*
    * @pre filename to open and get info from
    * @post calls the BlobReader class to read the file and set values accordingly
    * @return none
    */
    BlobFinder(string filename);
    /*
    * @pre none
    * @post 
    * @return none
    */
    ~BlobFinder();
    /*
    * @pre none.
    * @post prints map where the Blob will go to.
    * @return none.
    */
    void print();
    /*
    * @pre row and column to mark.
    * @post checks if row and column are valid to mark, and marks them.
    * @return none.
    */
    void mark(int row, int col);
    /*
    * @pre none
    * @post starts solve method in starting Blob position.
    * @return none
    */
    void solver();
    /*
    * @pre starting Blob position
    * @post moves blob to next valid position.
    * @return none
    */
    void solve(int row,int col);
    /*
    * @pre current position in map.
    * @post moves to blob to next cell.
    * @return none
    */
    void move(int row, int col);
    /*
    * @pre row and column to check.
    * @post checks if row and col cell moving to are valid.
    * @return true if valid.
    */
    bool isValid(int row,int col);
};

#endif
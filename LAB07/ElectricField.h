/*
* @author Alicia Zavala
* @date
* @file ElectricField.h
* @brief
*/

#ifndef ELECTRIC_FIELD_H
#define ELECTRIC_FIELD_H

#include <iostream>
#include <string>

using namespace std;

class ElectricField
{
    private:
    string** grid = nullptr;
    string str;
    int rows;
    int cols;
    int startR;
    int startC;
    int cells;
    bool solution = false;
    bool nosol = true;
    int gone = 0;

    public:
    /*
    * @pre filename to open and get info from
    * @post creates 2D Array with size and information gotten from filename
    * @return none
    */
    ElectricField(string filename);
    ~ElectricField();
    /*
    * @pre none
    * @post prints solution/no solution and Electric field
    * @return none
    */
    void print();
    /*
    * @pre none
    * @post starts solve method in starting cell
    * @return none
    */
    void solver();
    /*
    * @pre position of tank
    * @post moves tank to a positive cell
    * @return none
    */
    void solve(int row,int col);
    /*
    * @pre  int of current row and col, + or - sign to move to
    * @post moves tank to a positive cell
    * @return none
    */
    void move(int rows, int cols,string look);
    /*
    * @pre row and column to check
    * @post checks if row and col cell moving to are valid
    * @return none
    */
   bool isValid(int row,int col);
     /*
    * @pre row and column to check
    * @post checks if exit is around current cell
    * @return none
    */
   bool exitAround(int row,int col);
};

#endif
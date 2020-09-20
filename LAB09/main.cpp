/*
* @author Alicia Zavala
* @date  11/07/2019
* @file main.cpp
* @brief
*/
#include "Executive.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 4)
    {
        cout<<"Incorrect number of inputs!\n";
    }
    else
    {
        string a = argv[1];
        int size = stoi(a);
        Executive exec(size,argv[2],argv[3]);
    }

}

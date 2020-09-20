/*
*@author Alicia Zavala
*@date
*@file Function.h
*/
#ifndef Function_h
#define Function_h
#include <string>
#include <iostream>
using namespace std;

class Function
{
    private:
    string m_name;
    string m_status;

    public:
    Function(string name, string status);
    string getStatus();
    bool Status();
    string getName();

};
#endif
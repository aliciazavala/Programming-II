/*
* @author Alicia Zavala
* @date 11/21/2019
* @file Pokemon.cpp
* @brief Pokemon class with all private members, operator overloaders and methods
*/
#include "Pokemon.h"

#include <iostream>
#include <string>

using namespace std;
Pokemon::Pokemon(){

}
Pokemon::Pokemon(string US,string JP, int ID)
{
    US_name = US;
    JP_name = JP;
    pID = ID;
}

Pokemon::~Pokemon()
{

}

string Pokemon::getUSname()const
{
    return(US_name);
}

string Pokemon::getJPname()const
{
    return(JP_name);
}

int Pokemon::getID()const
{
    return(pID);
}

bool Pokemon::operator <(int key) const
{
    return(this->pID < key);
}

bool Pokemon::operator >(int key) const
{
    return (this->pID > key);
}

bool Pokemon::operator ==(int key) const
{
    return(this->pID == key);
}

bool Pokemon::operator ==(Pokemon& p) const
{
    if(p.JP_name == this->JP_name || p.US_name == this->US_name)
    {
      return true;
    }
    else
    {
      return false;
    }
}

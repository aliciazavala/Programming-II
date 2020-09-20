/*
* @author Alicia Zavala
* @date 11/20/2019
* @file Pokemon.h
* @brief Pokemon class with all private members, operator overloaders and methods
*/
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class Pokemon
{
    private:
        string US_name;
        string JP_name;
        int pID;

    public:

      /*
      * @pre
      * @post initializes Pokemon values
      * @return
      */
      Pokemon();
      /*
      * @pre
      * @post sets private member values
      * @return
      */
      Pokemon(string US,string JP, int ID);
      /*
      * @pre
      * @post Pokemon destructor
      * @return
      */
      ~Pokemon();
      /*
      * @pre
      * @post
      * @return Pokemon US Name
      */
      string getUSname()const;
      /*
      * @pre
      * @post
      * @return Pokemon Japanese Name
      */
      string getJPname()const;

      /*
      * @pre
      * @post
      * @return Pokemon Pokedex ID number
      */
      int getID()const;

      /*
      * @pre
      * @post operator < overloader, compares pokemon ID values
      * @return
      */
      bool operator <(int key) const;

      /*
      * @pre
      * @post operator > overloader, compares pokemon ID values
      * @return
      */
      bool operator >(int key) const;
      /*
      * @pre
      * @post operator == overloader, compares pokemon ID values
      * @return
      */
      bool operator ==(int key) const;
      /*
      * @pre
      * @post operator == overloader, compares one Pokemon to another
      * @return
      */
      bool operator ==(Pokemon& p) const;
      /*
      * @pre
      * @post operator cout overloader, sets how to "print" a Pokemon
      * @return
      */
      friend ostream& operator<<(ostream &out, const Pokemon& pk)
        {
            if(pk.US_name.length()<11)
            {
              out<< pk.US_name<<"     \t\t"<<pk.pID<<setw(20)<<'\t'<<pk.JP_name<<'\n';
              return out;
            }
            else
            {
              out<< pk.US_name<<" \t\t"<<pk.pID<<setw(20)<<'\t'<<pk.JP_name<<'\n';
              return out;
            }
        }
};
#endif

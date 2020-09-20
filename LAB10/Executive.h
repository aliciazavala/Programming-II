/*
* @author Alicia Zavala
* @date 11/20/2019
* @file Executive.h
* @brief Creates Pokedex (BST) and lets user edit it with given options by calling BST methods
*/
#include "Pokemon.h"
#include "BinarySearchTree.h"

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <fstream>

using namespace std;

class Executive
{
    private:
    ifstream inFile;
    string usName;
    string jpName;
    int id ;
    int option;
    int order;
    int treeOption;
    bool quit = false;
    int key;

    public:
      /*
      * @pre filename to open
      * @post creates Exective class and opens file
      * @return
      */
      Executive(string filename);
      /*
      * @pre
      * @post Exexcutive class destructor
      * @return
      */
      ~Executive();

      /*
      * @pre
      * @post has menu options and calls BST method according to option chosen by user
      * @return
      */
      void run(BST<Pokemon, int>& Pokedex);
      /*
      * @pre filename to open
      * @post reads filename
      * @return
      */
      void read(ifstream& file,BST<Pokemon, int>& Pokedex);
      /*
      * @pre
      * @post menu when a copy of BST has been made
      * @return
      */
      void menu(BST<Pokemon, int>& Pokedex,BST<Pokemon, int>& copyP);
      /*
      * @pre BST of where to add
      * @post Add method that calls BST add and adds a Pokemon
      * @return
      */
      void Add(BST<Pokemon, int>& Pokedex);
      /*
      * @pre BST to search
      * @post Searches Pokemon in BST with its method
      * @return
      */
      void Search(BST<Pokemon, int>& Pokedex);

      /*
      * @pre BST to print
      * @post prints BST according to users option
      * @return
      */void Print(BST<Pokemon, int>& Pokedex);

      /*
      * @pre
      * @post Removes a Pokemon in BST
      * @return
      */void Remove(BST<Pokemon, int>& Pokedex);
};

#endif

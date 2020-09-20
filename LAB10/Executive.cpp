/*
* @author Alicia Zavala
* @date 11/20/2019
* @file Executive.cpp
* @brief Creates Pokedex (BST) and lets user edit it with given options by calling BST methods
*/
#include "Executive.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

Executive::Executive(string filename)
{
    inFile.open(filename);
    if(inFile.is_open())
    {
        BST<Pokemon, int> Pokedex;
        read(inFile,Pokedex);
        run(Pokedex);
    }
    else
    {
        cout<<"Invalid file.\n";
    }

}
void Executive::run(BST<Pokemon, int>& Pokedex)
{
    while(quit == false)
        {
            cout<<"\n1) Search \n2) Print \n3) Copy \n4) Add \n5) Remove \n6) Quit\nEnter Option Number: ";
            cin>>option;
            cout<<"\n";
            if(option == 1)
            {
                Search(Pokedex);
            }
            if(option == 2)
            {
                Print(Pokedex);
            }
            if(option == 3)
            {
                BST<Pokemon, int> copyP(Pokedex);
                cout<<"Copy of Pokedex has been done correctly.\n";
                while(quit == false)
                {menu(Pokedex,copyP);}
            }
            if(option == 4)
            {
                Add(Pokedex);
            }
            if(option == 5)
            {
              Remove(Pokedex);
            }
            if(option == 6)
            {
                break;
            }
        }
}

void Executive::read(ifstream& inFile, BST<Pokemon, int>& Pokedex)
{
    string x;
    while(inFile>>usName)
    {
        if(inFile.eof())
        {
            break;
        }
        inFile>>id;
        if(id==0)
        {
            inFile.clear();
            inFile>>x;
            usName += " "+x;
            inFile>>id;
        }
        inFile>>jpName;
        Pokemon pokemon(usName,jpName, id);
        Pokedex.add(pokemon,id);
    }

}

void Executive::menu(BST<Pokemon, int>& Pokedex,BST<Pokemon, int>& copyP){
                cout<<"\n1) Search \n2) Print \n3) Copy \n4) Add \n5) Remove \n6) Quit\nEnter Option Number: ";
                cin>>option;
                cout<<"\n";
                if(option == 1)
                {
                    cout<<"Which Pokedex would you like to search?\n1)Original\n2)Copy\n";
                    cin>>treeOption;
                    if(treeOption == 1)
                    {
                        Search(Pokedex);
                    }
                    else
                    {
                        Search(copyP);
                    }
                }
                if(option == 2)
                {
                    cout<<"Which Pokedex would you like to print?\n1)Original\n2)Copy\n";
                    cin>>treeOption;
                    if(treeOption == 1)
                    {
                        Print(Pokedex);
                    }
                    else
                    {
                        Print(copyP);
                    }
                }
                if(option == 3)
                {
                        cout<<"Error. A copy has already been done.\n";
                }
                if(option == 4)
                {
                        cout<<"To which Pokedex would you like to add a Pokemon?\n1)Original\n2)Copy\n";
                        cin>>treeOption;
                        if(treeOption == 1)
                        {
                            Add(Pokedex);
                        }
                        else
                        {
                            Add(copyP);
                        }
                    }
                if(option == 5)
                {
                        cout<<"To which Pokedex would you like to remove a Pokemon?\n1)Original\n2)Copy\n";
                        cin>>treeOption;
                        if(treeOption == 1)
                        {
                          Remove(Pokedex);
                        }
                        else
                        {
                          Remove(copyP);
                        }
                    }
                if(option == 6)
                {
                    quit = true;
                }
}

void Executive::Add(BST<Pokemon, int>& Pokedex)
{
    Pokemon pok(usName,jpName,id);
    try
    {
        cout<<"Enter US Pokemon Name: ";
        cin>>usName;
        cout<<"Enter Pokedex ID: ";
        cin>>id;
        cout<<"Enter JPN Pokemon Name: ";
        cin>>jpName;
        cout<<"\n";
        Pokemon pok(usName,jpName,id);
        Pokedex.add(pok,id);
    }
    catch(runtime_error& except)
    {
        cout<<except.what()<<'\n';
    }
}
void Executive::Search(BST<Pokemon, int>& Pokedex)
{
     cout<<"Enter Pokedex Number to Search: ";
    cin>>key;
    cout<<"\n";
    if(Pokedex.finder(key)== true)
    {
        cout<<"US Name \t\tPokedex ID\t\tJPN Name \n-----------------------------------------------------------\n";
        Pokedex.search(key);
    }
    else
    {
      cout<<"Pokemon not in Pokedex.\n";
    }

}
void Executive::Remove(BST<Pokemon, int>& Pokedex)
{
    int x;
    cout<<"Enter Pokedex ID number to remove: ";
    cin>>x;
    try{
      Pokedex.remove(x);
    }
    catch(runtime_error& except)
    {
      cout<<except.what()<<"\n";
    }
}
void Executive::Print(BST<Pokemon, int>& Pokedex)
{
    cout<<"How would you like to print the Pokemon list?:\n1) Pre-Order\n2) In-Order\n3) Post-Order\n";
    cin>>order;
    cout<<"\n";
    cout<<"US Name \t\tPokedex ID\t\tJPN Name \n-----------------------------------------------------------\n";
    Pokedex.print(order);
}

Executive::~Executive()
{

}

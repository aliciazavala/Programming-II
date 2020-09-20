/*
*@author Alicia Zavala
*@date
*@file Command.h
*@brief
*/
#ifndef COMMAND_H
#define COMMAND_H

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Function.h"
using namespace std;

class Command
{
    private:

    public:
    Command(){};
    /*
    * @pre 
    * @post 
    * @return 
    */
    void Start(Queue<Stack<Function>*>& proc,ifstream& inFile,string command);
    /*
    * @pre 
    * @post 
    * @return 
    */
    void Cpu(Queue<Stack<Function>*>& proc,LinkedList<string>& names);
    /*
    * @pre 
    * @post 
    * @return 
    */
    void Throw(Queue<Stack<Function>*>& proc,LinkedList<string>& names);
    /*
    * @pre 
    * @post 
    * @return Print the information for process at the front of the queue. Include its name and the top-most function on its call stack.
    */
    void Status(Queue<Stack<Function>*>& proc,LinkedList<string>& names);
};
#endif
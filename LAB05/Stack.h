/*
*@author Alicia Zavala
*@date
*@file Stack.h
*/
#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
#include <iostream>
#include <string>

template<class Itemtype>
class Stack: public StackInterface<Itemtype>
{
  private:
  int m_size;
  Node<Itemtype>* m_top;
  
  public:
   Stack();
   /** destructor allows concrete implementations to clean up
       heap memory when the Stack is discarded. */
   ~Stack();

   /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */
   bool isEmpty() const;

   /** Adds a new entry to the top of this stack.
    @post If the operation was successful, newEntry is at the top of the stack.
    @param newEntry The object to be added as a new entry.
    @throw PrecondViolatedExcep if no memory available for the new item */
   void push(const Itemtype& newEntry);

  /** Removes the top of this stack.
  @pre The stack is not empty.
    @post If the operation was successful, the top of the stack has been removed.
    @throw PrecondViolatedExcep if the stack is empty when called */
    void pop();

   /** Returns the top of this stack.
    @pre The stack is not empty.
    @post The top of the stack has been returned, and the stack is unchanged.
    @return The top of the stack.
    @throw PrecondViolatedExcep if the stack is empty when called */
    Itemtype peek() const;
};

#include "Stack.cpp"

#endif

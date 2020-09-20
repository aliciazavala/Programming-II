/*
*@author Alicia Zavala
*@date
*@file Queue.h
*@brief
*/
#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"
#include "PrecondViolatedExcep.h"
#include "Node.h"
#include <stdexcept>
#include <iostream>
#include <string>

template<class ItemType>
class Queue: public QueueInterface<ItemType>
{
    private:
      Node<ItemType>* m_front;
      Node<ItemType>* m_back ;
      int m_size;

    public:
    Queue();
    /** destructor allows concrete implementations to clean up
        heap memory when the Stack is discarded. */
    ~Queue();

    void first2last();
     /** Sees whether this queue is empty.
     @return True if the queue is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new entry to the back of this queue.
     @post If the operation was successful, newEntry is at the back of the queue.
     @param newEntry  The object to be added as a new entry.
     @throw PrecondViolatedExcep if no memory available for the new item */
     void enqueue(const ItemType& newEntry) throw(PrecondViolatedExcep) ;

    /** Removes the front of this queue.
     @post If the operation was successful, the front of the queue has been removed.
     @throw PrecondViolatedExcep if the queue is empty when called */
     void dequeue() throw (PrecondViolatedExcep);

    /** Returns the front of this queue.
     @pre The queue is not empty.
     @post The front of the queue has been returned, and the queue is unchanged.
     @throw PrecondViolatedExcep if the queue is empty when called */
    ItemType peekFront() const throw (PrecondViolatedExcep);

};

#include"Queue.cpp"

#endif

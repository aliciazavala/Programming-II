#include <stdexcept>
#include <iostream>
#include <string>
#include "PrecondViolatedExcep.h"

template<typename Itemtype>
Queue<Itemtype>::Queue()
{
  m_front = nullptr;
  m_back = nullptr;
  m_size = 0;
}
template<typename Itemtype>
void Queue<Itemtype>::first2last()
{
  Node<Itemtype>* temp = m_front;
  for(int i=1;i<m_size;i++)
  {
    m_front->setNext(m_front->getNext());
  }
  m_back = temp;
}

template<typename Itemtype>
Queue<Itemtype>::~Queue()
{
  /*Node<Itemtype>* temp = m_front;
  while(isEmpty()==false)
  {
    temp = m_front->getNext();
    m_front -> setNext(nullptr);
    delete m_front;
    m_front = temp;
  }
  m_size=0;*/

}

template<typename Itemtype>
bool Queue<Itemtype>::isEmpty() const
{
  if (m_size == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

/** Adds a new entry to the back of this queue.
 @post If the operation was successful, newEntry is at the back of the queue.
 @param newEntry  The object to be added as a new entry.
 @throw PrecondViolatedExcep if no memory available for the new item */
template<typename Itemtype>
 void Queue<Itemtype>::enqueue(const Itemtype& newEntry) throw(PrecondViolatedExcep)
{
  Node<Itemtype>* newN = new Node<Itemtype>(newEntry);
  if(newN == nullptr)
  {
    std::string message;
     message= "Enqueue attemp failed. Memory is full.";
     throw(PrecondViolatedExcep(message));
  }
  if(m_size==0)
  {
    m_front = newN;
    m_back= newN;
    newN->setNext(nullptr);
  }
  else
  {
    newN->setNext(m_back);
    m_back = newN;
  }

  m_size++;
}

template<typename Itemtype>
 void Queue<Itemtype>::dequeue() throw(PrecondViolatedExcep)
{
  if (isEmpty()==true)
  {
    std::string message;
    message = "Cannot dequeue. Queue is empty.";
    throw(PrecondViolatedExcep(message));
  }
  else
  {
    Node<Itemtype>* temp = m_back;
      if(m_size==1)
      {
        delete m_front;
        m_front = nullptr;
        m_back = nullptr;
      }
      else
      {
        while (temp->getNext() != m_front)
        {
          temp = temp->getNext();
        }

        delete m_front;
        temp->setNext(nullptr);
        m_front=temp;
      }
    m_size--;
  }
}

template<typename Itemtype>
Itemtype Queue<Itemtype>::peekFront() const throw(PrecondViolatedExcep)
{
  if (isEmpty()==true)
  {
    std::string message;
    message = "Peek cannot be done. Queue is empty.";
    throw(PrecondViolatedExcep(message));
  }
  else
  {
    return (m_front->getItem());
  }
}

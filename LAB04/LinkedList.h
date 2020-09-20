#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SLNode.h"
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList: public ListInterface<ItemType>{
  private:
  SLNode<ItemType>* m_front = nullptr;
  int m_length = 0;

  public:

    bool isEmpty() const;
    int getLength() const;
    void insert(int newPosition, const ItemType& newEntry);
    void remove(int position);
    void clear();
    ItemType getEntry(int position) const;
    void setEntry(int position, const ItemType& newEntry);
    ~LinkedList();

};

#include "LinkedList.cpp"

#endif


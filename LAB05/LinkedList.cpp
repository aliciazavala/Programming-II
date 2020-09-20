#include <iostream>
#include <string>
#include <fstream>

template<class ItemType>
bool LinkedList<ItemType>::isEmpty()const
{

    if(m_length == 0){
      return(true);
    }
    else{
      return(false);
    }

}

template<class ItemType>
int LinkedList<ItemType>::getLength()const
{
  return (m_length);
}

template<class ItemType>
void LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
  if(newPosition<1 || newPosition>m_length || isEmpty()==true)
  {
    std::cout<<"Invalid position to insert.\n";
  }
  else{
    if(newPosition == 1)
    {
      Node<ItemType>* temp = new Node<ItemType>(newEntry);
      if(m_length == 0)
      {
        m_front = temp;
      }
      else
      {
      temp->setNext(m_front);
      m_front = temp;
      }
      m_length++;
    }
    else if(newPosition == (m_length+1))
    {
      Node<ItemType>* newNode = new Node<ItemType>(newEntry);
      Node<ItemType>* temp = m_front;
      for(int i=1;i <= newPosition-1; i++)
      {
        temp->getNext();
        if(i == (newPosition-1))
        {
        temp -> setNext(newNode);
        }
      }   
      m_length++;
    }
    else
    {
      Node<ItemType>* newNode = new Node<ItemType>(newEntry);
      Node<ItemType>* temp = m_front;
      Node<ItemType>* temp2 = m_front;
      for(int i = 1; i <= (newPosition-1); i++)
      {
        temp = temp -> getNext();
      }
      for(int i = 1; i < (newPosition-1); i++)
      {
        temp2 = temp2 -> getNext();
      }

      temp2 -> setNext(newNode);
      newNode -> setNext(temp);
      m_length++;
    }
  }
}
template<class ItemType>
void LinkedList<ItemType>::removeBack()
{
  Node<ItemType>* prev;
  Node<ItemType>* current = m_front;
  if(m_length==1)
    {
      delete current;
      m_length--;
      m_front=nullptr;
  	}
    else
    {
  		while(current->getNext() != nullptr)
      {
    		prev = current;
    		current = current->getNext();
  	  }
      delete current;
      prev -> setNext(nullptr);
      m_length--;
    }
}
template<class ItemType>
void LinkedList<ItemType>::remove(int position)
{
  if(position<1 || position>m_length || isEmpty()==true)
  {
    std::cout<<"Invalid ID to remove.\n";
  }
  else
  {
    Node<ItemType>* temp = nullptr;
    Node<ItemType>* temp2 = nullptr;
    if(position == 1){
      temp = m_front;
      m_front = m_front->getNext();
      delete temp;
    }
    else if(position == m_length && position != 1)
    {
      temp = m_front;
      for(int i=1; i<position-1;i++)
      {
        m_front = m_front->getNext();
      }
      for(int i=1; i<position;i++)
      {
       temp = temp->getNext();
      }
      m_front->setNext(nullptr);
      delete temp;
    }
    else
    {
      temp2 = m_front;
      for(int i=1 ; i<position-1;i++){
        temp2 = temp2->getNext();
      }
      temp = temp2->getNext();
      temp2->setNext(temp->getNext());
      //temp->setNext(nullptr);
      delete temp;
      temp = nullptr;
    } 
    m_length--;
  }
}

template<class ItemType>
void LinkedList<ItemType>::clear()
{
  while (isEmpty()==false)
  {
      remove(1);
  }    
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position)const
{
  if(position<1 || position>m_length || isEmpty()==true)
  {
    throw PrecondViolatedExcep("Invalid position to get entry.\n");
  }
  else
  {
      Node<ItemType>* temp = m_front;
      for(int i = 1; i < position; i++)
      {
        temp = temp -> getNext();
      }
      return(temp -> getItem());
   }    
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
  if(position<1)
  {
    std::cout<<"Invalid position to set entry.\n";
  }
  else
  {
    Node<ItemType>* n = new Node<ItemType>(newEntry);
    n -> setNext(m_front);
    m_front = n;
    m_length++;
  }  
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList(){

}

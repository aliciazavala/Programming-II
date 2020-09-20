template<typename Itemtype>
Stack<Itemtype>::Stack()
{
  m_size = 0;
  m_top = nullptr;

}

template<typename Itemtype>
Stack<Itemtype>::~Stack()
{
  Node<Itemtype>* temp = m_top;
  while(isEmpty()==false)
  {
    pop();
  }
  m_size=0;
}

/** Sees whether this stack is empty.
 @return True if the stack is empty, or false if not. */
template<typename Itemtype>
bool Stack<Itemtype>:: isEmpty() const
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

/** Adds a new entry to the top of this stack.
 @post If the operation was successful, newEntry is at the top of the stack.
 @param newEntry The object to be added as a new entry.
 @throw PrecondViolatedExcep if no memory available for the new item */
template<typename Itemtype>
void Stack<Itemtype>::push(const Itemtype& newEntry)
{
  Node<Itemtype>* temp = new Node<Itemtype>(newEntry);
    if(temp == nullptr)
  {
    std::string message;
    message = "Push attempt failed. Full Memory.";
    throw(PrecondViolatedExcep(message));
  }
  else
  {
    temp -> setNext(m_top);
    m_top = temp;
    m_size++;
  }

}

/** Removes the top of this stack.
 @pre The stack is not empty.
 @post If the operation was successful, the top of the stack has been removed.
 @throw PrecondViolatedExcep if the stack is empty when called */

template<typename Itemtype>
 void Stack<Itemtype>::pop()
 {
   if(isEmpty()==true)
  {
    std::string message;
		message = "Pop attempt failed. Empty stack.";
    throw(PrecondViolatedExcep(message));
	}
	else
  {
      /*Node<Itemtype>* temp = m_top;
      for(int i=1;i<m_size--;i++)
      {
        temp->setItem(m_top->getNext()->getItem());
        temp = temp->getNext();
      }*/
      /*Node<Itemtype>* temp = m_top;
      temp = temp->getNext();
      m_top->setItem(temp->getItem());
      temp = temp->getNext();*/
    
      /*Node<Itemtype>* temp = m_top;
      temp = temp->getNext();
      m_top = temp;*/
    Node<Itemtype>* temp = m_top;
    if(m_size==1)
    {
      m_size=0;
      m_top=nullptr;
    }
    else
    {
      temp = m_top->getNext();
      m_top -> setNext(nullptr);
      m_top = temp;
      m_size--;
    }

	}
 }

/** Returns the top of this stack.
 @pre The stack is not empty.
 @post The top of the stack has been returned, and the stack is unchanged.
 @return The top of the stack.
 @throw PrecondViolatedExcep if the stack is empty when called */
template<typename Itemtype>
Itemtype Stack<Itemtype>::peek() const
 {
   if(isEmpty()==true)
  {
   std::string message;
		message = "Empty stack.";
    throw(PrecondViolatedExcep(message));
	}
	else
  {
		return(m_top->getItem());
	}
 }

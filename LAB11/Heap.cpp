 #include<stdexcept>
#include <iostream>

template <typename T>
Heap<T>::Heap(int initialSize)
{
    sizeOfArray = initialSize;
    numItemsInHeap = 0;
    theCompleteBinaryTree = new T[sizeOfArray];
}

template <typename T>
Heap<T>::Heap(const Heap<T>& heap)// The copy constructor
{
	sizeOfArray = heap.sizeOfArray;
	numItemsInHeap = heap.numItemsInHeap;
  theCompleteBinaryTree = new T[sizeOfArray];
  for(int i = 0; i < numItemsInHeap; i++)
  {
    theCompleteBinaryTree[i] = heap.theCompleteBinaryTree[i];
  }
}

template <typename T>
Heap<T>::~Heap()
{
    delete[] theCompleteBinaryTree;
}

template <typename T>
void Heap<T>::swap(int child, int parent)
{
  T temp = theCompleteBinaryTree[parent];
  theCompleteBinaryTree[parent] = theCompleteBinaryTree[child];
  theCompleteBinaryTree[child] = temp;
}

template <typename T>
int Heap<T>::parent(int index)
{
  return (index - 1)/2;
}

template <typename T>
int Heap<T>::leftChild(int index)
{
  return (2*index)+1;
}

template <typename T>
int Heap<T>::rightChild(int index)
{
  return (2*index)+2;
}

template <typename T>
void Heap<T>::add(T& newItem)
{
 if(sizeOfArray == numItemsInHeap)
  {
    resize();
  }
  numItemsInHeap++;
  theCompleteBinaryTree[numItemsInHeap-1] = newItem;//check!!!
  upHeap(numItemsInHeap-1);
}

template <typename T>
void Heap<T>:: resize()
{
    sizeOfArray = sizeOfArray * 2;
    T* tempArray = new T[sizeOfArray];
    for(int i=0; i< (sizeOfArray/2); i++)
    {
        tempArray[i]=theCompleteBinaryTree[i];
    }
    delete[] theCompleteBinaryTree;
    theCompleteBinaryTree = tempArray;
}

template <typename T>
bool Heap<T>::isEmpty() const
{
    if(numItemsInHeap == 0)
    {
        return(true);
    }
    return(false);
}

template <typename T>
void Heap<T>::remove() 
{
    int lastElement = numItemsInHeap-1;
    theCompleteBinaryTree[0] = theCompleteBinaryTree[lastElement]; 
    numItemsInHeap--;
    heapify(0); 
}

template <typename T>
T Heap<T>::peekTop() const
{
    if(numItemsInHeap == 0)
  {
    throw EmptyHeap();
  }
  return(theCompleteBinaryTree[0]);
}

template <typename T>
void Heap<T>::heapify(int index)
{
    int largest = index; // Initialize largest as root 
    int l = leftChild(index); // left = 2*i + 1 
    int r = rightChild(index); // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < numItemsInHeap && theCompleteBinaryTree[l] > theCompleteBinaryTree[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < numItemsInHeap && theCompleteBinaryTree[r] > theCompleteBinaryTree[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != index) { 
        swap(largest, index); 
  
        // Recursively heapify the affected sub-tree 
        heapify(largest); 
    } 
}

template <typename T>
void Heap<T>::upHeap(int index)
{
    int parentI = parent(index);
    if (parentI > 0) { 
        if (theCompleteBinaryTree[index] > theCompleteBinaryTree[parentI]) { 
            swap(index,parentI); 
            upHeap(parentI); 
        } 
    } 
} 

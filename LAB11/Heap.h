#ifndef HEAP_H
#define HEAP_H

#include "EmptyHeap.h"

#include<iostream>
#include<stdexcept>
using namespace std;

template <typename T>
class Heap // a max Heap
{
public:
	Heap(int initialSize);
	Heap(const Heap<T>& heap); // The copy constructor
	~Heap();

	void add(T& newItem);
	bool isEmpty() const;
	void remove();
	T peekTop() const;
	
private:
	void heapify(int index);
	void upHeap(int index);
	void resize();
	int parent(int index);
	int leftChild(int index);
	int rightChild(int index);
	void swap(int child, int parent);
	T* theCompleteBinaryTree;
	int sizeOfArray;
	int numItemsInHeap;
};

#include "Heap.cpp"
#endif

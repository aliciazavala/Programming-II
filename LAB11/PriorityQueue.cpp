using namespace std;

template <typename T>
PriorityQueue<T>::PriorityQueue(int initialSize)
{
    theHeap = new Heap<T>(initialSize);
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq) // The copy constructor
{
    theHeap = new Heap<T>(*pq.theHeap);

}
template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    
}

template <typename T>
void PriorityQueue<T>::enqueue(T newEntry)
{
    theHeap->add(newEntry);
}

template <typename T>
void PriorityQueue<T>::dequeue() /* throw EmptyPriorityQueue */
{
    if(isEmpty() == true)
    {
        throw EmptyPriorityQueue();
    }
    try
    {
        theHeap->remove();
    }
    catch(EmptyHeap& error)
    {
        throw EmptyPriorityQueue();
    }
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return(theHeap->isEmpty());
}

template <typename T>
T PriorityQueue<T>::peekFront() const /* throw EmptyPriorityQueue */
{
    if(isEmpty() == true)
    {
        throw EmptyPriorityQueue();
    }
    try
    {
        return(theHeap->peekTop());
    }
    catch(EmptyHeap& error)
    {
        throw EmptyPriorityQueue();
    }
}
/*
* @author Alicia Zavala
* @date 11/20/2019
* @file BNode.cpp
* @brief Nodes for BST with all methods and members
*/
template <typename itemType>
BNode<itemType>::BNode()
{
    leftC = nullptr;
    rightC = nullptr;
}

template <typename itemType>
BNode<itemType>::BNode(const itemType& entry)
{
   item = entry;
}

template <typename itemType>
BNode<itemType>::BNode(const BNode<itemType>& other)
{
    leftC = nullptr;
    rightC = nullptr;
    item = other.item;
    if (other.leftC != nullptr)
    {
        leftC = new BNode<itemType>(*(other.leftC));
    }
    if (other.rightC != nullptr)
    {
        rightC = new BNode<itemType>(*(other.rightC));
    }
}

template <typename itemType>
itemType& BNode<itemType>:: getItem()
{
    return(item);
}

template <typename itemType>
BNode<itemType>* BNode<itemType>::getLeft() const
{
    return(leftC);
}

template <typename itemType>
BNode<itemType>* BNode<itemType>::getRight() const
{
    return(rightC);
}

template <typename itemType>
void BNode<itemType>::setItem(itemType& entry)
{
    item = entry;
}

template <typename itemType>
void BNode<itemType>::setLeft(BNode<itemType>* left)
{
    leftC = left;
}

template <typename itemType>
void BNode<itemType>::setRight(BNode<itemType>* right)
{
    rightC = right;
}

template <typename itemType>
BNode<itemType>::~BNode()
{

}

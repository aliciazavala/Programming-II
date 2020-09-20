/*
* @author Alicia Zavala
* @date 11/20/2019
* @file BNode.h
* @brief Nodes for BST with all methods and members
*/
#ifndef BNODE_H
#define BNODE_H

#include <iostream>

template <typename itemType>
class BNode
{
  private:
    itemType item;
    BNode<itemType>* leftC;
    BNode<itemType>* rightC;

  public:
    /*
    * @pre
    * @post initlializes BNode values
    * @return
    */
   BNode();
   /*
   * @pre
   * @post sets value for item in BNode
   * @return
   */
   BNode(const itemType& entry);

   /*
   * @pre
   * @post Creates deep copy of BNode
   * @return
   */
   BNode(const BNode<itemType>& other);

   /*
   * @pre
   * @post
   * @return BNode item value;
   */
   itemType& getItem();

   /*
   * @pre
   * @post
   * @return LeftChild pointer
   */
   BNode<itemType>* getLeft() const;
   /*
   * @pre
   * @post
   * @return Right Child pointer
   */
   BNode<itemType>* getRight() const;

   /*
   * @pre
   * @post sets Item value for BNode
   * @return
   */
   void setItem(itemType& entry);

   /*
   * @pre
   * @post sets Left Child item value
   * @return
   */
   void setLeft(BNode<itemType>* left);
   /*
   * @pre
   * @post sets RIght Child item value
   * @return
   */
   void setRight(BNode<itemType>* right);

   /*
   * @pre
   * @post BNode destructor.
   * @return
   */
   ~BNode();
};
#include "BNode.cpp"
#endif

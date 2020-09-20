/*
* @author Alicia Zavala
* @date 11/20/2019
* @file BinarySearchTree.h
* @brief creates BST with BinaryNodes and all its methods
*/
#include "BNode.h"
#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>

using namespace std;
template <typename itemType,typename keyType>
class BST
{
  private:
  BNode<itemType>* m_root;
  /*
  * @pre key to find and tree to Search
  * @post helper method for search method to find node with key value
  * @return
  */
  void search(keyType key, BNode<itemType>* tree);
  /*
  * @pre
  * @post helper method for add function to add a value at a position
  * @return
  */
  void add(itemType entry,BNode<itemType>* tree,keyType id);
  /*
  * @pre
  * @post helper method for print to print nodes in traversal order
  * @return
  */
  void print(int option,BNode<itemType>* tree);
  bool found;

  public:
  /*
  * @pre
  * @post inirializes values of Binary Search Tree
  * @return
  */
  BST();
  /*
  * @pre binary search tree to Copy
  * @post Copy Constructor. Creates deep copy of binary search Tree
  * @return
  */
  BST(BST<itemType,keyType>& original);
  /*
  * @pre
  * @post destructor for binary search tree. Removes all nodes from Tree
  * @return
  */
  ~BST();

  /*
  * @pre
  * @post helper method for copy constructor
  * @return BinaryNode copied
  */
  BNode<itemType>* copy(BNode<itemType>* original);

  /*
  * @pre itemtype to add and key value
  * @post adds value to binary search tree where it should go
  * @return
  */
  void add(itemType entry, keyType id);

  /*
  * @pre BST to delete completely
  * @post helper method to delete all nodes from tree
  * @return
  */
  void deleteTree(BNode<itemType>* tree);

  /*
  * @pre traversal order
  * @post print method that prints given an order
  * @return
  */
  void print(int option);

  /*
  * @pre key value
  * @post searches throughout BST for a node with key value
  * @return
  */
  void search(keyType key);

  /*
  * @pre Itemtype entry and BST to Search
  * @post find itemtype inside BST
  * @return returns true if found
  */
  bool finder(itemType entry,BNode<itemType>* tree);

  /*
  * @pre key value to search
  * @post helper method for find
  * @return returns true if Itemtype with Key value is found
  */
  bool finder(keyType id);

  /*
  * @pre key value to search
  * @post finds itemtype that contains key value in BST_H
  * @return returns true if Itemtype with Key value is found
  */
  bool find(keyType entry,BNode<itemType>* tree);

  /*
  * @pre
  * @post removes BNode that contains Itemtype with Key value
  * @return
  */
  void remove(keyType key);

  /*
  * @pre
  * @post calls removeNode once it finds the value
  * @return Node to delete
  */
  BNode<itemType>* removeValue(BNode<itemType>* root, keyType value);

  /*
  * @pre
  * @post finds the left most Node to remove and calls remove method
  * @return Left most Node
  */
  BNode<itemType>* removeLeftmostNode(BNode<itemType>* tree, itemType value);

  /*
  * @pre
  * @post removes node inside BST
  * @return New BNode* with child deleted, or no childs
  */
  BNode<itemType>* removeNode(BNode<itemType>* node);

};
#include "BinarySearchTree.cpp"
#endif

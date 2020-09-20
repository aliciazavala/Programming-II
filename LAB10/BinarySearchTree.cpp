/*
* @author Alicia Zavala
* @date 11/20/2019
* @file BinarySearchTree.cpp
* @brief creates BST with BinaryNodes and all its methods
*/
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename itemType,typename keyType>
BST<itemType,keyType>::BST()
{
    m_root = nullptr;
}

template <typename itemType,typename keyType>
BST<itemType,keyType>::~BST()
{
    deleteTree(m_root);
}

template <typename itemType,typename keyType>
void BST<itemType,keyType>::deleteTree(BNode<itemType>* tree)
{
	if(tree != nullptr)
	{
		BNode<itemType>* temp = tree;
		deleteTree(tree->getLeft());
		deleteTree(tree->getRight());
		delete (temp);
	}

}
template <typename itemType,typename keyType>
BST<itemType,keyType>::BST(BST<itemType,keyType>& original)
{
    m_root = copy(original.m_root);

}
template <typename itemType,typename keyType>
BNode<itemType>* BST<itemType,keyType>::copy(BNode<itemType>* originalTree)
{
    BNode<itemType>* temp = nullptr;
    if(originalTree != nullptr)
    {
        temp = new BNode<itemType>(originalTree->getItem());
        temp->setLeft(copy(originalTree -> getLeft()));
        temp->setRight(copy(originalTree -> getRight()));
    }
    return temp;
}

template <typename itemType, typename keyType>
void BST<itemType, keyType>::print(int option)
{
    print(option, m_root);
}
template <typename itemType, typename keyType>
void BST<itemType, keyType>::print(int option,BNode<itemType>* tree)
{
    if(tree == nullptr)
    {
        return;
    }
    if (option == 1)
    {
    //Pre order
        cout<<(tree->getItem());
        print(option,tree->getLeft());
        print(option,tree->getRight());
    }
    // in order
    if(option == 2)
    {
        print(option,tree->getLeft());
        cout<<(tree->getItem());
        print(option,tree->getRight());
    }
    // post order
    if(option == 3)
    {
        print(option,tree->getLeft());
        print(option,tree->getRight());
        cout<<(tree->getItem());
    }
}

template <typename itemType, typename keyType>
void BST<itemType, keyType>::add(itemType entry, keyType id)
{
    find(id,m_root);
    if(found == true)
    {
        int x;
        cout<<"Item with that Pokedex ID already exists, do you want to modify it?\n1) Yes\n2) No\n";
        cin>>x;
        if(x == 1)
        {
          add(entry,m_root,id);
        }
    }
    finder(entry,m_root);
    if(found == true)
    {
        throw runtime_error("Item already added.");
    }
    if(m_root==nullptr)
    {
       m_root = new BNode<itemType>(entry);
    }
    else
    {
        add(entry,m_root,id);
    }

}

template <typename itemType, typename keyType>
void BST<itemType, keyType>::add(itemType entry,BNode<itemType>* tree,keyType id)
{
  if(tree->getItem() == id)
  {
    tree->setItem(entry);
  }
	if(tree->getItem() > id)
    {
        if(tree->getLeft() == nullptr)
        {
            BNode<itemType>* temp = new BNode<itemType>(entry);
            tree->setLeft(temp);
            return;
        }
		add(entry,tree->getLeft(),id);
	}
	else if(tree->getItem() < id){
        if(tree->getRight() == nullptr)
        {
            BNode<itemType>* temp = new BNode<itemType>(entry);
            tree->setRight(temp);
            return;
        }
		add(entry,tree->getRight(),id);
	}

}

template <typename itemType,typename keyType>
void BST<itemType, keyType>::search(keyType key, BNode<itemType>* tree)
{
  found=false;
    if (tree!= nullptr)
    {
        if (tree->getItem() == key)
        {
            found = true;
            cout<<tree->getItem();
        }
        else if (tree->getItem() > key)
        {
            search(key, tree->getLeft());
        }
        else
        {
            search(key, tree->getRight());
        }
    }
}
template <typename itemType,typename keyType>
void BST<itemType, keyType>::search(keyType key)
{
    found = false;
    search(key,m_root);
}
template <typename itemType,typename keyType>
bool BST<itemType, keyType>::finder(keyType id)
{
  find(id,m_root);
  if(found==true)
  {
    found=false;
    return true;
  }
  return(false);
}
template <typename itemType,typename keyType>
bool BST<itemType, keyType>::find(keyType key,BNode<itemType>* tree)
{
  found = false;
    if (tree!= nullptr)
    {
        if (tree->getItem() == key)
        {
            found = true;
            return(true);
        }
        else if (tree->getItem() > key)
        {
            find(key, tree->getLeft());
        }
        else
        {
            find(key, tree->getRight());
        }
    }
    return(false);
}

template <typename itemType,typename keyType>
bool BST<itemType, keyType>::finder(itemType entry, BNode<itemType>* tree)
{
  found = false;
    if (tree!= nullptr)
    {
        if (tree->getItem() == entry)
        {
            found = true;
            return(true);
        }
        finder(entry, tree->getLeft());
        finder(entry, tree->getRight());
    }
    return(false);
}

template <typename itemType,typename keyType>
BNode<itemType>* BST<itemType, keyType>::removeValue(BNode<itemType>* tree, keyType data)
{
    if(tree == nullptr)
    {
        return nullptr;
    }
    else if(tree->getItem() == data)
    {
        tree = removeNode(tree);
        return tree;
    }
    else if(tree->getItem() > data)
    {
        BNode<itemType>* temp = removeValue(tree->getLeft(),data);
        tree->setLeft(temp);
        return tree;
    }
    else
    {
        BNode<itemType>* temp = removeValue(tree->getRight(),data);
        tree->setRight(temp);
        return tree;
    }
}

template <typename itemType,typename keyType>
BNode<itemType>* BST<itemType, keyType>::removeNode(BNode<itemType>* tree)
{
    //no child
    if(tree->getLeft() == nullptr && tree->getRight() == nullptr)
    {
        delete tree;
        tree = nullptr;
        return tree;
    }
    //one child
    else if(tree->getRight() == nullptr)
    {
        BNode<itemType>* temp = tree->getLeft();
        delete tree;
        tree = nullptr;
        return temp;
    }
    else if(tree->getLeft() == nullptr )
    {
        BNode<itemType>* temp = tree->getRight();
        delete tree;
        tree = nullptr;
        return temp;
    }
    //two
    else
    {
        itemType value;
        BNode<itemType>* temp = removeLeftmostNode(tree->getRight(), value);
        tree->setRight(temp);
        tree->setItem(value);
        return (tree);
    }
}
template <typename itemType,typename keyType>
BNode<itemType>* BST<itemType, keyType>::removeLeftmostNode(BNode<itemType>* tree, itemType value)
{
    if(tree->getLeft() == nullptr)
    {
        value = tree->getItem();
        return(removeNode(tree));
    }
    else
    {
        return(removeLeftmostNode(tree->getLeft(),value));
    }
}
template <typename itemType,typename keyType>
void BST<itemType, keyType>::remove(keyType key)
{
    find(key,m_root);
    if(found == false)
    {
      throw runtime_error("Item not found to remove.");
    }
    removeValue(m_root,key);
}

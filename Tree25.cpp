#include <iostream>
#include "AVL.h"

using namespace std;


AVL::AVL()
{
	head = NULL;
}

AVL::~AVL() {
    if (head != NULL) {
        delete head;
    }
}

void AVL::insert (string str) { insert(str, head); }

void AVL::insert (string str, node* pointer)
{
	if(pointer == NULL)
	{
		//cout<<"head inserted:"<<str<<endl;
		node* tmp = new node(str);
		head=tmp;
		//cout<<"head init"<<endl;
	}
	else
	{
		if(str > pointer->getData())
		{
			if(pointer->getRight() == NULL)
			{
				node* tmp = new node(str);
				pointer->setRight(tmp);
                //cout<<"str inserted:"<<str<<endl;
			}
			else
			{
				insert(str, pointer->getRight());
			}
			
		}
		else if(str < pointer->getData())
		{
			if(pointer->getLeft() == NULL)
			{
				node* tmp = new node(str);
				pointer->setLeft(tmp);
				//cout<<"str inserted:"<<str<<endl;
			}
			else
			{
				insert(str, pointer->getLeft());
			}
		}
        else {
            pointer->incrementCounter ();
        }
	}
}


int AVL::countInTree(node* headz)
{
	if(headz==NULL)
    {
		return 0;
	}
	else
    {
		return headz->getCounter()+countInTree(headz->getLeft())+countInTree(headz->getRight());
	}

}

void AVL::printInOrder(node* headz)
{
	if(headz!=NULL)
	{
		printInOrder(headz->getLeft());
		if (headz ->getCounter() > 0 )
			cout<<headz->getData()<< " "<< headz->getCounter()<< endl;
		printInOrder(headz->getRight());
	}
}

void AVL::printTree (node* headz, string spaces) {
    if (headz != NULL) {
        cout << spaces << headz->getData () << " " <<headz->getCounter() << endl;
        printTree (headz->getLeft(), spaces + " ");
        printTree (headz->getRight(), spaces+" ");
    }
}


void AVL::sorted (node* headz, vector <string> &list) {
	if (headz!=NULL) {
		sorted (headz->getLeft(), list);
		for (int i = 0; i < headz ->getCounter(); i++) {
			list.push_back (headz->getData());
		}
		sorted (headz->getRight(), list);
	}
}

int AVL::search(string str) { return search (str, head); }

int AVL::search(string str, node* pointer)
{
	if(pointer==NULL)
	{
		return 0;
	}
	else if(pointer->getData()==str)
	{
		return pointer->getCounter();
	}
	else if(pointer->getData()>str)
	{
		return search(str, pointer->getLeft());
	}
	else if(pointer->getData()<str)
	{
		return search(str, pointer->getRight());
	}
	return 0;
}


void AVL::readInTree(string a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insert(a[i]);
	}
}

node* AVL::getHead()
{  return head; }


vector<string> AVL::rangeSearch (string a, string b) {
    vector <string> v;
    rangeSearches (a, b, head, v);
    return v;
}

void AVL::rangeSearches (string a, string b, node* pointer, vector <string> &list) {
    if (pointer != NULL) {
        if (pointer->getData() < a) {
            rangeSearches (a, b, pointer->getRight(), list);
        }
        else if (pointer->getData () > b) {
            rangeSearches (a, b, pointer->getLeft(), list);
        }
        else {
            //cout << pointer->getData() << endl;
            for (int i = 0; i < pointer->getCounter(); i++) {
                list.push_back (pointer->getData());
            }
            rangeSearches (a, b, pointer->getRight(), list);
            rangeSearches (a, b, pointer->getLeft(), list);
        }
    }
}


node* AVL::searchNode(string str, node* pointer)
{
	if(pointer==NULL)
	{
		return 0;
	}
	else if(pointer->getData()==str)
	{
		return pointer;
	}
	else if(pointer->getData()>str)
	{
		return searchNode(str, pointer->getLeft());
	}
	else if(pointer->getData()<str)
	{
		return searchNode(str, pointer->getRight());
	}
	return NULL;
}

void AVL::deleteNode(string str)
{
    head = deleteNodeHelper (str, head);
}

node* AVL::deleteNodeHelper (string str, node *pointer) {
	if (pointer == NULL)  {
		return pointer;
	}

	if (pointer->getData() < str) {
		pointer->setRight (deleteNodeHelper(str, pointer->getRight()));
		return pointer;
	}
	else if (pointer->getData() > str) {
		pointer->setLeft (deleteNodeHelper(str, pointer->getLeft()));
		return pointer;
	}
	else if (pointer->getCounter() > 1) {
		pointer->decrementCounter();
	}
	else {
		if (pointer->getRight() == NULL) {
			node* tmp = pointer -> getLeft ();
            pointer->setLeft (NULL);
			delete pointer;
			return tmp;
		}
		if (pointer ->getLeft() == NULL) {
			node *tmp = pointer -> getRight();
            pointer->setRight (NULL);
			delete pointer;
			return tmp;
		}


		// node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* successor = pointer->getRight();
        while (successor->getLeft() != NULL) {
            successor = successor->getLeft();
        }
 
        // Copy the inorder successor's content to this node
        pointer->setData (successor->getData());
        pointer->setCounter (successor->getCounter());
        successor->setCounter (1);
        // Delete the inorder successor
        pointer->setRight (deleteNodeHelper(successor->getData(),pointer->getRight()));
	}
	return pointer;

}


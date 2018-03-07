#include <iostream>
#include "Tree25.h"

using namespace std;


Tree25::Tree25()
{
	head = NULL;
}

Tree25::~Tree25() {
    if (head != NULL) {
        delete head;
    }
}

void Tree25::insert (string str) {
    vector <node25 *> rvpointers;
    if (head != NULL) {
        insert(str, head, rvpointers);
        if (rvpointers.size() > 0) {
            head = rvpointers[1];
            head->setPointer (0, rvpointers[0]);
            head->setPointer (1, rvpointers[2]);
        }
    }
    else {
        head = new node25 (str);
    }
}

void Tree25::insert (string str, node25* pointer, vector<node25 *> &return_pointers)
{
    if (pointer->findIndex (str) != -1) {
        pointer->incrementCounter (str);
    }
    else if (pointer->isLeaf () ) {
        if (! pointer ->isFull()) {
            pointer->insert (str);
        }
        else { // leaf gets full
            return_pointers = pointer->split (str);
        }
    }
    else {
        //cout << "Seg fault2" << endl;
        vector <node25 *> rvpointers;
        insert (str, pointer->getInterval (str), rvpointers);
        if (rvpointers.size() > 0) {
            
            if (!pointer->isFull()) { // Case where parent is not full
                pointer -> insert (rvpointers);
            }
            else { // Case where parent is full
                return_pointers = pointer->split (rvpointers);
            }
        }
    }
}


/*
int Tree25::countInTree(node25* headz)
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
*/


void Tree25::printInOrder(node25* headz)
{
	if(headz!=NULL)
	{
        int i = 0;
        for (i = 0; i < headz->getTotal(); i++) {
            printInOrder(headz->getPointer (i));
            cout << headz->getData (i) << " " <<headz->getCounter(i) << endl;
        }
        printInOrder (headz->getPointer (i));
	}
}

void Tree25::printTree (node25* headz, string spaces) {
    if (headz != NULL) {
        int i = 0;
        for (i = 0; i < headz->getTotal(); i++) {
            printTree (headz->getPointer (i), spaces + " ");
            cout << spaces << headz->getData (i) << " " <<headz->getCounter(i) << endl;
            
            //printTree (headz->getPointer (i), spaces + " ");
        }
        printTree (headz->getPointer (i), spaces+" ");
    }
}

/*
void Tree25::sorted (node25* headz, vector <string> &list) {
	if (headz!=NULL) {
		sorted (headz->getLeft(), list);
		for (int i = 0; i < headz ->getCounter(); i++) {
			list.push_back (headz->getData());
		}
		sorted (headz->getRight(), list);
	}
}
*/

/*
int Tree25::search(string str) { return search (str, head); }

int Tree25::search(string str, node25* pointer)
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
*/

void Tree25::readInTree(string a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insert(a[i]);
	}
}

node25* Tree25::getHead()
{  return head; }


/*
vector<string> Tree25::rangeSearch (string a, string b) {
    vector <string> v;
    rangeSearches (a, b, head, v);
    return v;
}

void Tree25::rangeSearches (string a, string b, node25* pointer, vector <string> &list) {
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
*/
/*
node25* Tree25::searchNode(string str, node25* pointer)
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

void Tree25::deleteNode(string str)
{
    head = deleteNodeHelper (str, head);
}

node25* Tree25::deleteNodeHelper (string str, node *pointer) {
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
			node25* tmp = pointer -> getLeft ();
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
        node25* successor = pointer->getRight();
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
*/

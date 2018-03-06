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
    string rv = "";
    vector <node25 *> rvpointers;
    if (head != NULL) {
        insert(str, head, rv, rvpointers);
        head = new node25 (str);
        head->setPointer (0, rvpointers[0]);
        head->setPointer (1, rvpointers[1]);
    }
    else {
        head = new node25 (str);
    }
}

void Tree25::insert (string str, node25* pointer, string &rv, vector<node25 *> &return_pointers)
{
    if (pointer->findIndex (str) != -1) {
        pointer->incrementCounter (str);
    }
    else if (pointer->isLeaf () ) {
        cout << "Seg fault" << endl;
        if (! pointer ->isFull()) {
            pointer->insert (str);
            cout << "Seg fault4" << endl;
        }
        else { // leaf gets full
            string data [5];
            int i = 0;
            while(i < 4 && str < pointer->getData (i)) {
                data[0] = pointer->getData (i);
                i++;
            }
            data[i] = str;
            for (int c = i; c < 4; c++) {
                data[c+1] = pointer->getData (c);
            }
            node25* left = new node25 (data[0]);
            left->insert (data[1]);
            
            node25* right = new node25 (data[3]);
            right->insert (data[4]);
            
            rv = data[2];
            
            return_pointers.push_back (left);
            return_pointers.push_back (right);
        }
        
    }
    else {
        string returnValue = "";
        vector <node25 *> rvpointers;
        insert (str, pointer->getInterval (str), returnValue, rvpointers);
        if (returnValue != "") {
            
            if (!  pointer->isFull()) { // Case where parent is not full
                int i = 0;
                while(i < 3 && returnValue > pointer->getData (i)) {
                    i++;
                }
                
                // shift all the pointers and values over
                for (int b = 4; b >= i; b --) {
                    pointer->setPointer (b+1, pointer->getPointer (b));
                    pointer->setData (b, pointer->getData (b-1));
                }
                
                pointer->setData (i, returnValue);
                pointer->setPointer (i, rvpointers[0]);
                pointer->setPointer (i, rvpointers[1]);
            }
            else { // Case where parent is full
                string data [5];
                vector <node25 *> orderedpointers;
                int i = 0;
                while(i < 4 && returnValue < pointer->getData (i)) {
                    orderedpointers.push_back (pointer->getPointer (i));
                    data[0] = pointer->getData (i);
                    i++;
                }
                orderedpointers.push_back (rvpointers[0]);
                orderedpointers.push_back (rvpointers[1]);
                data[i] = returnValue;
                for (int c = i; c < 4; c++) {
                    orderedpointers.push_back(pointer->getPointer(c));
                    data[c+1] = pointer->getData (c);
                }
                
                node25* left = new node25 (data[0]);
                left->insert (data[1]);
                
                node25* right = new node25 (data[3]);
                right->insert (data[4]);
                
                rv = data[2];
                
                return_pointers.push_back (left);
                return_pointers.push_back (right);
            }
        }
    }
}
    /*
	if(pointer == NULL)
	{
		//cout<<"head inserted:"<<str<<endl;
		node25* tmp = new node25(str);
		head=tmp;
		//cout<<"head init"<<endl;
	}
	else
	{
		if(str > pointer->getData())
		{
			if(pointer->getRight() == NULL)
			{
				node25* tmp = new node25(str);
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
				node25* tmp = new node25(str);
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
*/


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
        for (int i = 0; i < headz->getTotal(); i++) {
            printInOrder(headz->getPointer (i));
            cout << headz->getData (i) << " " <<headz->getCounter(i) << endl;
        }
        printInOrder (headz->getPointer (headz->getTotal() +1));
	}
}

void Tree25::printTree (node25* headz, string spaces) {
    if (headz != NULL) {
        for (int i = 0; i < headz->getTotal(); i++) {
            cout << spaces << headz->getData (i) << " " <<headz->getCounter(i) << endl;
            
            printTree (headz->getPointer (i), spaces + " ");
        }
        printTree (headz->getPointer (headz->getTotal() +1), spaces+" ");
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

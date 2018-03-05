#include <iostream>
#include "BST.h"

using namespace std;


BST::BST()
{
	head = NULL;
}

BST::~BST() {
    if (head != NULL) {
        delete head;
    }
}

void BST::insert (string str) { insert(str, head); }

void BST::insert (string str, node* pointer)
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


int BST::countInTree(node* headz)
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

void BST::printInOrder(node* headz)
{
	if(headz!=NULL)
	{
		printInOrder(headz->getLeft());
		if (headz ->getCounter() > 0 )
			cout<<headz->getData()<< " "<< headz->getCounter()<< endl;
		printInOrder(headz->getRight());
	}
}


void BST::sorted (node* headz, vector <string> &list) {
	if (headz!=NULL) {
		sorted (headz->getLeft(), list);
		for (int i = 0; i < headz ->getCounter(); i++) {
			list.push_back (headz->getData());
		}
		sorted (headz->getRight(), list);
	}
}

int BST::search(string str) { return search (str, head); }

int BST::search(string str, node* pointer)
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


void BST::readInTree(string a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insert(a[i]);
	}
}

node* BST::getHead()
{  return head; }


vector<string> BST::rangeSearch (string a, string b) {
    vector <string> v;
    rangeSearches (a, b, head, v);
    return v;
}

void BST::rangeSearches (string a, string b, node* pointer, vector <string> &list) {
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


node* BST::searchNode(string str, node* pointer)
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

node* BST::findSmallNode(node* pointer)
{
	if(pointer->getLeft() == NULL && pointer->getRight() == NULL)
	{
		return pointer;
	}
	else if(pointer->getLeft()== NULL && pointer->getRight()!=NULL)
	{
		return pointer;
	}
	else 
	{
		findSmallNode(pointer->getRight());
	}

	return NULL;

}

///node* BST::findNodeBefore(node);


void BST::deleteNode(string str)
{
	//cout<<"before search"<<endl;
	node* nodeVal = searchNode(str, head);
	/*
	cout<<"after search"<<endl;

	cout<<"node val: "<<nodeVal->getData()<<endl;

	if(nodeVal == NULL)
	{
		cout<<"Cannot delete: value not found"<<endl;
	}
	*/
	if (nodeVal != NULL)
	{
		if(nodeVal->getCounter()>=1)
		{
			//cout<<"node val counter BEFORE: "<<nodeVal->getCounter()<<endl;
			nodeVal->decrementCounter();
			//cout<<"node val counter AFTER: "<<nodeVal->getCounter()<<endl;
		}
		/*
		else 
		{
			//actually deleting the node

			//for a leaf node
			if(nodeVal->getLeft() == NULL && nodeVal->getRight() == NULL)
			{
				delete nodeVal;
			}

			else if(nodeVal->getLeft() == NULL || nodeVal->getRight() == NULL)
			{

			}
			else
			{
				node* switched = findSmallNode(nodeVal);
				nodeVal->setData(switched->getData());
				nodeVal->setCounter(switched->getCounter());
				delete switched;

			}
		}
		*/
	}
}


/*
node* BST::deleteNodeHelper (string str, node *pointer) {
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
			delete pointer;
			return tmp;
		}
		if (pointer ->getLeft() == NULL) {
			node *tmp = pointer -> getRight();
			delete pointer;
			return tmp;
		}
		return pointer;
*/
/*
		// node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
*/
/*
	}
	return pointer;

}
*/

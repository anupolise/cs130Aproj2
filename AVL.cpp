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

void AVL::insert (string str) { head = insert(str, head); }

node* AVL::insert (string str, node* pointer)
{
	cout<<"INSERT: "<<str<<endl;
	//if theres nothing in the tree
	if(pointer == NULL)
	{
		node* tmp = new node(str);
		tmp->updateHeight();
		return tmp;
	}

	else
	{
		//go right
		if(str > pointer->getData())
		{
			//if there's nothing in the right subtree
			if(pointer->getRight() == NULL)
			{ 
				//pointer is the parent!
				node* tmp = new node(str);

				//set new node to right
				pointer->setRight(tmp);


                pointer->updateHeight();
				cout <<"right insert "<< pointer->getData()<< " " << pointer->getHeight() << endl;
			}

			else
			{
				pointer->setRight(insert(str, pointer->getRight()));
				pointer->updateHeight();
				//cout <<"right bef rebalace " <<pointer->getData()<< " " << pointer->getHeight() << endl;
				pointer = rebalanceTree (pointer);
				//cout << pointer->getData()<< " " << pointer->getHeight() << endl;
				pointer->updateHeight();
			}
			
		}
		//go left
		else if(str < pointer->getData())
		{
			if(pointer->getLeft() == NULL)
			{
				node* tmp = new node(str);
				pointer->setLeft(tmp);
				//cout<<"str inserted:"<<str<<endl;
				//pointer = rebalanceTree (pointer);
				pointer->updateHeight();
				cout <<" left insert " << pointer->getData()<< " " << pointer->getHeight() << endl;
				//cout << pointer->getHeight() << endl;
			}
			else
			{
				pointer->setLeft(insert(str, pointer->getLeft()));
				pointer->updateHeight();
				//cout<<"left before rebal " << pointer->getData()<< " " << pointer->getHeight() << endl;
				pointer = rebalanceTree (pointer);
				//cout << pointer->getData()<< " " << pointer->getHeight() << endl;
				pointer->updateHeight();
				//cout << pointer->getHeight() << endl;
				//cout<<"left after rebal " << pointer->getData()<< " " << pointer->getHeight() << endl;
			}
		}
        else {
            pointer->incrementCounter ();
        }
	}
	return pointer;
}

void AVL::rightRotate(node* top, node* b)
{
	node* bLeft  = b->getLeft();
	node* bRight = b->getRight();
	node* topRight =  top->getRight();

	b->setRight(top);
	top->setLeft(bRight);
	top->updateHeight();
	b->updateHeight();
}
void AVL::leftRotate(node* top, node* b) {
	node* topLeft = top->getLeft();
	node* bLeft = b->getLeft();
	node* bRight = b->getRight();
	top->setRight(bLeft);
	b->setLeft (top);
	top->updateHeight();
	b->updateHeight();
}

node* AVL::rebalanceTree (node* root) {

	int leftHeight = 0;
	if (root->getLeft() != NULL)
	{
		//root->getLeft()->updateHeight();
	  	leftHeight = root->getLeft()->getHeight();
	}
		
	int rightHeight = 0;
	if (root->getRight() != NULL)
	{   
		//root->getRight()->updateHeight();
		rightHeight = root->getRight()->getHeight();
	} 

	cout<< " right height: " << rightHeight<<endl;
	cout<< " left height: " << leftHeight<<endl;
	
	//left rotate 
	if (leftHeight - rightHeight > 1) {
		cout << "Howdy1";
		int leftleft = 0;

		int leftright = 0;
		if (root->getLeft()->getLeft() != NULL)
		{
		  	leftleft = root->getLeft()->getLeft()->getHeight();
		}
			
		int rightHeight = 0;
		if (root->getLeft()->getRight() != NULL)
		{   
			leftright = root->getLeft()->getRight()->getHeight();
		}


		if (leftleft >= leftright) {
			cout<<"left-left rotate"<<endl;
			node* temp = root->getLeft();
			rightRotate (root, root->getLeft());
			return temp;
		}
		else {
			cout<<"left-right rotate"<<endl;
			node * temp = root->getLeft()->getRight();
			leftRotate (root->getLeft(), root->getLeft()->getRight());
			root->setLeft(temp);
			rightRotate (root, root->getLeft());
			return temp;
		}
	}

	//right rotate
	else if (rightHeight - leftHeight > 1) {
		int rightright = 0;
		int rightleft = 0;
		if (root->getRight()->getLeft() != NULL)
		{
		  	rightleft = root->getRight()->getLeft()->getHeight();
		}
		if (root->getRight()->getRight() != NULL)
		{   
			rightright = root->getRight()->getRight()->getHeight();
		}


		cout << "Howdy2";

		if (rightright>=rightleft) {
			cout<<"right-right rotate"<<endl;
			node* temp = root->getRight();
			leftRotate (root, root->getRight());
			return temp;
		}
		else {
			cout<<"right-left rotate"<<endl;
			node * temp = root->getRight()->getLeft();
			rightRotate (root->getRight(), root->getRight()->getLeft());
			root->setRight(temp);
			leftRotate (root, root->getRight());
			return temp;
		}
	}
	return root;
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
        printTree (headz->getRight(), spaces+"  ");
    	//printTree (headz->getLeft(), spaces + "  ");
        cout << spaces << headz->getData () << "  " <<headz->getCounter()<<" "<<"h= "<<headz->getHeight() << endl;
        //printTree (headz->getRight(), spaces+"  ");
      	printTree (headz->getLeft(), spaces + "  ");
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
		pointer->updateHeight();
		pointer = rebalanceTree(pointer);
		return pointer;
	}
	else if (pointer->getData() > str) {
		pointer->setLeft (deleteNodeHelper(str, pointer->getLeft()));
		pointer->updateHeight();
		pointer= rebalanceTree(pointer);
		return pointer;
	}
	else if (pointer->getCounter() > 1) {
		pointer->decrementCounter();
	}
	else {
		//if the thing we delete nly has one child
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
        pointer->updateHeight();
        pointer = rebalanceTree(pointer);
	}
	return pointer;

}


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

/*
void Tree25::printTree (node25* headz, string spaces) {
    if (headz != NULL) {
        int i = 0;
        for (i = 0; i < headz->getTotal(); i++) {
            printTree (headz->getPointer (i), spaces + "  ");
            cout << spaces << headz->getData (i) << " " <<headz->getCounter(i) << endl;
            
            //printTree (headz->getPointer (i), spaces + " ");
        }
        printTree (headz->getPointer (i), spaces+"  ");
    }
}
*/
void Tree25::printTree (node25* headz, string spaces) {
    if (headz != NULL) {
        int i = 0;
        for (i = headz->getTotal(); i > 0; i--) {
            printTree (headz->getPointer (i), spaces + "   ");
            if (i == headz->getTotal()) {
                //cout << spaces << "total=" << headz->getTotal() << endl;
            }
            cout << spaces << headz->getData (i-1) << "   " <<headz->getCounter(i-1) << endl;
            
            //printTree (headz->getPointer (i), spaces + " ");
        }
        printTree (headz->getPointer (i), spaces+"   ");
    }
}


void Tree25::sorted (node25* headz, vector <string> &list) {
    
    if (headz != NULL) {
        int i = 0;
        for (i = 0; i < headz->getTotal(); i++) {
            sorted (headz->getPointer (i), list);
            for (int j = 0; j < headz ->getCounter(i); j++) {
                list.push_back (headz->getData (i));
            }
        }
        sorted (headz->getPointer (i), list);
    }
}

int Tree25::search(string str) { return search (str, head); }

int Tree25::search(string str, node25* pointer)
{
	if(pointer==NULL)
	{
		return 0;
	}
	else if (pointer->findIndex(str) == -1)
	{
		return search (str, pointer->getInterval(str));
	}
    else {
        return pointer->getCounter(pointer->findIndex(str));
    }
	return 0;
}


void Tree25::readInTree(string a[], int length)
{
	for(int i=0; i<length; i++)
	{
		insert(a[i]);
	}
}

node25* Tree25::getHead()
{  return head; }



vector<string> Tree25::rangeSearch (string a, string b) {
    vector <string> v;
    rangeSearches (a, b, head, v);
    return v;
}

void Tree25::rangeSearches (string a, string b, node25* pointer, vector <string> &list) {

    if (pointer != NULL) {
        int i = 0;
        for (i = 0; i < pointer->getTotal(); i++) {
           
            if(pointer->getData(i) >=a && pointer->getData(i)<=b){
                //cout << pointer->getData() << endl;
             
                for (int j = 0; j< pointer->getCounter(i); j++) {
                    list.push_back (pointer->getData(i));
                }
                rangeSearches (a, b, pointer->getPointer(i), list);
                //rangeSearches (a, b, pointer->getLeft(), list);
            }
            else if (pointer->getData(i) > a) {
                rangeSearches (a, b, pointer->getPointer(i), list);
            }
        }
        if (pointer->getData (i-1) < b) {
            rangeSearches(a, b, pointer->getPointer(i), list);
        }
        
    }
}



int Tree25::getTotal(node25* headz)
{
    int counter= 0;
    if(headz!=NULL)
    {
        int i=0;
        for (i = 0; i < headz->getTotal(); i++) {
            counter+=headz->getCounter(i)+getTotal(headz->getPointer (i));
        }
        counter+=getTotal(headz->getPointer (i));
    }

    return counter;
}

void Tree25::deleteNode(string str)
{
    node25* newptr = deleteNodeHelper (str, head);
    if (newptr == NULL) {
        head = NULL;
    }
    else if (newptr->getTotal () > 0){
        head = newptr;
    }
    else {
        head = newptr->getPointer (0);
    }
}

bool Tree25::borrow (string str, node25* pointer, node25* newptr, int indexFromParent) {
    //int indexFromParent = pointer->getIntervalIndex (str);
    bool borrowed = false;
    //cout << "borrow ";
    // First attempt a borrow from the left, then the right
    if (indexFromParent > 0) { // borrow from left
        node25* leftNode = pointer->getPointer (indexFromParent-1);
        if (leftNode->getTotal() > 1) {
            newptr->setData(0, pointer->getData (indexFromParent-1));
            newptr->setCounter (0, pointer->getCounter (indexFromParent-1));
            newptr->setTotal (1);
            
            node25* pushup = leftNode ->getMax();
            node25* leftNodeGreatestPointer = leftNode->getPointer (leftNode->getTotal());
            leftNode->setPointer (leftNode->getTotal(), NULL);
            leftNode->deleteVal (pushup->getData(0));
            //leftNode->setPointer (leftNode->getTotal(), NULL);
            
            pointer->setData ((indexFromParent-1), pushup->getData(0));
            pointer->setCounter ((indexFromParent-1), pushup->getCounter (0));
            
            
            newptr->setPointer (1, newptr->getPointer(0));
            newptr->setPointer (0, leftNodeGreatestPointer);
            
            pointer->setPointer (indexFromParent, newptr);
            borrowed = true;
        }
    }
    if (!borrowed && indexFromParent < pointer->getTotal()) {
        //cout << "index = " << indexFromParent << endl;
        //cout << "totalPointer = " << pointer->getTotal() << endl;
        // borrow from right
        node25* rightNode = pointer->getPointer (indexFromParent+1);
        //cout << "277" << endl;
        if (rightNode->getTotal() > 1) {
            newptr->setData(0, pointer->getData (indexFromParent));
            newptr->setCounter (0, pointer->getCounter (indexFromParent));
            newptr->setTotal (1);
            //cout << "282" << endl;
            node25* pushup = rightNode ->getMin();
            //cout << "284" << endl;
            node25* rightNodeMinimumPointer = rightNode->getPointer (0);
            //cout << "286" << endl;
            for (int i = 1; i < 5; i++) {
                rightNode->setPointer (i-1, rightNode->getPointer (i));
            }
            //cout << "290" << endl;
            rightNode->setPointer(4, NULL);
            rightNode->deleteVal (pushup->getData(0));
            //cout << "293" << endl;
            
            pointer->setData (indexFromParent, pushup->getData(0));
            pointer->setCounter (indexFromParent, pushup ->getCounter (0));
            //cout << "297" << endl;
            
            newptr->setPointer (1, rightNodeMinimumPointer);
            
            pointer->setPointer (indexFromParent, newptr);
            borrowed = true;
            //cout << "303" << endl;
        }
    }
    return borrowed;
}

node25* Tree25::merge (string str, node25* pointer, node25* newptr, int indexFromParent) {
    //int indexFromParent = pointer->getIntervalIndex (str);
    // Case 1: all nodes merge together and another empty node is returned
    if (pointer->getTotal () == 1) {
        
        //cout << "Parent has one value" << endl;
        //cout << pointer->getData (0) << endl;
        //cout << indexFromParent << endl;
        node25* rv = new node25 ();
        if (indexFromParent > 0) { // Merge with the left child node if empty node is from right side
            //cout << "Merge left single parent node " << endl;
            node25* leftNode = pointer->getPointer (indexFromParent-1);
            rv->insert (leftNode->getData(0));
            rv->setCounter (leftNode->getData(0), leftNode->getCounter (0));
            
            rv->insert (pointer->getData(0));
            rv->setCounter (pointer->getData(0), pointer->getCounter (0));
            
            rv->setPointer (0, leftNode->getPointer (0));
            rv->setPointer (1, leftNode->getPointer (1));
            rv->setPointer (2, newptr->getPointer (0));
            
            
            
            
            pointer->setCounter (0, 0);
            pointer->setTotal (0);
            pointer->setPointer (0, rv);
        }
        else { // Merge with the right child node
            node25* rightNode = pointer->getPointer (indexFromParent+1);
            
            //cout << "Merge right single parent node"<< endl;
            //cout << "total = " << rightNode ->getTotal () << rightNode->getData (0) << endl;
            
            //cout << pointer->getData (indexFromParent+1) << endl;
            
            //cout << pointer->getData(0) << endl;
            rv->insert (pointer->getData(0));
            rv->setCounter (pointer->getData(0), pointer->getCounter (0));
            
            rv->insert (rightNode->getData(0));
            rv->setCounter (rightNode->getData(0), rightNode->getCounter (0));
            
            rv->setPointer (0, newptr->getPointer (0));
            rv->setPointer (1, rightNode->getPointer (0));
            rv->setPointer (2, rightNode->getPointer (1));
            
            pointer->setCounter (0, 0);
            pointer->setTotal (0);
            pointer->setPointer (0, rv);
        }
    }
    // Case 2: total > 1 and merge left first
    else if (indexFromParent > 0) { // merge with left
        //cout << " Merge left " << endl;
        
        node25* leftNode = pointer->getPointer (indexFromParent-1);
        
        //cout << leftNode ->getData (0)<< endl;
        leftNode->insert (pointer->getData (indexFromParent-1));
        //cout << pointer->getData (indexFromParent-1)<<endl;
        leftNode->setCounter (pointer->getData (indexFromParent-1), pointer->getCounter (indexFromParent-1));
        
        leftNode->setPointer (2, newptr->getPointer (0));
        
        
        for (int i = indexFromParent; i < 4; i++ ){
            pointer->setPointer(i-1, pointer->getPointer (i));
        }
        pointer->setPointer (4, NULL);
        
        //cout << indexFromParent-1<<endl;
        pointer->setPointer (indexFromParent-1, leftNode);
        pointer->deleteVal (pointer->getData (indexFromParent -1));
    }
    else { // merge right
        //cout << " Merge right " << endl;
        node25* rightNode = pointer->getPointer (indexFromParent+1);
        //cout << "total= " << rightNode ->getTotal () << rightNode->getData (0) << endl;
        
        //cout << pointer->getData (indexFromParent+1) << endl;
        
        rightNode->insert (pointer->getData (indexFromParent));
        //cout <<"hello "<<pointer->getData (indexFromParent) << endl;
        
        rightNode->setCounter (pointer->getData (indexFromParent), pointer->getCounter (indexFromParent));
        
        //cout << " merge right " << endl;
        //cout << rightNode ->getTotal () << endl;
        
        
        rightNode->setPointer (2, rightNode->getPointer (1));
        rightNode->setPointer (1, rightNode->getPointer (0));
        rightNode->setPointer (0, newptr->getPointer (0));
        for (int i = indexFromParent; i < 4; i++ ){
            pointer->setPointer(i-1, pointer->getPointer (i));
        }
        pointer->setPointer (4, NULL);
        pointer->deleteVal (pointer->getData (indexFromParent));
    }
    return pointer;
}

node25* Tree25::deleteNodeHelper (string str, node25 *pointer) {
	if (pointer == NULL)  {
		return pointer;
	}
    
    // Case 1: current node25 does not have str
    if (pointer->getCounter (str) == -1) {
        node25* child = pointer->getInterval (str);
        int indexFromParent = pointer->getIntervalIndex (str);
        // Goes to the interval where str will be
        node25* newptr = deleteNodeHelper (str, child);
        
        // If a non empty newptr is returned then nothing major happens
        if (newptr == NULL || newptr->getTotal() > 0) {
            pointer->setPointer (indexFromParent, newptr);
        }
        // If an empty newptr is returned
        else {
            // merge or borrow
            // true if a borrow was successful
            //cout << "pointer->total () = " << pointer->getTotal() << endl;
            //cout << pointer->getData (0) << endl;
            //cout << endl;
            bool borrowed = borrow (str, pointer, newptr, indexFromParent);
            
            // Borrow failed, so merge is required
            if (!borrowed) {
                pointer = merge (str, pointer, newptr, indexFromParent);
            }
        }
    }
    // Case 2: Search came up true and counter is greater than one
	else if (pointer->getCounter(str) > 1) {
		pointer->decrementCounter(str);
	}
    // Case 3: Leaf node where counter is one
    // can just delete the value
	else if (pointer->isLeaf ()) {
        pointer->deleteVal (str);
    }
    // Case 4: non-leaf node
    else {
		// non-leaf node: Get the inorder predecessor (largest
        // in the left subtree)
        int index = pointer->findIndex (str);
        
        node25* successor = pointer->getPointer (index);
        while (!successor->isLeaf()) {
            successor = successor->getPointer (successor->getTotal ());
        }
        
        
        // Copy the inorder predecessor's content to this node
        
        int successorIndex = successor->getTotal()-1;
        pointer->setData (index, successor->getData(successorIndex));
        pointer->setCounter (index, successor->getCounter(successorIndex));
        successor->setCounter (successorIndex, 1);
        // Delete the inorder successor
        
        node25* newptr = deleteNodeHelper(successor->getData(successorIndex),pointer->getPointer(index));
        // Need to take of case with empty node
        
        // If a non empty newptr is returned then nothing major happens
        if (newptr == NULL || newptr->getTotal() > 0) {
            pointer->setPointer (index, newptr);
        }
        // If an empty newptr is returned
        else {
            // merge or borrow
            // true if a borrow was successful
            bool borrowed = borrow (str, pointer, newptr, index);
            
            // Borrow failed, so merge is required
            if (!borrowed) {
                pointer = merge (str, pointer, newptr, index);
            }
        }
    }
	return pointer;

}
                         


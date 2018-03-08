#include <iostream>
#include "node.h"
using namespace std;

node::node()
{

    data="";
    counter = 0;
    left=NULL;
    right=NULL;
    
}

node::node(string str)
{
    data = str;
    counter = 1;
    left=NULL;
    right=NULL;
    
}

node::node(string str, node* ptrL, node* ptrR)
{
    data = str;
    counter = 1;
    left=ptrL;
    right=ptrR;
    height=1;
}

node::~node () {
    //delete data;
    /*
    if (left != NULL) {
        delete left;
    }
    if (right != NULL) {
        delete right;
    }
     */
}


void node::setLeft(node *ptr){left=ptr;}
void node::setRight(node *ptr){ right=ptr;}
void node::setData(string str){ data=str;}
string node::getData(){ return data;}
node* node::getLeft(){ return left;}
node* node::getRight(){ return right;}
int node::getHeight() { return height;}
void node::setHeight(int h){ height=h;}
void node::incrementHeight(){height++;}
void node::decrementHeight(){height--;}
void node::updateHeight(){
    int leftHeight = 0;
    int rightHeight = 0;
    if (left !=  NULL) {
        leftHeight = left->getHeight();
    }
    if (right != NULL) {
        rightHeight = right->getHeight();
    }
    if(leftHeight>rightHeight)
    {
        height = leftHeight+1;
    }
    else
    {
        height = rightHeight+1;   
    }
}

int node::getCounter() { return counter; }
void node::incrementCounter() { counter++; }
void node::decrementCounter() { counter--; }
void node::setCounter(int count){ counter = count;}


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

int node::getCounter() { return counter; }
void node::incrementCounter() { counter++; }
void node::decrementCounter() { counter--; }
void node::setCounter(int count){ counter = count;}


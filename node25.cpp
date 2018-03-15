#include <iostream>
#include "node25.h"
using namespace std;

node25::node25()
{
    total = 0;
}

node25::node25(string str)
{
    data[0] = str;
    counter[0] = 1;
    total = 1;
}

/*
node25::node25(string str, node25* ptrL, node25* ptrR)
{
    data = str;
    counter = 1;
    left=ptrL;
    right=ptrR;
}*/

node25::~node25 () {
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

int node25::findIndex(string str)
{
    for(int i=0; i<getTotal(); i++)
    {
        if(str == (data[i]))
        {
            return i;
        }
    }

    return -1;
}

string node25::getData(int i) {
    //cout << "Seg" << endl;
    return data[i];
}

int node25::getCounter(string str)
{
    for(int i=0; i<SIZE; i++)
    {
        if(str == (data[i]))
        {
            return counter[i];
        }
    }
    return -1;
}

int node25::getCounter(int i)
{
    return counter[i];
}

void node25::incrementCounter(string str)
{
    for(int i=0; i<SIZE; i++)
    {
        if(str == (data[i]))
        {
            counter[i]= counter[i]+1;
        }
    }

}

void node25::incrementCounter(int i)
{
    counter[i] = counter[i]+1;
}

void node25::decrementCounter(string str)
{
    for(int i=0; i<SIZE; i++)
    {
        if(str == (data[i]))
        {
            counter[i] = counter[i]-1;
        }
    }
}

void node25::decrementCounter(int i)
{
    counter[i] = counter[i]-1;
}


void node25::setCounter(string str, int count)
{
    int index = findIndex(str);
    counter[index] = count;
}
    

void node25::setCounter (int index, int count)
{
    counter[index] = count;
}

void node25::setPointer(int index, node25 *ptr) {
    pointers[index] = ptr;
}
 
node25* node25::getPointer(int index)
{
    return pointers[index];
}
    
      
node25* node25::getInterval (string str)
{
    int i = 0;
    for (i = 0; i < total; i ++) {
        if (str < data [i]) {
            return pointers [i];
        }
    }
    return pointers [i];
}

int node25::getIntervalIndex (string str)
{
    int i = 0;
    for (i = 0; i < total; i ++) {
        if (str < data [i]) {
            return i;
        }
    }
    return i;
}

void node25::insert (string str) {
    int i = 0;
    while (i < 3 && data[i] < str && data[i] != "") {
        //cout << "Seg fault2" << i << endl;
        i++;
    }
    for (int b = 3; b > i; b --) {
        //cout << "Seg fault2" << b-1 << endl;
        setData (b, data[b-1]);
        setCounter (b, counter [b-1]);
    }
    data [i] = str;
    counter [i] = 1;
    total += 1;
}

void node25::insert (vector <node25 *> v) {
    string returnValue = v[1]->getData(0);
    int i = 0;
    while(i < 3 && returnValue > getData (i) && getData (i) != "") {
        i++;
    }
    
    // shift all the pointers and values over
    for (int b = 3; b > i; b--) {
        setPointer (b+1, getPointer (b));
        setData (b, getData (b-1));
        setCounter (b, counter [b-1]);
    }
    
    setData (i, returnValue);
    setCounter (i, v[1]->getCounter (0));
    setPointer (i, v[0]);
    setPointer (i+1, v[2]);
    total += 1;
}

//if node->count==1 && total>1 && is a leaf
//string exists 
void node25::deleteVal(string str)
{
    int index = findIndex(str);

    for(int i = index+1; i< total; i++)
    {
        data[i-1] = data[i];
        counter[i-1] = counter[i];
    }
    total--;
}


vector <node25 *> node25::split (string str) {
    vector <node25 *> return_pointers;
    string data [5];
    int i = 0;
    while(i < 4 && str > getData (i)) {
        data[i] = getData (i);
        i++;
    }
    for (int c = i; c < 4; c++) {
        data[c+1] = getData (c);
    }
    
    data[i] = str;

    node25* left = new node25 (data[0]);
    left->insert (data[1]);
    left->setCounter (data[0], getCounter (data[0]));
    left->setCounter (data[1], getCounter (data[1]));
    
    node25* right = new node25 (data[3]);
    right->insert (data[4]);
    right->setCounter (data[3], getCounter (data[3]));
    right->setCounter (data[4], getCounter (data[4]));
    
    node25* pushed_up = new node25 (data[2]);
    pushed_up->setCounter (data[2], getCounter (data[2]));
    
    if (i == 0 || i == 1) {
        left->setCounter (data[i], 1);
    }
    else if (i == 2) {
        pushed_up->setCounter (data[i], 1);
    }
    else {
        right->setCounter (data[i], 1);
    }
    return_pointers.push_back (left);
    return_pointers.push_back (pushed_up);
    return_pointers.push_back (right);
    return return_pointers;
}

vector <node25 *> node25::split (vector <node25 *> v) {
    string str = v[1] -> getData (0);
    vector <node25 *> return_pointers;
    string data [5];
    vector <node25 *> orderedpointers;
    int i = 0;
    while(i < 4 && str > getData (i)) {
        orderedpointers.push_back (getPointer (i));
        data[i] = getData (i);
        i++;
    }
    orderedpointers.push_back (v[0]);
    orderedpointers.push_back (v[2]);
    for (int c = i; c < 4; c++) {
        orderedpointers.push_back(getPointer(c+1));
        data[c+1] = getData (c);
    }
    
    data[i] = str;
    
    node25* left = new node25 (data[0]);
    left->insert (data[1]);
    left->setCounter (data[0], getCounter (data[0]));
    left->setCounter (data[1], getCounter (data[1]));
    left->setPointer (0, orderedpointers[0]);
    left->setPointer (1, orderedpointers[1]);
    left->setPointer (2, orderedpointers[2]);
    
    node25* right = new node25 (data[3]);
    right->insert (data[4]);
    right->setCounter (data[3], getCounter (data[3]));
    right->setCounter (data[4], getCounter (data[4]));
    right->setPointer (0, orderedpointers[3]);
    right->setPointer (1, orderedpointers[4]);
    right->setPointer (2, orderedpointers[5]);
    
    node25* pushed_up = new node25 (data[2]);
    pushed_up->setCounter (data[2], getCounter (data[2]));
    
    if (i == 0 || i == 1) {
        left->setCounter (data[i], v[1]->getCounter(0));
    }
    else if (i == 2) {
        pushed_up->setCounter (data[i], v[1]->getCounter(0));
    }
    else {
        right->setCounter (data[i], v[1]->getCounter(0));
    }
    return_pointers.push_back (left);
    return_pointers.push_back (pushed_up);
    return_pointers.push_back (right);
    return return_pointers;
}

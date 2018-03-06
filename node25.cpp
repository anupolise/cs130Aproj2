#include <iostream>
#include "node25.h"
using namespace std;

node25::node25()
{
    data=["","","",""];
    counter = [0,0,0,0];
    pointers = [NULL, NULL, NULL, NULL, NULL]
}

node25::node25(string str)
{
    data=[str,"","",""];
    counter = [0,0,0,0];
    pointers = [NULL, NULL, NULL, NULL, NULL]
}

node25::node25(string str, node25* ptrL, node25* ptrR)
{
    data = str;
    counter = 1;
    left=ptrL;
    right=ptrR;
}

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
    for(int i=0; i<SIZE; i++)
    {
        if(str.equals(data[i]))
        {
            return i;
        }
    }

    return -1
}

string node25::indexOf(int i)
{
    return data[i];
}

int node25::getCounter(string str)
{
    for(int i=0; i<SIZE; i++)
    {
        if(str.equals(data[i]))
        {
            return counter[i];
        }
    }
}

void node25::incrementCounter(string str)
{
    for(int i=0; i<SIZE; i++)
    {
        if(str.equals(data[i]))
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
        if(str.equals(data[i]))
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
    
 
node25* getPointer(int index)
{
    return pointers[index];
}
    
      
node25* getInterval (string str)
{
    if(str<data[0])
    {
        return pointers[0];
    }
    else if(str>data[4])
    {
        return pointers[5];
    }
    else if(str>data[0] && str<data[1])
    {
        return pointers[1];
    }
    else if(str>data[1] && str<data[2])
    {
        return pointers[2];
    }
    else if(str>data[2] && str<data[3])
    {
        return pointers[3];
    }
    else
    {
        return pointers[4];
    }
    
}


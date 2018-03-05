#include <iostream>
#include "nodeHT.h"
using namespace std;

nodeHT::nodeHT()
{
    data="";
    counter = 0;
}

nodeHT::nodeHT(string str)
{
    data = str;
    counter = 1;
}
	
void nodeHT::setData(string str){ data=str;}
string nodeHT::getData(){ return data;}

int nodeHT::getCounter() { return counter; }
void nodeHT::incrementCounter() { counter++; }
void nodeHT::decrementCounter() { counter--; }

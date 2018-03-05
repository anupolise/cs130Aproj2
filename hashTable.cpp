#include <iostream>
#include "hashTable.h"

using namespace std;


hashTable::hashTable() {
    size = 101;
	hashTbl =  new nodeHT[size];
	for(int i=0; i<size; i++) {
		hashTbl[i] =  nodeHT();
	}
}

hashTable::hashTable(int s) {
	hashTbl = new nodeHT[s];
	for(int i=0; i<s; i++) {
		hashTbl[i] = nodeHT();
	}
	size = s;
}

hashTable::~hashTable () {
    delete []hashTbl;
}



void hashTable::insert(string str) {
    int index = indexOf(str);
    if (index != -1) {
        hashTbl[index].incrementCounter ();
    }
    else {
        int startingIndex = hash (str)%size;
        int i = startingIndex;
        if(hashTbl[i].getCounter()<=0) {
            hashTbl [i].incrementCounter();
            hashTbl [i].setData (str);
        }
        else {
            i = (i+1)%size;
            while (i != startingIndex && hashTbl[i].getCounter() > 0) {
                i = (i+1)%size;
            }
        
            if(i != startingIndex) {
                hashTbl [i].incrementCounter();
                hashTbl [i].setData (str);
            }
        }
    }
}


int hashTable::countInTable()
{
    int counter = 0;
    for(int i=0; i< size; i++)
    {
        cout<<"Data: "<<hashTbl[i].getData()<<"  Count: "<<hashTbl[i].getCounter()<<endl;
        counter+=hashTbl[i].getCounter();
    }

    return counter;

}
vector <string> hashTable::sort() {
    vector <string> s;
    for (int i = 0; i < size; i++) {
        if (hashTbl[i].getData() != "") {
            for (int c = 0; c < hashTbl[i].getCounter(); c++) {
                s.push_back (hashTbl[i].getData());
            }
        }
    }
    std::sort (s.begin(), s.end());
    return s;
}

vector <string> hashTable::rangeSearch(string a, string b) {
    vector <string> s;
    for (int i = 0; i < size; i++) {
        if (hashTbl[i].getData() != "" && hashTbl[i].getData() > a && hashTbl[i].getData() < b) {
            for (int c = 0; c < hashTbl[i].getCounter(); c++) {
                s.push_back (hashTbl[i].getData());
            }
        }
    }
    return s;
}



int hashTable::search(string str) {
    int index = indexOf (str);
    if (index == -1) {
        return 0;
    }
    else {
        return hashTbl[index].getCounter();
    }
}

int hashTable::indexOf (string str) {
    int startingIndex = hash (str)%size;
    int i = startingIndex;
    if(hashTbl[i].getData()==str) {
           return i;
    }
    i = (i+1)%size;

    while (i != startingIndex && hashTbl[i].getData()!="") {

        if(hashTbl[i].getData()==str) {
            return i;
        }
        i = (i+1)%size;
    }
    return -1;
}

void hashTable::readInTable(string a[],int length) {
    for(int i=0; i<length; i++) {
        insert(a[i]);
    }
}

int hashTable::hash (string str){
    int a = 409;
    int b = 551;
    int c = 257;
    int d = 613;
    if (str.length() >= 1) {
        a = a * int(str [0]);
    }
    if (str.length() >= 2) {
        b = b * int(str [1]);
    }
    if (str.length() >= 3) {
        c = c * int(str [2]);
    }
    if (str.length() >= 4) {
        d = d * int(str [3]);
    }
    return a + b + c + d;
}

void hashTable::printTable()
{
     int counter = 0;
    for(int i=0; i< size; i++)
    {
        cout<<"index: "<< i;
        cout<<" Data: "<<hashTbl[i].getData()<<"  Count: "<<hashTbl[i].getCounter()<<endl;
 
    }

}

void hashTable::deleteValue(string str) {
    int index = indexOf (str);
    if (index != -1) {
        hashTbl[index].decrementCounter ();
    }
}

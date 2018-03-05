#ifndef hashTable_H
#define hashTable_H

#include <algorithm>
#include <vector>
#include "nodeHT.h"

class hashTable
{
	private:
		nodeHT *hashTbl;
		int size;
        int indexOf(string str);
        int hashFunction(); 
	public:
		hashTable();
		hashTable(int size);
        ~hashTable ();
        int hash(string str);

		//void sortInOrder();
		int countInTable();
		void printTable();

		vector<string> rangeSearch(string a, string b);
        vector<string> sort ();
		//int countInTable(nodeHT* head);

		int search(string str);
        void insert(string str);
		void readInTable(string a[],int length);
		void deleteValue(string str);


};
#endif

#ifndef TREE25_H
#define TREE25_H
#include "node25.h"
#include <vector>

class Tree25
{
	private:
		node25* head;
        void insert(string str, node25* head);
        int search(string str, node25* head);
        node25* searchNode(string str, node25* head);
        void rangeSearches (string a, string b, node25* pointer, vector <string> &list);
        node25* deleteNodeHelper (string str, node25* pointer);
	public:
		Tree25();
        ~Tree25();
    
		void insert(string str);
		void printInOrder(node25* headz);
        void printTree (node25* headz, string spaces);
		int countInTree(node25* head);
		int search(string str);
		void readInTree(string a[],int length);
		void deleteNode(string str);
		node25* getHead();
        vector <string>rangeSearch (string a, string b);
        void sorted (node25* headz, vector <string> &list);
};
#endif

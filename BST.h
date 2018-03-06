#ifndef BST_H
#define BST_H
#include "node.h"
#include <vector>

class BST
{
	private:
		node* head;
        void insert(string str, node* head);
        int search(string str, node* head);
        node* searchNode(string str, node* head);
        void rangeSearches (string a, string b, node* pointer, vector <string> &list);
        node* deleteNodeHelper (string str, node* pointer);
	public:
		BST();
        ~BST();
		void insert(string str);
		void printInOrder(node* headz);
        void printTree (node* headz, string spaces);
		int countInTree(node* head);
		int search(string str);
		void readInTree(string a[],int length);
		void deleteNode(string str);
		node* getHead();
        vector <string>rangeSearch (string a, string b);
        void sorted (node* headz, vector <string> &list);
};
#endif

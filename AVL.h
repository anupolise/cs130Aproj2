#ifndef AVL_H
#define AVL_H
#include "node.h"
#include <vector>

class AVL
{
	private:
		node* head;
        node* insert(string str, node* head);
        int search(string str, node* head);
        node* searchNode(string str, node* head);
        void rangeSearches (string a, string b, node* pointer, vector <string> &list);
        node* deleteNodeHelper (string str, node* pointer);
	public:
		AVL();
        ~AVL();
		void insert(string str);
		void printInOrder(node* headz);
        void printTree (node* headz, string spaces);
		int countInTree(node* head);
		int search(string str);
		void readInTree(string a[],int length);
		void deleteNode(string str);
		void rightRotate(node* top, node* b);
		void leftRotate(node* top, node* b);

		node* rebalanceTree (node* root);

		node* getHead();
        vector <string>rangeSearch (string a, string b);
        void sorted (node* headz, vector <string> &list);
};
#endif

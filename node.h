#ifndef NODE_H
#define NODE_H
using namespace std;

class node
{
	private:
		string data;
        int counter;
		node* left;
		node* right;
		int height;
	public:
		//constructor
		node();
		node(string str);
		node(string str, node* ptrL, node* ptrR);
    
        ~node();

		void setLeft(node *ptr);
		void setRight(node *ptr);
		void setData(string str);
		string getData();
        int getCounter ();
        void incrementCounter ();
        void decrementCounter();
        void setCounter(int count);
        int getHeight();
        void setHeight(int h);
        void incrementHeight();
        void decrementHeight();
        void updateHeight();
		node* getLeft();
		node* getRight();


};
#endif

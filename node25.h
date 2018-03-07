#ifndef NODE25_H
#define NODE25_H
using namespace std;
#include <vector>

class node25
{
	private:
        const int SIZE = 4;
        string data[4] = {"","","",""};
        int counter[4] = {0,0,0,0};
        node25 *pointers[5] = {NULL, NULL, NULL, NULL, NULL};
        int total;
	public:
		//constructor
		node25();
		node25(string str);
    
        ~node25();
    
        // sets the Pointer at that index
		void setPointer(int index, node25 *ptr);
    
        // sets the data at that index
        void setData(int index, string str) { data[index] = str; }
    
        // Returns the index given a string if it exists in this node25, otherwise -1
		int findIndex(string str);
    
        // Returns the string at that index
        string getData (int i);
    
        // Returns the counter at that string data
        int getCounter (string str);
    
        // Returns the counter at that string data
        int getCounter (int i);
    
        // increments the counter at that string data
        void incrementCounter (string str);
        // increments the counter at that index
        void incrementCounter (int i);
    
        // decrements the counter at that string data
        void decrementCounter (string str);
        // decrements the counter at that index
        void decrementCounter (int i);
    
        // sets the counter at that string data to the count
        void setCounter(string str, int count);
    
        // sets the counter at that index to the count
        void setCounter (int index, int count);
    
        // returns the pointer at that index
		node25* getPointer(int index);
    
        // compares str with each of the data points and returns the interval that str is between
        node25* getInterval (string str);
    
        bool isFull () { return total >= SIZE; }
    
        bool isLeaf () { return pointers[0] == NULL; }
    
        void insert (string str);
    
        void insert (vector <node25 *> v);
    
        int getTotal () { return total; }
    
        vector <node25 *> split (string str);
 
        vector <node25 *> split (vector <node25 *> v);
};
#endif

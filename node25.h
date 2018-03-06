#ifndef NODE25_H
#define NODE25_H
using namespace std;

class node25
{
	private:
        const int SIZE = 4;
		string data [SIZE];
        int counter [SIZE];
        node25* pointers [SIZE + 1];
	public:
		//constructor
		node25();
		node25(string str);
    
        ~node25();
    
        // sets the Pointer at that index
		void setPointer(int index, node25 *ptr);
    
        // sets the data at that index
		void setData(int index, string str);
    
        // Returns the index given a string if it exists in this node25, otherwise -1
		int findIndex(string str);
    
        // Returns the string at that index
        string indexOf (int i);
    
        // Returns the counter at that string data
        int getCounter (string str);
    
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
};
#endif

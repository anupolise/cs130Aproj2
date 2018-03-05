#ifndef NODEHT_H
#define NODEHT_H
using namespace std;

class nodeHT
{
	private:
		string data;
        int counter;
	
	public:
		//constructor
		nodeHT();
		nodeHT(string str);
    
    /*
        void operator = (const nodeHT &N ) {
            data = N.data;
            counter = N.counter;
        }
 */
		void setData(string str);
		string getData();
        int getCounter ();
        void incrementCounter ();
        void decrementCounter();
};
#endif

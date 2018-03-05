#include <iostream>
#include "hashTable.h"

using namespace std;

int main()
{
    string arr[13] = {"aa","js", "bb", "hs", "sdt", "sdd", "fw", "tt", "zz", "aawe", "gewt", "aa", "gg"};
    hashTable ht;
    ht.readInTable(arr, 13);
    
    
    vector <string> s = ht.sort();
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    
    //cout<<"header: "<<(ht.getHead()).getData()<<endl;
    //int countin = ht.countInTree(ht.getHead());
    //cout<<"count:"<<countin<<endl;
    
    
    vector <string> v = ht.rangeSearch ("bd", "zz");
    
    cout << "Range Search ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v)[i] << " ";
    }
    
    
    cout << endl;
    cout << endl;
    int the = ht.search("aa");
    cout<<"search aa - "<<the<<endl<<std::flush;
    
    int ben = ht.search("jj");
    cout<<"search jj - "<<ben<<endl<<std::flush;
    
    ht.deleteValue ("gg");
    ht.printTable();
    int count = ht.countInTable();
    cout<<"count in table: "<<count<<endl;
    
}

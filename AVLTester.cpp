
#include <iostream>
#include "AVL.h"

using namespace std;

int main()
{
    string arr[14] = {"aa","ja", "ba", "zz", "aa", "ab", "nn"};
    AVL binary;
    binary.readInTree(arr, 14);
    
    
    binary.printInOrder(binary.getHead());
    
    
    cout<<"header: "<<(binary.getHead())->getData()<<endl;
    int countin= binary.countInTree(binary.getHead());
    cout<<"count:"<<countin<<endl;
    
    //string* v = binary.rangeSearch ("bd", "zz");
    vector <string> v = binary.rangeSearch ("bd", "zz");
    
    cout << "Range Search ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v)[i] << " ";
    }
    
    cout << endl;
    cout << endl;
    int the = binary.search("hs");
    cout<<"search hs - "<<the<<endl<<std::flush;
    
    int ben = binary.search("jj");
    cout<<"search jj - "<<ben<<endl<<std::flush;

    binary.printTree (binary.getHead(), "");
    cout << "Begin deletion" << endl;
    binary.deleteNode("ja");
    binary.printTree (binary.getHead(), "");
    binary.deleteNode("ja");
    binary.printTree (binary.getHead(), "");
    binary.deleteNode("aa");
    binary.printTree (binary.getHead(), "");
    binary.deleteNode("aa");
    binary.printTree (binary.getHead(), "");
    binary.deleteNode("aa");
    binary.printTree (binary.getHead(), "");
    binary.deleteNode("aa");
    binary.printTree (binary.getHead(), "");
    //binary.insert ("aa");
    cout<<"delete aa"<<endl;
    binary.printInOrder(binary.getHead());
    
}

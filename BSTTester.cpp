
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    string arr[14] = {"aa","gs","gb","bb","be","hs","ja","ss","sd","as","hs","aa","ja","aa"};
    BST binary;
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


    binary.deleteNode("ja");
    binary.deleteNode("ja");
    binary.deleteNode("aa");
    binary.deleteNode("aa");
    binary.deleteNode("aa");
    binary.deleteNode("aa");
    //binary.insert ("aa");
    cout<<"dekte ja"<<endl;
    binary.printInOrder(binary.getHead());
    
}

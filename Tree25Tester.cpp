
#include <iostream>
#include "Tree25.h"

using namespace std;

int main()
{
    string arr[14] = {"aa","ja"};
    Tree25 tree;
    tree.readInTree(arr, 2);
    
    
    tree.printInOrder(tree.getHead());
    
    
    cout<<"header: "<<(tree.getHead())->getData(0)<<endl;
    
    tree.printInOrder(tree.getHead());
    
    /*
    int countin= tree.countInTree(tree.getHead());
    cout<<"count:"<<countin<<endl;
    
    //string* v = tree.rangeSearch ("bd", "zz");
    vector <string> v = tree.rangeSearch ("bd", "zz");
    
    cout << "Range Search ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v)[i] << " ";
    }
    
    cout << endl;
    cout << endl;
    int the = tree.search("hs");
    cout<<"search hs - "<<the<<endl<<std::flush;
    
    int ben = tree.search("jj");
    cout<<"search jj - "<<ben<<endl<<std::flush;

    tree.printTree (tree.getHead(), "");
    cout << "Begin deletion" << endl;
    tree.deleteNode("ja");
    tree.printTree (tree.getHead(), "");
    tree.deleteNode("ja");
    tree.printTree (tree.getHead(), "");
    tree.deleteNode("aa");
    tree.printTree (tree.getHead(), "");
    tree.deleteNode("aa");
    tree.printTree (tree.getHead(), "");
    tree.deleteNode("aa");
    tree.printTree (tree.getHead(), "");
    tree.deleteNode("aa");
    tree.printTree (tree.getHead(), "");
    //tree.insert ("aa");
    cout<<"delete aa"<<endl;
    tree.printInOrder(tree.getHead());
     */
    
}

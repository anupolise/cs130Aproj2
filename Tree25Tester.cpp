
#include <iostream>
#include "Tree25.h"

using namespace std;

int main()
{
    string arr[40] = {"aa","ja","ja", "bd", "bd", "ja", "ra", "bb", "zz", "ff", "df", "gg", "gg", "dd", "ds", "hi", "ai", "at", "as", "av", "hh", "hb", "bc", "cf", "gh", "he", "ha", "zg", "sd", "sc", "zg", "gk", "zh", "ss", "sd", "sh", "sf", "sj"};
    Tree25 tree;
    tree.readInTree(arr,37);
    
    
    //tree.printInOrder(tree.getHead());
    
    
    cout<<"header: "<<(tree.getHead())->getData(0)<<endl;
    
    tree.printTree(tree.getHead(), "");
    
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

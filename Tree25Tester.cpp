
#include <iostream>
#include "Tree25.h"

using namespace std;

int main()
{
    string arr[100] = {
        "aa", "ja","ja", "bd", "bd", "ja", "ra", "bb", "zz", "ff", "df", "gg", "gg", "dd", "ds", "hi", "ai", "at", "as", "av", "hh", "hb", "bc", "cf", "gh", "he", "ha", "zg", "sd", "sc", "zg", "gk", "zh", "ss", "sd", "sh", "sf", "sj", "gh", "bb", "hj", "uc", "vd", "qw", "wa", "po", "li", "ju", "rf", "rb", "bb", "xi", "os", "dk", "lt", "ef", "qa", "qj", "bt", "zo", "nf", "sz"};
    Tree25 tree;
    tree.readInTree(arr,37);
    
    cout<<"header: "<<(tree.getHead())->getData(0)<<endl;
    
    tree.printTree(tree.getHead(), "");
    
    cout<< "Total = " << tree.getTotal (tree.getHead()) << endl;

    cout<<"SEARCH"<<endl;

    cout<<"Searhc aa: "<<tree.search("aa")<<endl;
    cout<<"Searhc ju: "<<tree.search("ju")<<endl;
    cout<<"Searhc gg: "<<tree.search("gg")<<endl;
    
    // string arr2[40] = {"sh","ss","sd", "sf", "ra", "sc", "ss", "sd", "zh", "hb", "ha", "gk", "bd", "bd", "av", "at", "bb", "at", "as", "bc", "dd", "ds", "gh", "df", "gg", "gg", "ff", "zz", "zg", "zg", "ja", "ja", "ja", "hh", "he", "hi", "ai", "aa", "cf"};
    // for (int i = 0; i < 39; i++) {
    //     cout << "Delete " << arr2[i]<< endl;
    //     tree.deleteNode (arr2[i]);
    //     tree.printTree(tree.getHead(), "");
    //     cout << "Total = " << tree.getTotal (tree.getHead()) << endl;
    //     cout << endl;
    //     cout << endl;
    // }
    vector<string> s = tree.rangeSearch("ch","ja");

    for(int i=0; i<s.size(); i++)
    {
        cout<<s[i]<<endl;
    }
    
    tree.printInOrder(tree.getHead());
    
}

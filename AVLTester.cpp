
#include <iostream>
#include "AVL.h"

using namespace std;

int main()
{
    string arr[50] = {"aa","ja", "ba", "zz", "aa", "ab", "nn", "pp","fg","sd","fg", "lm", "tf", "rb", "yy", "ty", "af", "pp", "ij", "uu","kk","os", "tf","wd","ee"};
    AVL binary;
    binary.readInTree(arr, 25);
    
    
    binary.printInOrder(binary.getHead());
    cout << endl;
    binary.printTree (binary.getHead(), "  ");
    
    cout<<"header: "<<(binary.getHead())->getData()<<endl;
    int countin= binary.countInTree(binary.getHead());
    cout<<"count:"<<countin<<endl;
    
    

    
    cout << endl;
    cout << endl;
    int the = binary.search("fg");
    cout<<"search fg - "<<the<<endl<<std::flush;
    
    int ben = binary.search("pp");
    cout<<"search pp - "<<ben<<endl<<std::flush;


    int num = binary.search("ll");
    cout<<"search ll - "<<num<<endl<<std::flush;
    

    string arrDel[50] = {"aa","aa", "ba", "yy", "pp", "pp", "nn", "pp","uu","sd","lm", "kk", "ee","os","zz", "ab","af"};
    for(int i =0; i<17; i++)
    {
        cout<<"delete: "<<arrDel[i]<<endl;
        binary.deleteNode(arrDel[i]);
        binary.printTree(binary.getHead(),"");
        cout<<"count: "<<binary.countInTree(binary.getHead())<<endl;
    }


    vector <string> v = binary.rangeSearch ("ij", "tg");
    
    cout << "Range Search ";
    for (int i = 0; i < v.size(); i++) {
        cout << (v)[i] << " ";
    }

    vector <string> sort; 

    binary.sorted(binary.getHead(), sort);

    cout << "Sorter ";
    for (int i = 0; i < sort.size(); i++) {
        cout << (sort)[i] << " ";
    }
    
}

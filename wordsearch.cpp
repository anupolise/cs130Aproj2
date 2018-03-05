
// wordsearch.cpp
// 1/27/17
// Credits to Agrawal for the file traversal in CS24.
//


#include "wordsearch.h"

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    struct stat s;
    if((dp  = opendir(dir.c_str())) == NULL) {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        if (string(dirp->d_name) != "." && string(dirp->d_name) != "..") {
            string path = dir+"/"+string(dirp->d_name);
            getdir (dir+"/"+string(dirp->d_name), files);
            if ( stat(path.c_str(), &s) == 0 ) {
                if ( s.st_mode & S_IFREG ) {
                    files.push_back(string(dir+"/"+dirp->d_name));
                }
            }
        }
    }
    closedir(dp);
    return 0;
}

bool checkAlphaNum(string str)
{
    if (str.length() <= 0) {
        return false;
    }
    for(int i=0; i< str.length(); i++)
    {
        if(!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}


int main(int argc, char* argv[])
{
    string dir; //
    vector<string> files = vector<string>();
    hashTable wordIndex (77747);
    BST wordIndex2;
    
    if (argc < 2)
    {
        cout << "No Directory specified; Exiting ..." << endl;
        return(-1);
    }
    dir = string(argv[1]);
    if (getdir(dir,files)!=0)
    {
        //cout << "Error opening " << dir << "; Exiting ..." << endl;
        return(-2);
    }
    
    // THIS PART OF THE CODE SETS UP THE INVERTED INDEX
    
    string slash("/");
    int count = 0;
    for (unsigned int i = 0; i < files.size(); i++) {
        if(files[i][0]=='.') continue; //skip hidden files
        //cout << "OPEN " << files[i] << endl;
        ifstream fin((files[i]).c_str()); //open using absolute path
        // ...read the file..
        string word;
        while(!fin.eof()){
            count ++;
            fin>>word;
            //cout<<"       " << files[i]<<"::"<<word<<endl;
            if(checkAlphaNum(word))
            {
                for(int i = 0; i<word.length(); i++)
                {
                    word[i] = toupper(word[i]);
                }
                wordIndex.insert(word);
                wordIndex2.insert(word);
            }
           
            // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
            // Use these two strings to search/insert in your linked lists
        }
        //cout << "EOF " << files[i] << endl;
        //cout << count<<endl;
        fin.close();
    }
    
    //cout << wordIndex2.countInTree(wordIndex2.getHead());
    
    //string word_to_be_found;
    int userInput = 0;
    while (true){
        cout << "> ./main" << endl;
        cout << "> ";
        cin>>userInput;
        if(userInput == 1)
        {
             search(wordIndex, wordIndex2);
        }
        else if(userInput == 2)
        {
            insert(wordIndex, wordIndex2);
        }
        else if(userInput == 3)
        {
            deletion(wordIndex, wordIndex2);
        }
        else if(userInput == 4)
        {
            sorted(wordIndex, wordIndex2);
        }
        else if(userInput ==5)
        {
            rangedSearch(wordIndex, wordIndex2);
        }
        cout << endl;
    }
    return 0;
}

void search (hashTable &wordIndex, BST &wordIndex2) {
    //cout << endl;
    string word_to_be_found;
    cout << "> ";
    cin >> word_to_be_found;
    for(int i = 0; i<word_to_be_found.length(); i++) {
        word_to_be_found[i] = toupper(word_to_be_found[i]);
    }
    
    
    struct timeval timer_usec;
    int n = 0;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }

    n = wordIndex2.search (word_to_be_found); // BST
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    if (n > 0) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    cout << "BST: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }

    n = wordIndex.search (word_to_be_found); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
}

void insert (hashTable &wordIndex, BST &wordIndex2) {
    string word_to_insert;
    cout << "> ";
    cin >> word_to_insert;
    for(int i = 0; i<word_to_insert.length(); i++) {
        word_to_insert[i] = toupper(word_to_insert[i]);
    }
    
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    wordIndex2.insert (word_to_insert); // BST
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "BST: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    wordIndex.insert (word_to_insert); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
}


void deletion (hashTable &wordIndex, BST &wordIndex2) {
    string word_to_delete;
    cout << "> ";
    cin >> word_to_delete;
    for(int i = 0; i<word_to_delete.length(); i++) {
        word_to_delete[i] = toupper(word_to_delete[i]);
    }
    
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    wordIndex2.deleteNode(word_to_delete); // BST
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "BST: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    wordIndex.deleteValue (word_to_delete); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
}


void sorted (hashTable &wordIndex, BST &wordIndex2) {
    string path = "output.txt";
    cout<<path<<endl;


    ofstream output;
   // output.open(path);
    output.open( path, std::ofstream::out | std::ofstream::trunc);

    
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    vector <string> s1;
    wordIndex2.sorted(wordIndex2.getHead(), s1); // BST
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    cout << "BST: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s2 = wordIndex.sort(); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;


    for(int i=0; i<s1.size(); i++)
    {
        output<<s1[i]<<endl;
    }

    output<<endl;

    for(int i=0; i<s2.size(); i++)
    {
        output<<s2[i]<<endl;
    }
}


void rangedSearch (hashTable &wordIndex, BST &wordIndex2) {
    string lower, higher;
    cout << "> ";
    cin >> lower;
    cout << "> ";
    cin >> higher;
    
    for(int i = 0; i<lower.length(); i++) {
        lower[i] = toupper(lower[i]);
    }
    for(int i = 0; i<higher.length(); i++) {
        higher[i] = toupper(higher[i]);
    }
    
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s1 = wordIndex2.rangeSearch(lower, higher); // BST
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    for (int i = 0; i < s1.size(); i++) {
        cout <<s1[i]<<endl;
    }
    cout << "BST: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s2 = wordIndex.rangeSearch (lower, higher); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }

    cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
}


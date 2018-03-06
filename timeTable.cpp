
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "AVL.h"
#include <algorithm>

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */

#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>

using namespace std;

// Given a directory, return all the files in that directory
// if the directory does not exist -- report error.
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        //cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }
    
    while ((dirp = readdir(dp)) != NULL) {
        if (string(dirp->d_name) != "." && string(dirp->d_name) != "..") {
            getdir (dir+"/"+string(dirp->d_name), files);
            files.push_back(string(dir+"/"+dirp->d_name));
        }
    }
    closedir(dp);
    return 0;
}

bool checkAlphaNum(string str)
{
    for(int i=0; i< str.length(); i++)
    {
        if(!isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}


void search (hashTable &wordIndex, AVL &wordIndex2, vector <string> &v) {
    //cout << endl;
    int msecsAVL = 0;
    int msecsHT = 0;
    for (int i = 0; i < v.size(); i++) {
        struct timeval timer_usec;
        long long int timestamp_usec_before, timestamp_usec_after;
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
    
        int n = wordIndex2.search (v[i]); // AVL
        if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
                (long long int) timer_usec.tv_usec;
        }
        msecsAVL += (timestamp_usec_after - timestamp_usec_before);
        //cout << "AVL: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
    
        n = wordIndex.search (v[i]); // HT
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
        msecsHT += (timestamp_usec_after - timestamp_usec_before);
        //cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    }
    cout << "AVL " << v.size()<<" searches = " << msecsAVL << " microseconds." << endl;
    cout << "HT  " << v.size()<<" searches = " << msecsHT << " microseconds."<< endl;
}



void deletion (hashTable &wordIndex, AVL &wordIndex2, vector <string> &v) {
    int msecsAVL = 0;
    int msecsHT = 0;
    for (int i = 0; i < v.size(); i++) {
        struct timeval timer_usec;
        long long int timestamp_usec_before, timestamp_usec_after;
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
        
        wordIndex2.deleteNode(v[i]); // AVL
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
        msecsAVL += (timestamp_usec_after - timestamp_usec_before);
        
        //cout << "AVL: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
        
        wordIndex.deleteValue (v[i]); // HT
        if (!gettimeofday(&timer_usec, NULL)) {
            timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
            (long long int) timer_usec.tv_usec;
        }
        msecsHT += (timestamp_usec_after - timestamp_usec_before);
        //cout << "Hash: " << float(timestamp_usec_after - timestamp_usec_before)/1000000.0 << " s" << endl;
    }
    cout << "AVL " << v.size()<<" deletes = " << msecsAVL << " microseconds." << endl;
    cout << "HT  " << v.size()<<" deletes = " << msecsHT << " microseconds."<< endl;
}


void sorted (hashTable &wordIndex, AVL &wordIndex2) {
    
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    vector <string> s1;
    wordIndex2.sorted(wordIndex2.getHead(), s1); // AVL
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    cout << "AVL complete sort hotels-small " << timestamp_usec_after - timestamp_usec_before<< " microseconds." << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s2 = wordIndex.sort(); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    cout << "HT  complete sort hotels-small " << timestamp_usec_after - timestamp_usec_before << " microseconds." << endl;
    
}


void rangedSearch (hashTable &wordIndex, AVL &wordIndex2, int size) {

    vector <string> s1;
    wordIndex2.sorted(wordIndex2.getHead(), s1); // AVL
    int randomInd = rand()%10000;
    string lower, higher;
    lower = s1[randomInd];
    higher = s1[randomInd+size];
    //cout << lower << endl;
    //cout << higher << endl;
    struct timeval timer_usec;
    long long int timestamp_usec_before, timestamp_usec_after;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s3 = wordIndex2.rangeSearch(lower, higher); // AVL
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    for (int i = 0; i < s3.size(); i++) {
        //cout <<s3[i]<<endl;
    }
    cout << "AVL  " << size << " ranged search = " << timestamp_usec_after - timestamp_usec_before << " microseconds." << endl;
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }
    
    vector <string> s4 = wordIndex.rangeSearch (lower, higher); // HT
    if (!gettimeofday(&timer_usec, NULL)) {
        timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
        (long long int) timer_usec.tv_usec;
    }

    for (int i = 0; i < s4.size(); i++) {
        //cout <<s4[i]<<endl;
    }
    
    cout << "HT  " << size << " ranged search = " << timestamp_usec_after - timestamp_usec_before << " microseconds." << endl;
}



int main(int argc, char* argv[])
{
    string dir; //
    vector<string> files = vector<string>();
    hashTable wordIndex (77747);
    AVL wordIndex2;
    
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
    int countInsert = 0;
    int countSearch = 0;
    int countDelete = 0;
    
    int msecsAVL = 0;
    int msecsHT = 0;
    
    vector <string> randomWordsSearch;
    vector <string> randomWordsDelete;
    for (unsigned int i = 0; i < files.size(); i++) {
        if(files[i][0]=='.') continue; //skip hidden files
        //cout << "OPEN " << files[i] << endl;
        ifstream fin((files[i]).c_str()); //open using absolute path
        // ...read the file..
        string word;
        struct timeval timer_usec;
        long long int timestamp_usec_before, timestamp_usec_after;

        
        
        while(!fin.eof()){
            fin>>word;
            int searchChance = rand() % 100;
            int deleteChance = rand() % 100;
            
            if (deleteChance < 2 && countDelete < 100) {
                countDelete ++;
                randomWordsDelete.push_back (word);
            }
            if (searchChance < 2 && countSearch < 100) {
                countSearch ++;
                randomWordsSearch.push_back (word);
            }
            
            //cout<<"       " << files[i]<<"::"<<word<<endl;
            if(checkAlphaNum(word))
            {
                if (!gettimeofday(&timer_usec, NULL)) {
                    timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
                    (long long int) timer_usec.tv_usec;
                }
                
                wordIndex.insert(word);
                
                if (!gettimeofday(&timer_usec, NULL)) {
                    timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
                    (long long int) timer_usec.tv_usec;
                }
                
                if (countInsert < 100)
                    msecsHT += timestamp_usec_after - timestamp_usec_before;
                
                if (!gettimeofday(&timer_usec, NULL)) {
                    timestamp_usec_before = ((long long int) timer_usec.tv_sec) * 1000000ll +
                    (long long int) timer_usec.tv_usec;
                }
                wordIndex2.insert(word);
                if (!gettimeofday(&timer_usec, NULL)) {
                    timestamp_usec_after = ((long long int) timer_usec.tv_sec) * 1000000ll +
                    (long long int) timer_usec.tv_usec;
                }
                
                if (countInsert < 100)
                    msecsAVL += timestamp_usec_after - timestamp_usec_before;
                
                countInsert ++;
            }
            
            // Now the string "word" holds the keyword, and the string "files[i]" holds the document name.
            // Use these two strings to search/insert in your linked lists
        }
        //cout << "EOF " << files[i] << endl;
        //cout << count<<endl;
        fin.close();
    }
    
    cout << "AVL 100 inserts = " << msecsAVL << " microseconds." << endl;
    cout << "HT  100 inserts = " << msecsHT << " microseconds."<< endl;
    
    search (wordIndex, wordIndex2, randomWordsSearch);
    rangedSearch(wordIndex, wordIndex2, 10);
    rangedSearch(wordIndex, wordIndex2, 100);
    rangedSearch(wordIndex, wordIndex2, 1000);
    deletion (wordIndex, wordIndex2, randomWordsDelete);
    sorted (wordIndex, wordIndex2);
    
    return 0;
}



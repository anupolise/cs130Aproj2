// Lawrence Lim
// Anu Polisetty

// wordsearch.h
//


#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "BST.h"
#include <algorithm>

#include <time.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//#include "document.h"

int getdir (string dir, vector<string> &files);
bool makeAlphaNum(string str);

void search (hashTable &wordIndex, BST &wordIndex2);
void insert (hashTable &wordIndex, BST &wordIndex2);
void deletion (hashTable &wordIndex, BST &wordIndex2);
void sorted (hashTable &wordIndex, BST &wordIndex2);
void rangedSearch(hashTable &wordIndex, BST &wordIndex2);


int main(int argc, char* argv[]);

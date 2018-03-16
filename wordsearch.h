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
#include "AVL.h"
#include "Tree25.h"
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

void search (AVL &wordIndex2, Tree25 &wordIndex1);
void insert (AVL &wordIndex2, Tree25 &wordIndex1);
void deletion (AVL &wordIndex2, Tree25 &wordIndex1);
void sorted (AVL &wordIndex2, Tree25 &wordIndex1);
void rangedSearch(AVL &wordIndex2, Tree25 &wordIndex1);


int main(int argc, char* argv[]);

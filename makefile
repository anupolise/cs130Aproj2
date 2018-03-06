WordSearch: wordsearch.cpp BST.cpp node.cpp 
	g++ -std=c++11 BST.cpp node.cpp wordsearch.cpp -c
	g++ -std=c++11 BST.o node.o wordsearch.o -o main
TimeTable: timeTable.cpp BST.cpp node.cpp
	g++ -std=c++11 BST.cpp node.cpp timeTable.cpp -c
	g++ -std=c++11 BST.o node.o hashTable.o nodeHT.o timeTable.o -o TTmain

BST: BST.cpp node.cpp
	g++ -std=c++11 BST.cpp node.cpp BSTTester.cpp -c
	g++ -std=c++11 BST.o node.o BSTTester.o -o BSTmain

	
clean:
	rm *.o
	rm BSTmain
	rm TTmain

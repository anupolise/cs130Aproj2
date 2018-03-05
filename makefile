WordSearch: wordsearch.cpp BST.cpp node.cpp hashTable.cpp nodeHT.cpp
	g++ -std=c++11 BST.cpp node.cpp hashTable.cpp nodeHT.cpp wordsearch.cpp -c
	g++ -std=c++11 BST.o node.o hashTable.o nodeHT.o wordsearch.o -o main
TimeTable: timeTable.cpp BST.cpp node.cpp hashTable.cpp nodeHT.cpp
	g++ -std=c++11 BST.cpp node.cpp hashTable.cpp nodeHT.cpp timeTable.cpp -c
	g++ -std=c++11 BST.o node.o hashTable.o nodeHT.o timeTable.o -o TTmain

BST: BST.cpp node.cpp
	g++ -std=c++11 BST.cpp node.cpp BSTTester.cpp -c
	g++ -std=c++11 BST.o node.o BSTTester.o -o BSTmain
HT: hashTable.cpp nodeHT.cpp
	g++ -std=c++11 hashTable.cpp nodeHT.cpp hashTableTester.cpp -c
	g++ -std=c++11 hashTable.o nodeHT.o hashTableTester.cpp -o HTmain

	
clean:
	rm *.o
	rm BSTmain
	rm HTmain
	rm TTmain

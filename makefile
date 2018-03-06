WordSearch: wordsearch.cpp AVL.cpp node.cpp 
	g++ -std=c++11 AVL.cpp node.cpp wordsearch.cpp -c
	g++ -std=c++11 AVL.o node.o wordsearch.o -o main
TimeTable: timeTable.cpp AVL.cpp node.cpp
	g++ -std=c++11 AVL.cpp node.cpp timeTable.cpp -c
	g++ -std=c++11 AVL.o node.o hashTable.o nodeHT.o timeTable.o -o TTmain

AVL: AVL.cpp node.cpp
	g++ -std=c++11 AVL.cpp node.cpp AVLTester.cpp -c
	g++ -std=c++11 AVL.o node.o AVLTester.o -o AVLmain

	
clean:
	rm *.o
	rm AVLmain
	rm TTmain

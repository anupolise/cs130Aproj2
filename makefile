WordSearch: wordsearch.cpp AVL.cpp node.cpp 
	g++ -std=c++11 AVL.cpp node.cpp Tree25.cpp node25.cpp wordsearch.cpp -c
	g++ -std=c++11 AVL.o node.o Tree25.o node25.o wordsearch.o -o main
TimeTable: timeTable.cpp AVL.cpp node.cpp
	g++ -std=c++11 AVL.cpp node.cpp Tree25.cpp node25.cpp timeTable.cpp -c
	g++ -std=c++11 AVL.o node.o Tree25.o node25.o timeTable.o -o TTmain

AVL: AVLTester.cpp AVL.cpp node.cpp
	g++ -std=c++11 AVL.cpp node.cpp AVLTester.cpp -c
	g++ -std=c++11 AVL.o node.o AVLTester.o -o AVLmain

Tree25: Tree25Tester.cpp Tree25.cpp node25.cpp
	g++ -std=c++11 Tree25.cpp node25.cpp Tree25Tester.cpp -c
	g++ -std=c++11 Tree25.o node25.o Tree25Tester.o -o Tree25main
	
clean:
	rm *.o
	rm AVLmain
	rm Tree25main
	rm TTmain

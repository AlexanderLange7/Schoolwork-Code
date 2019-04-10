all:	TestAVLTree TestSimpleBST TestProper

TestAVLTree:	TestAVLTree.cpp
	g++ -std=c++11 -Wall TestAVLTree.cpp -o TestAVLTree
	
TestSimpleBST:	TestSimpleBST.cpp
	g++ -std=c++11 -Wall TestSimpleBST.cpp -o TestSimpleBST
	
TestProper:	testisproper.cpp
	g++ -std=c++11 -Wall testisproper.cpp -o TestProper
	
clean:
	rm TestAVLTree TestSimpleBST TestProper
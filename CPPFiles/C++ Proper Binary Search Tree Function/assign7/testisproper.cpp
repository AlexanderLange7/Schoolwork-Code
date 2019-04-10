#include "SimpleBST.h"
#include <cstdlib>
#include <iostream>

int main() {
  using namespace std;

  SimpleBST<int> bst;

  // randomize the same way each time
  srand(68333);

  cout << "Initial bst has " << bst.size() << " nodes" << endl;
  cout << "Tree: " << bst << endl;
  bst.printAsTree();

  cout << "\nInserting 45." << endl;
  bst.insert(45);
  cout << "Now bst has " << bst.size() << " nodes" << endl;
  cout << "Tree: " << bst << endl;
  bst.printAsTree();

  cout << "\nInserting ";
  for (int i = 0; i < 10; i++) {
    int d = rand() % 200;
    cout << d << " ";
    bst.insert(d);
  }
  cout << "\nNow bst has " << bst.size() << " nodes" << endl;
  cout << "Tree: " << bst << endl;
  bst.printAsTree();
  
  
  
  
   if(bst.isProper() == true ){
        cout << "It's Proper" << endl;
    }
    else{
        cout << "It's not Propper."<< endl;
    }
  
  //Creation of a proper tree
  SimpleBST<int> proper;
  
  // insert root of 20 
  proper.insert(20);
  proper.printAsTree();
  proper.insert(25);
  proper.insert(10);
  proper.insert(23);
  proper.insert(5);
  proper.insert(26);
  proper.insert(11);
  proper.printAsTree();
  
  
  if(proper.isProper() == true ){
        cout << "It's Proper" << endl;
    }
    else{
        cout << "It's not Propper."<< endl;
    }

   
    
//   cout << "\nCopy constructor." << endl;
//   SimpleBST<int> bst1(bst);
//   cout << "\nNew bst has " << bst1.size() << " nodes" << endl;
//   cout << "Tree: " << bst1 << endl;
//   bst1.printAsTree();

//   cout << "\nSearching." << endl;
//   cout << "bst " << (bst.contains(159) ? "does" : "does not") << " contain 159"
//       << endl;
//   cout << "bst " << (bst.contains(160) ? "does" : "does not") << " contain 160"
//       << endl;

//   cout << "\nRemoving 160 and 45." << endl;
//   bst.remove(160);
//   bst.remove(45);
//   cout << "bst " << (bst.contains(45) ? "does" : "does not") << " contain 45"
//       << endl;
//   cout << "bst " << (bst.contains(160) ? "does" : "does not") << " contain 160"
//       << endl;
//   cout << bst << endl;
//   bst.printAsTree();

//   cout << "\nClearing tree." << endl;
//   bst.clear();
//   cout << "\nNow bst has " << bst.size() << " nodes" << endl;
//   cout << "Tree: " << bst << endl;
//   cout << "bst " << (bst.contains(159) ? "does" : "does not") << " contain 159"
//       << endl;
//   cout << "bst " << (bst.contains(160) ? "does" : "does not") << " contain 160"
//       << endl;
//   cout << "\nNew bst has " << bst1.size() << " nodes" << endl;
//   cout << "Tree: " << bst1 << endl;
//   bst1.printAsTree();

//   cout << "\nAssignment operator." << endl;
//   bst = bst1;
//   cout << "\nNow bst has " << bst.size() << " nodes" << endl;
//   cout << "Tree: " << bst << endl;
//   cout<< "Is the bst proper" << bst.isProper(pRoot)<<endl;
//   bst.printAsTree();

//   cout << "\nAllocating dynamic BST and filling:" << endl;
//   SimpleBST<int> *pBst = new SimpleBST<int>();
//   for (int i = 0; i < 20; i++) {
//     pBst->insert(rand() % 200);
//   }
//   cout << "New bst has " << pBst->size() << " nodes" << endl;
//   cout << "Tree: " << *pBst << endl;
//   pBst->printAsTree();

//   cout << "Clearing and making a chain" << endl;
//   pBst->clear();
//   for (int i = 0; i < 20; i++) {
//     pBst->insert(i);
//   }
//   cout << *pBst << endl;
//   pBst->printAsTree();

//   cout << "Freeing dynamic tree." << endl;
//   delete pBst;

  return EXIT_SUCCESS;
}

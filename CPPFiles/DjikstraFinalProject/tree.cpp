//##############################################################################
/** IST 246 SEMESTER FINAL
 *  DAN MARTIN
 *  MARTIN HUANG
 *  ALEX LANGE
 *  START DATE: NOVEMBER 28, 2017
 *  COMPLETION DATE: 
 */
//############################################################################## 
/** PROJECT SUMMARY
 *      
 *      GIVEN A PARAMETER INPUT, TRAVERSE THROUGH THE MULTIPLE PATHWAYS PROVIDED
 *      BY THE PARAMETERS. FIND THE CHEAPEST ROUTE TO GET FROM START TO FINISH.
 *      AFTERWARDS, OUTPUT THE PATH YOU MUST TRAVERSE.
 * 
 */
//##############################################################################

//Import Statements
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Tree.h"

//Helper Function Declarations
/**
 * Name: addNodes
 * Purpose: Recursive method to add individual nodes to the tree object
 * The tree will represent our grid of possible moves for each tile
 * Return: void, tree is modified 
 */ 
void addNodes(std::vector<std::vector<double>> moves, Tree<int> tree, Tree<int>::Handle handle, int start, int finish);


//Main Application Entry
int main(){
    //Setup A Namespace Standard.
    using namespace std;  
    //Setup A2-D vector of doubles 
    vector<vector<double>> moves;
    
    //Open our input Textfile.
    ifstream inFile;
    inFile.open("4x4.txt");
    
    //Set up a tokenizer to read in our Input.
    string line;
    
    // add an empty node to the front
    vector<double> empty;
    moves.push_back(empty);
    
    // while there are more lines in the file
    while (getline(inFile, line)){
        // string stream object used to tokenize the line
        istringstream ss(line);
        
        // vector for the numbers in current line
        vector<double> number;
        
        // string will be used for the current string in the line
        string token;
        while(getline(ss, token, ',')) {
            // initialize n to the double value of the string
            double n = atof(token.c_str());
            // add n to vector of doubles
            number.push_back(n);
        } //End While
        // add number vector to vector of vector pointers
        moves.push_back(number);
    } //end of while more lines
    
    //User Input
    int start = 0;
    int finish = 0;
    cout << "Where is the starting location?" << endl;
    cin >> start;
    cout << "Where is the ending location?" << endl;
    cin >> finish;
    
    // Initialize tree to start tile inputed fro user
    Tree<int> tree(start);
    
    // Initialize a TreeHandle at the begining of the tree
    Tree<int>::Handle treeHandle = tree.rootHandle();
    
    addNodes(moves, tree, treeHandle, start, finish);
    Tree<int>::Node* shortest = new Tree<int>::Node();
    shortest->CurCost = 100.0;
    //tree.findShortest(finish, shortest);
    cout << shortest->CurCost << endl;
    delete shortest;
    
    return EXIT_SUCCESS;
    
}//End MAIN Method

void addNodes(std::vector<std::vector<double>> moves, Tree<int> tree, Tree<int>::Handle handle, int start, int finish) {
    using namespace std;
    if(start != finish) {
        //Here, we will set up a Cost Index to keep track of elements.
        int costIndex = 1;
        // Iterate through all possible moves for current tile
        for(double cost : moves[start]) {
        
            //If the double we are checking out is > 0, and the path doesn't have our costIndex
            if(cost > 0.0 && !tree.containsNode(costIndex, handle.node())) {
                // add to the tree
                handle.addChild(costIndex, cost);
                if(costIndex == finish) {
                    return;
                }
            } // end of if possible move
            ++costIndex;
        }// for possible moves for tile
    

        unsigned childIndex = 0u;
        for(Tree<int>::Node* i : handle.node()->children) {
            Tree<int>::Handle loc = handle.getChild(childIndex);
            addNodes(moves, tree, loc, i->tile, finish);
            ++childIndex;
        }
    } else {
        return;
    }
} //End of findShortest
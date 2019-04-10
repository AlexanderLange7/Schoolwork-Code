//##############################################################################
/** IST 246 SEMESTER FINAL
 *  DAN MARTIN
 *  MARTIN HUANG
 *  ALEX LANGE
 *  START DATE: NOVEMBER 28, 2017
 *  COMPLETION DATE: DECEMBER 2017
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
#include "DLL.h"

//Helper Function Declarations

/**
 * Name: findShortest
 * Purpose: Recursively search through all possible paths to the finish
 * Return: DLL of the shortest path to the finish
 */
void findShortest(std::vector<std::vector<double>> &moves, DLL<double> &path, DLL<double> &shortestList, int start, int finish);

/**
 * Name: comparison
 * Purpose: Make a comparison between two DLLs based on their first elements.
 * Return: DLL of the shorter of two paths.
 */
DLL<double> comparison(DLL<double> &path, DLL<double> &shortestPath);


//Main Application Entry
int main(){
    
    //Setup A Namespace Standard.
    using namespace std;  
    
    //Setup A2-D vector of doubles 
    vector<vector<double>> moves;
    
    //Open our input Textfile.
    ifstream inFile;
    inFile.open("20x20.txt");
    
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
        
        //while we still have items to add to our data structure
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
    int last = 0;
    cout << "Where is the starting location?" << endl;
    cin >> start;
    cout << "Where is the ending location?" << endl;
    cin >> last;
    
    
    
    // Doubly linked list to store the path of tiles traveled over
    DLL<double> path;
    DLL<double> shortest;
    
    // Add the starting point to our path and the max int to our list
    path.addFirst(0.0);
    path.addLast(start);
    shortest.addFirst(100);
    
    findShortest(moves, path, shortest, start, last);
    
    //Remove the Cost for a Clean Return.
    shortest.removeFirst();
    
    //Output our Results.
    cout << shortest << endl;
   
}//End MAIN Method
    




//Function Entry

/**
 * Name: findShortest
 * Purpose: Recursively search through all possible paths to the finish
 * Return: DLL of the shortest path to the finish
 */
 
 // Always call the recursive method from the shortest possible move first
 // Before using recursion check the cost of shortest path vs path 
void findShortest(std::vector<std::vector<double>> &moves, DLL<double> &path, DLL<double> &shortestList, int start, int finish) {
   
    using namespace std;
    
    // Our Base Case #1 is if our start point and endpoint are the same.
    if(start == finish){
        //Get our Shortest List
        shortestList = comparison(path, shortestList);
        return;
    } //End of Base Case 1
    
    //Set up a Cost Index to keep track of elements.
    double costIndex = 1;
    
    // Iterate through all possible moves for current tile
    for (double cost : moves[start]) {
        
        //If the vector we are checking out is >0, and the path doesn't have our costIndex
        if(cost > 0.0 && path.contains(costIndex) == -1){
                
            // Base case #2 - if the right tile has been found!
            if(costIndex == finish) {
                
                // If finish tile has been found add to list and set shortestList
                path.addLast(costIndex);
                // iniCost used to keep the original cost of path
                double iniCost = path.getFirst();
                // update the cost of path
                path.setFirst(iniCost + cost);
                // set shortestList to the result of comparison function (Which is th shortestList)
                shortestList = comparison(path, shortestList);
                //Now that our shortest list is the shortest, we remove a node so we can make more recursions thtrough at the correct node.
                path.removeLast(); 
                // set path's cost back to initial cost before comparison
                path.setFirst(iniCost);
                // Return ending the current recursion
                return;
                
            }//End Base Case 2
            else {
                //recursive case - call findShortest for next tile
                //Add The Tile to the end of our list.
                //If shortestList's cost to hit the end was smaller than the path we are working with, skip traversal.
                if(shortestList.getFirst() < path.getFirst()){
                //Do Nothing.
                }
                else {
            
                    //Add our new tile to the path 
                    path.addLast(costIndex);
                    //Update our Path Cost
                    double iniCost = path.getFirst();
                    path.setFirst(iniCost + cost);
                    //Recurse and Look for another tile to add to the path
                    findShortest(moves,path,shortestList, costIndex,finish);
                    //Now that our shortest list is the shortest, we remove a node so we can make more recursions thtrough at the correct node.
                    path.removeLast();
                    //Set the path's cost to it's initial value prior to our comparison
                    path.setFirst(iniCost);
                    
                } // end else 
                
                
            }//end else statemenst
            
        } // end of if possible move (cost > 0)
        
        // Increment costIndex to check the next possible tile 
        ++costIndex;
            
    } // for possible moves for tile
    
} //End of findShortest


/**
 * Name: comparison
 * Purpose: Make a comparison between two DLLs based on their first elements.
 * Return: DLL of the shorter of two paths.
 */
DLL<double> comparison(DLL<double> &path, DLL<double> &shortestPath) {
    
    //If the first value of a path we just made is less than the amount in our shortest path,    
    if(path.getFirst() < shortestPath.getFirst()){
        return path;
    } else {
        return shortestPath;
    }

} //End of comparison




//CHANGELOG

//##############################################################################
/**
 * 12/3/2017
 * 
 * Worked from 10 AM to Noon. Discussion on how to find all possible traversals
 * and output the cheapest one.
 * 
 * Plans for next time:
 * work on findShortest method
 * work on tree.h modifications
 * 
 */
 //#############################################################################
/**
 * 12/5/2017
 * 
 * Worked from 7PM to 8:30. Worked on modifying Tree.h to add children by using 
 * the values in our vectors and finding the shortest path using a method. 
 * 
 * Post-Work: We went to the MeysenMan for assistance because we didn't know 
 * where to go now. So we've switched to using DLL's I believe.
 */
 //#############################################################################
/**
 * 12/6/2017
 * Worked from 6:20 to 8:20. Decided on using doubly linked lists instead of trees
 * to hold our parameters. It will be easier to work with, and it will be
 * an easy printout afterward.
 * 
 * 
 */
 //#############################################################################
/**
 * 12/9/2017
 * Worked from 1:30 to ?. Worked on findshortest method. Added a second DLL in
 * order to make the method more simple. Whenever the cost of a new path is
 * found to be shorter than our shortest, just replace our entire shortest list.
 * 
 * Maybe we make a comparison function separate from our findshortest
 * 
 * Created helper methods comparison and final check to clean up our code block
 * We are dying right now. Need to unravel, go back, and continue through.
 * 
 * 
 * 
 */
 //#############################################################################
 /**
  * 12/10/17
  * Worked on DLL method of solving problem
  * Changed the return type on findShortest 
  * 
  */
  //############################################################################
 /**
  * 12/13/2017
  * Got the program to work with 12x12. Did a little formatting. Martin turned
  * in the version that works with 4x4 quick. Alex turned in an iteration that
  * gets 4x4 and 12x12 to work pretty quick. We're looking through for a verson
  * that works for 20x20. If not, what we've turned in should be good.
  * 
  * 
  * 
  */
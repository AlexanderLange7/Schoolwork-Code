/**
 *  This file will implement our SLL and use it to generate random poems with a
 * dictionary that we inject into a list.  Based on user input, we will create
 * poems using a getRandom method, and will repeat the process based on user
 * input.
 * 
 * Alex L, Alex S
 * 9/06/2017
 * 
 * 
 */

/**
 * This is a list of all our libraries we will include.
 */ 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "SimpleSLL.h"

/**
 * This is our main method.
 * We will start by seeding our randum number generator. The reason we don't 
 * seed it in the getRandom method is because we would accidentally seed our
 * generator multiple times, and thus get the same pseudo-random word over and
 * over.
 */

int main(){
	using namespace std;
	srand(time(0));


    /**
     * We'll start by creating a simple interface for the user to follow. A 
     * short introduction as well as a description of what the program must do
     * before they can start will be fine.
     */
    std::cout << "Welcome to the random poetry generator!"	<< endl;
    std::cout << "Please wait for the dictionary to load." << endl;
	
    /**
     * Next, we're going to use our input file streaming library to open our 
     * dictionary file, and then follow up by creating a Singly-Linked List.
     */
    ifstream inFile;
    inFile.open("dictionary.txt");
    SimpleSLL randompoet;

    /**
     * Using a simple while loop, we can fill our Singly-Linked list with a copy
     * of every word from our dictionary.
     */
    string b1;
    while (inFile >> b1) {
        randompoet.add (b1);
    }

    /**
     * Next, we're going to declare a variable. This variable, which we will
     * give the arbitrary name 'continuation', will be used to check for whether
     * or not the user would like to continue to generate more random poems
     * after the first one, by using a while loop that checks the value of our
     * variable.
     */
    int continuation = 1;
    while (continuation == 1){

       /**
        * Now we are in our poem loop. Using the cin command, we can let users
        * input varziables in order to customize our poem, such as number of
        * lines, and size of lines.
        * 
        */
        
        std::cout << "Let's Make some Poetry dude! Enter the number of lines:"; 
        int noflines;
        cin >> noflines;
        
        
        std::cout << endl << "Radical! Now, enter the number of words per line.";
        int wpline;
        cin >> wpline;
        
        
        /**
         * After the user has input their options, the program will generate
         * the poem using the variables that the user input. For each line, we
         * will generate a word based on the amounts of words per line, as the
         * user requested.
         */
         
        std::cout <<endl << "Here's your poem, man!" << endl << "\t";
        //This line reads through the number of lines the user requested.
        for(int i = 0; i < noflines; i++){
            //This line reads through the number of words per line.
            for(int i = 0; i < wpline; i++){
                string randoword = randompoet.getRandom();
                std::cout << randoword << " ";
            }
            
            //End the line after all random words have been placed in it.
            std::cout << endl << "\t";
        }
        
        /**
         * Thus, a random poem has been generated. Finally, we will ask if they
         * would like to continue to generate poems, and based on their input,
         * we may or may not run through the while loop again.
         * 
         */
        std::cout << "Would you like to make another poem? enter 1 for yes, 0 for no.";
        cin>> continuation;
    }
        
    return EXIT_SUCCESS;
        
}



#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Program to analyze the frequency of each number in PowerBall lottery
 * drawings.
 *
 * <Alex, John>
 * <Monday, the 240th day of 2017 @ 1:30PM.>
 */
 
int main() {
	using namespace std;
	
	// open input file
	ifstream inFile;
	inFile.open("numbers.txt");
	
	// read numbers, one line at a time
	int b1, b2, b3, b4, b5, b6;

	//First, we made an array outside of our loop. We can use this array to
	//Keep track of how many times each number is read.
    int* array = new int[59];


	while  ( inFile >> b1 ) {
		inFile >> b2;
		inFile >> b3;
		inFile >> b4;
		inFile >> b5;
		inFile >> b6;

		// TODO: replace this output code with your code to count
		// the frequency of each number
		
		//So we're going to take whatever we find at each ball number and increment
		//that spot in our array, so we can keep track of how many times we've seen that number
		array[b1-1] = array[b1-1]+1;
		array[b2-1] = array[b2-1]+1;
		array[b3-1] = array[b3-1]+1;
		array[b4-1] = array[b4-1]+1;
		array[b5-1] = array[b5-1]+1;
		array[b6-1] = array[b6-1]+1;
		
	}

	inFile.close();

	// TODO: output the frequency for each number, as described in the
	// assignment
	
	
	//for this, we will start with a count of one, and then loop equal to our
	//array length, where in each instance, we write what number we are on, and
	//how many times that number was counted.
	int count = 1;
	for(int i = 0; i < 59; i++){
		
		std::cout << count << "\t" << array[i] << endl;
		count +=1;
	}

	return EXIT_SUCCESS;
}
/**
 * Empirically Demonstrate the Time Complexity of the Binary Search Algorithm
 * 
 * Write two functions for a binary search - One iterative, One Recursive.
 * 
 * Instead of returning the key index where the number is located, return the #
 * of comparisons in order to complete.
 * 
 * Alex, Martin 
 * October 11th, 2017
 * 
 */
 
 // Include Statements
#include <cstdlib>      //
#include <algorithm>    // Used for STL Sorting
#include <chrono>       // Used for Seeding PRNG
#include <iostream>     //
#include <random>       // Used for Mersenne Twister PRNG


//This is our recursive Binary Search.   
int rSearch(int *sortedArr, int low, int high, int key){
    //Implement a counter.
    //Flag is our midpoint we decide on
    int flag = ((low + high) /2);
    if(sortedArr[flag] == key || high<low){
        return 1;
    }
    //If our flag is greater, we will work with the left side of our split.
    else if(sortedArr[flag]>key){
          return 2+rSearch(sortedArr,low,flag-1,key);
    }
    //If our flag is less than our key we will work with the right side.
    else {
         low = flag;
         return 3+ rSearch(sortedArr, low + 1, high, key);
    }
}//END RECURSIVESEARCH 
    
//This is our Iterative Binary Search.
int iSearch(int *sortedArr, int low, int high, int key){    
    int flag = 0;
    //Go through and chack to see if it's there.
    int i = 0;
    while(high>=low){
        flag = (low+high)/2;
        i+=1;
        if (sortedArr[flag] > key){
            high = flag - 1;
            i+=1;
        }
        else if(sortedArr[flag]<key){
            low = flag + 1;
            i+=2;
        }
        else{ 
            i+=3;
        }
    }
return i;
}//END ITERATIVESEARCH

//MAIN METHOD
int main(){
    using namespace std;
   
    //First, we will make our Random Number Generator.
    mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
   
   //Next, we will have a for loop. In each loop, we will make an Array to work
   //with, starting with 6.
    for(int n = 64; n <= 134217728; n *= 2){
   
        //Here's a list of some of our more important variables that we will use in our work.
        double recursivecomp = 0;
        double iterativecomp = 0;
        //int n = 2^i;
        int *pA = new int[n];
        int a = 0;
        int b = 0;
        double val = ceil(log2(n));
   
        // Next, we'll fill our array with random numbers
        for(int j = 0; j< n; j++) {
            pA[j] = prng();    
        }
   
        //Now, we sort the array we're working with.
        sort(pA, pA+n);     
   
         //This next part is going to be where we call our binary searches, both iterative and recursive.
        //We will perform each 1000 times, and count the number of comparisons done by each.
        for(int k = 0; k<1000; k++){
            a = rSearch(pA, 0, n - 1, prng());
            recursivecomp+=a;
        }
        for(int l = 0; l<1000; l++){
            b= iSearch(pA, 0, n - 1, prng());
            iterativecomp+=b;
        }
        recursivecomp = recursivecomp/1000;
        iterativecomp = iterativecomp/1000;
   
        //If we're still on our first time through the loop, we put our header.
        if(n==(64)){
            cout<<"n"<<"\t"<<"iter"<<"\t"<<"recur"<<"\t"<<"log(n)"<<endl;
        }
    
   
        //Next we output our data for our runthrough.
        cout<<n<<"\t"<<iterativecomp<<"\t"<<recursivecomp<<"\t"<<val<<endl;
    
        //Finally we delete our array and go through it again if necessary.
        delete [] pA;
    }//END FOR LOOP
}//END MAIN METHOD
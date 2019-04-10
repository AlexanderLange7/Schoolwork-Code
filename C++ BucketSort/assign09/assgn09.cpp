#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <list>
#include <random>
#include <vector>

using namespace std;

/**
 * Determine if an array of unsigned integers is sorted in ascending order.
 * 
 * \param pArr Pointer to the first element of the array.
 * \param n Number of elements in the array.
 * \return true if the array is sorted in ascending order, false otherwise.
 */
bool isSorted(unsigned *pArr, unsigned n) {
    for(unsigned i = 0u; i < n - 1u; i++) {
        if(pArr[i] > pArr[i + 1u]) {
            return false;
        }
    }
    return true;
}











/**
 * Sort an array of unsigned integers using bucket sort.
 * 
 * Alex, Logan, Martin
 * 11/20/2017
 */

void bucketSort(unsigned *pArr, unsigned n) {
    //First, we will Create An Array which contains pointers to Vectors
    vector<unsigned>** ppBucket = new vector<unsigned>*[256];
    
    //Go through the buckets
    for(unsigned i = 0u; i <256u; i++){
    //Initialize Vectors in each bucket
        ppBucket[i] = new vector<unsigned>();  
    }
    
        //Find the relevance of the value at j and place at that index?
        for (unsigned j = 0; j < n; j++){
            //Do some bitshift to find relevance
            unsigned pushin = pArr[j]>>24;
            //Add our element to our bucket at pushin index.
            ppBucket[pushin]->push_back(pArr[j]);
        }
           
            //Sort the buckets
            for(int i = 0; i<256; i++){
            sort(ppBucket[i]->begin(), ppBucket[i]->end());
            }
    
    //Loop through the buckets
    int index = 0;
    for(unsigned j = 0; j < 256; j++) {
        for(unsigned i : *ppBucket[j]) {
            //Insert the elements one at a time back into the array.
            pArr[index++] = i;
        }
    }
    
    
    
    //##For whatever reason, the code gave us a segmentation fault for our add back in.##
    /*for (unsigned i=0; i<n; i++){
        for(unsigned j = 0; j < ppBucket[i]->size();j++ ){
            //Starting at pArr[0], add each elemet back into the array from the buckets.
            pArr[index] = (*ppBucket[i])[j];
            index++;
        }
    }*/
    
    for(unsigned i = 0u; i < 256u; i++){
        //Delete our buckets since we have finished using them.
        delete ppBucket[i];
        }
    //Delete our ppBucket array
    delete[]ppBucket;
}
    




















/**
 * Application entry point.
 */
int main() {
    // Mersenne Twister PRNG
    mt19937 prng(chrono::system_clock::now().time_since_epoch().count());
    
    // size of arrays
    unsigned n = 10000000u;

    // create two arrays of size n
    unsigned *pArr1 = new unsigned[n];
    unsigned *pArr2 = new unsigned[n];

    // fill with identical pseudo-random values
    for(unsigned i = 0u; i < n; i++) {
        pArr1[i] = prng();
        pArr2[i] = pArr1[i];
    }
    
    sort(pArr1, pArr1 + n);     // sort 1st array with STL sort
    bucketSort(pArr2, n);       // sort 2nd array with bucketSort

    // output success or failure of each sort
    cout << "Array 1 " << (isSorted(pArr1, n) ? "is" : "is not") << " sorted." << endl;
    cout << "Array 2 " << (isSorted(pArr2, n) ? "is" : "is not") << " sorted." << endl;

    // free memory
    delete [] pArr1;
    delete [] pArr2;
    
    return EXIT_SUCCESS;
}
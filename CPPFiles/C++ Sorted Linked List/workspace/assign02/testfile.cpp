#include "SortedSSL.h"
#include <fstream>
#include <iostream>
#include <string>

/**
 * IST 246 Assignment 02 program: Sorted Linked List
 * 
 * Program to test the functionality of the add function of SortedSLL.h
 * 
 *
 * \Ashby Mullin
 * \Alex Lange
 * \15 September 2017
 */

int main(){
    using namespace std;
    
    //instantiates SimplyLinked List
    SLL < int > checker;
    
    
    //uses sorted add to add items to the list
    checker.add(0);
    checker.add(4);
    checker.add(8);
    checker.add(30);
    checker.add(2);
    checker.add(1);
    
    //prints out the list showing the list is in 
    cout << checker << endl;
    
    //Insttantiates a string-typed list.
    SLL<string> list;
    
    //use our new sorted add method to add items to our list
    list.add("bob");
    list.add("carol");
    list.add("ted");
    list.add("alice");
    list.add("franklin");
    list.add("zephyr");
    list.add("ashby");
    
    //Print our list
    cout << list << endl;
}
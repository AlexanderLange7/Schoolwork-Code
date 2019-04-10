#pragma once

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <string>

/**
 * Class representing a simple singly-linked list of integers.
 * This Class makes our SLL. It's our header, and will be used as a template.
 * All of the coding for each method that's more than one line will be done in
 * the CPP file for it. The reason that we can keep one-liner methods in here is
 * because they essentially just replace the word for their method with the 
 * one-liners everywhere else in the code, thus significantly speeding the code
 * up.
 * 
 * Alex S, Alex L
 * 9/06/2017
 */
class SimpleSLL
{
private:

/**
 * The following class will represent all of the nodes in our singly linked list.
 */
  class Node
  {
  public:

// This default constructor makes a node without any specs.
  Node ():data (0), pNext (0)
    { }

// Constructor makes a node with specific specs that one would input.
    Node (std::string d, Node * pN):data (d), pNext (pN)
    { }

    std::string data;
	   //This is the "payload" of our node, basically what we want from it.

    Node *pNext;
	     //pNext is the pointer to the next node of our list. In the exent that it
	     //is on the last node, it is set to zero.
  };

public:

//This is the default constructor of our list. Make an empty list.
SimpleSLL ():pHead (0), n (0u)
  { }

// Destructor. Delete the contents of our list.
  ~SimpleSLL ();

/**
 * The following is a list of all of our methods we can call for our list.
 * 
 */ 

//The add method adds a value to the front of the list.
  void add (std::string i);

//The clear method removes all the elements of the list.
  void clear ();

//The contains method will determine if a specific value is in the list.
  int contains (std::string i) const;

//The get method will get the value at a specified location.
  std::string get (unsigned idx) const;

//IsEmptu will determine if the list is empty.
  bool isEmpty () const
  {
    return size () == 0u;
  }

//The remove method will remove the value at a specified location.
  std::string remove (unsigned idx);

//The print method will print the contents of this list to the standard output.
  void print () const;

//The setter will change the value at a specified index to another value.
  void set (unsigned idx, std::string i);



//This GetRandom Method will get random words from our list based on an int.
//We define it here, and code it in the cpp file, since it's a little longer.
  std::string getRandom() const;


//The size method will get the number of integers in the list.
 
  unsigned size () const
  {
    return n;
  }


//This is where we set up our first node.
private:

    Node * pHead;    /**< Pointer to the first Node in the list, or 0 if
			       the list is empty. */
  unsigned n;		    /**< Number of strings in the list. */
};


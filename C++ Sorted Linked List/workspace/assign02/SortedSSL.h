#pragma once

#include <iostream>
#include <stdexcept>

/**
 * This class is our template for the Singly Linked Lists. We are going to 
 * modify the add method to sort our list as elements are being added to it.
 * 
 * Alex, Ashby
 * 9/12/2017
 * 
 */
template <class T> class SLL {
private:
  /**
   * The following is a nested class which will represent each node in our
   * linked list.
   */
  class Node {
  public:
    /**
     * Default constructor. Make a new Node with default data
     * and next pointer set to zero.
     */
    Node() : data(), pNext(0) {}

    /**
     * Initializing constructor. Make a new Node with the specified
     * data and next pointer values.
     *
     * \param d Data value of type T for the node.
     *
     * \param pN Pointer to the next Node in the list, or 0 if
     * this is the last Node.
     */
    Node(T d, Node *pN) : data(d), pNext(pN) {}

    /** Type T payload of the Node. */
    T data;

    /** Pointer to the next Node in the list, or 0 if last node. */
    Node *pNext;
  };

public:
  /**
   * Default constructor. Make an empty list.
   */
  SLL() : pHead(0), n(0u) {}

  /**
   * Copy constructor. Make a new list just like the parameter.
   *
   * \param list SLL to copy
   */
  SLL(const SLL<T> &list);

  /**
   * Destructor. Delete the contents of this list.
   */
  ~SLL() { clear(); }

  /**
   * Add a value to the front of the list.
   *
   * \param d Value to add to the list.
   */
  virtual void add(const T &d);

  /**
   * Remove all the elements of the list.
   */
  void clear();

  /**
   * Determine if a specific value is in the list.
   *
   * \param key Value of type T to search for.
   *
   * \return Index of first occurrence of key in the list, or
   * -1 if it is not in the list.
   */
  int contains(const T &key) const;

  /**
   * Get the value at a specified location.
   *
   * \param idx Index of the value to get.
   *
   * \return Value at location idx in the list
   */
  T &get(unsigned idx) const;

  /**
   * Determine if this list is empty.
   *
   * \return true if the list is empty, false otherwise.
   */
  bool isEmpty() const { return size() == 0u; }

  /**
   * Remove the value at a specified location.
   *
   * \param idx Index of the element to remove.
   *
   * \return Value that was in location idx.
   */
  T remove(unsigned idx);

  /**
   * Change the value at a specified index to another value.
   *
   * \param idx Index of the value to change.
   *
   * \param d New value to place in position idx.
   */
  void set(unsigned idx, const T &d);

  /**
   * Get the number of elements in the list.
   *
   * \return The number of elements in the list.
   */
  unsigned size() const { return n; }

  /**
   * Override of the assignment operator for SLL objects.
   *
   * \param list SLL to copy.
   */
  SLL<T> &operator=(const SLL<T> &list);

  /**
   * Override of the stream insertion operator for SLL objects.
   *
   * \param out ostream object to output to, e.g., cout
   *
   * \param list SLL to output
   *
   * \return the out ostream object
   */
  friend std::ostream &operator<<(std::ostream &out, const SLL<T> &list) {
    out << "[";

    // initialize cursor to the head of the list
    Node *pCurr = list.pHead;

    // iterate through the list
    while (pCurr != 0) {
      out << pCurr->data;

      // output no comma for last element
      if (pCurr->pNext != 0) {
        out << ", ";
      }
      pCurr = pCurr->pNext;
    }
    out << "]";

    return out;
  }

private:
  /**
   * Private helper method: make this list just like the parameter list.
   *
   * \param list SLL to copy.
   */
  void copy(const SLL<T> &list);

  /** Pointer to the first Node in the list, or 0 if list is empty. */
  Node *pHead;

  /** Number of elements in the list. */
  unsigned n;
};

//-----------------------------------------------------------
// function implementations
//-----------------------------------------------------------

/*
 * Copy constructor
 */
template <class T> SLL<T>::SLL(const SLL<T> &list) : pHead(0), n(0u) {
  copy(list);
}

/*
 * Assignment operator.
 */
template <class T> SLL<T> &SLL<T>::operator=(const SLL<T> &list) {
  copy(list);
  return *this;
}

/**
 * The following is our new add method, which will add anything that goes into
 * the list into a sorted order instead of directly.
 */
template <class T> void SLL<T>::add(const T &d) {

  //First we're going to create our cursors
  Node *pCurr = pHead, *pPrev = 0;
  Node *pN = new Node(d, 0);
  
  /**
   * For our first special scenario, we will check to see if our list is empty.
   * If it is, we will insert into the beginning of our singliy linked list.
   */
  if(pHead == 0) {
    //If the head is null, we set the head to point at our new node pN.
    pHead = pN;
    //Next we will increment our list's size.
    n++;
  } 
  //In the event our head was not zero, we will move on to our next two scenarios.
  else {
    //While our pCurr is not null, and the data of our new node is greater than 
    //pCurr, we will inch up the list.
    while(pCurr != 0 && pN->data > pCurr->data) {
      //We inch up the list by setting our pPrev pointer to where pCurr is pointing,
      //and setting pCurr's pointer to the node its pNext is pointing to.
      pPrev = pCurr;
      pCurr = pCurr->pNext;
    }
    
    //In the event that our pPrevious pointer is null after we've tried to inch up
    //the list, we will simply set our pN's pNext to pHead, and pHead will point to pN,
    //thus inserting it at the beginning of the list. This is our second special scenario.
    if(pPrev == 0) {
      pN->pNext = pHead;
      pHead = pN;
    } 
    //If pPrev is not zero, we will set pN's pNext to the node pCurr is pointing at,
    //and we will take the pointer of the node pPrev is seeing, and move it onto pN. 
    //This scenario is when we have to insert anywhere that isn't at the beginning
    //of the list when the list isn't empty.
    else {
      pN->pNext = pCurr;
      pPrev->pNext = pN;
    }
    //Finally, we increment our list size again for either of these two scenarios.
    n++;
  }

}

/*
 * Delete all list nodes.
 */
 template <class T> void SLL<T>::clear() {
  // create cursors
  Node *pCurr = pHead, *pPrev = 0;

  // iterate through the list
  while (pCurr != 0) {
    // "inchworm" up to next node
    pPrev = pCurr;
    pCurr = pCurr->pNext;

    // delete previous node
    delete pPrev;
  }

  // reset head pointer and size
  pHead = 0;
  n = 0u;
}

/*
 * Search the list for element key.
 */
template <class T> int SLL<T>::contains(const T &key) const {
  // create cursors
  int idx = -1;
  Node *pCurr = pHead;

  // iterate until we find key or end of list
  while (pCurr != 0) {
    idx++;
    // hit? return index
    if (pCurr->data == key) {
      return idx;
    }

    pCurr = pCurr->pNext;
  }

  // not found
  return -1;
}

/*
 * Copy elements from another list into this one,
 * first removing current elements.
 */
template <class T> void SLL<T>::copy(const SLL<T> &list) {
  // any existing data
  clear();

  // initialize cursors, one for parameter and
  // one for this list
  Node *pL = list.pHead, *pCurr = pHead;

  // iterate through nodes in parameter list
  while (pL != 0) {
    // special case: first node changes head pointer
    if (pHead == 0) {
      pHead = new Node(pL->data, 0);
      pCurr = pHead;
    } else {
      // general case: add new node to end of this list
      pCurr->pNext = new Node(pL->data, 0);
      pCurr = pCurr->pNext;
    }

    n++;
    pL = pL->pNext;
  }
}

/*
 * Get value at location idx.
 */
template <class T> T &SLL<T>::get(unsigned idx) const {
  // initialize cursor
  Node *pCurr = pHead;

  // if the access is past list end, throw an exception
  if (idx >= n) {
    throw std::out_of_range("Index out of range in SLL::get()");
  }

  // iterate cursor to postion
  for (unsigned i = 0u; i < idx && pCurr != 0; i++) {
    pCurr = pCurr->pNext;
  }

  // return requested value
  return pCurr->data;
}

/*
 * Remove node at location idx.
 */
template <class T> T SLL<T>::remove(unsigned idx) {
  // initialize cursors
  Node *pCurr = pHead, *pPrev = 0;

  // if the access is past list end, throw an exception
  if (idx >= n) {
    throw std::out_of_range("Index out of range in SLL::remove()");
  }

  // iterate cursors to position
  for (unsigned i = 0u; i < idx && pCurr != 0; i++) {
    pPrev = pCurr;
    pCurr = pCurr->pNext;
  }

  // save value of node we're deleting
  T d = pCurr->data;

  // first element? change head pointer
  if (pCurr == pHead) {
    pHead = pCurr->pNext;
  } else {
    // general case: "wire around" node
    pPrev->pNext = pCurr->pNext;
  }
}
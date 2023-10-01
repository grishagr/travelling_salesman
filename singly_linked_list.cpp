/**
 * Methods and helper functions of class singly_linked_list
 * @file singly_linked_list.cpp
 * @author Grisha Hatavets
 * @date December 5, 2022
 */

// CITE: Lab 11 singly_linked_list.cc
// DESC: Template for singly_linked_list methods.

#include <iostream>
#include "singly_linked_list.h"

/**
 * No-argument constructor
 */
singly_linked_list::singly_linked_list() {
   _head = nullptr;
   _tail = nullptr;
   _size = 0;
}

/**
 * Destructor
 */
singly_linked_list::~singly_linked_list() {
   clear();
}

/** 
 * Gets the Node at the given index of the linked list (a helper function)
 * @param index the index of the Node to return
 * @return (a pointer to) the Node at the given index.
 */
singly_linked_list::node* singly_linked_list::get_node(const size_t index) const {
   singly_linked_list::node * current_node = _head;
   for (size_t current_index = 0; current_index < index; current_index++) {
      current_node = current_node -> next;
   }
   return current_node;
}

/**
 * Returns the data stored at the given index
 * @param index the index of the data element
 * @return int* -- data stored at the index
 */
int* singly_linked_list::get(const size_t index) const {
   return get_node(index) -> data;
}

/**
 * Adds the given Node to the end of the linked list
 * @param baby The Node to add to the list.
 * @return none
 */
void singly_linked_list::add_last(singly_linked_list::node * baby) {
    if (_tail == nullptr) {
        _tail = baby;
        _head = baby;
    } else {
        _tail -> next = baby;
        _tail = baby;
    }
    _size++;
}

/**
 * Appends the given data to end of the linked list.
 * @param data The data to place at the index.
 * @return none
 */
void singly_linked_list::add(int* data) {
    singly_linked_list::node * baby = new singly_linked_list::node;
    baby -> next = nullptr;
    baby -> data = data;
    add_last(baby);
}

/**
 * Removes the first Node from the linked list (a helper function)
 * @param none
 * @return none
 */
void singly_linked_list::remove_first() {
   singly_linked_list::node * old = _head;
   _head = _head -> next;

   if (_head == nullptr)
   {
      _tail = nullptr;
   }
   _size--;
   delete [] old -> data;
   delete old;
}

/**
 * Deletes all of the Nodes in the linked list
 * @param none
 * @return none
 */
void singly_linked_list::clear()
{
   while (_head != nullptr) {
      remove_first();
   }
}

/**
 * Reads the data into the linked list from the given input stream
 * @param input_stream the input stream to read from
 * @param size the size of the input line
 * @return none
 */
void singly_linked_list::read(std::istream& input_stream, size_t size) {
   int i = 0;
   int* data = new int [size];
   while (i < size) {
      int read_int = 0;
      input_stream >> read_int;
      data[i] = read_int;
      i++;
   }
   add(data);
}

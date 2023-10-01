/**
 * Header file of class singly_linked_list
 * Slightly-modified version of singly_linked_list class from lab 11:
 * The data in the node contains a dynamic array of integers, and the unused methods were removed.
 * @file singly_linked_list.h
 * @author Grisha Hatavets
 * @date December 5, 2022
 */

// CITE: Lab 11 singly_linked_list.h
// DESC: Template for singly_linked_list class header.

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <iostream>

class singly_linked_list {
private:
   struct node {
      int* data; // dynamic array of int
      node* next;
   };
    node * _head;
    node * _tail;
    size_t _size;

public:
    // lifecycle methods
    singly_linked_list();
    ~singly_linked_list();
    // methods from the List interface
    int* get(const size_t index) const;
    void add(int* data);
    void read(std::istream& input_stream, size_t size);
private:
    // helper methods
    node* get_node(const size_t index) const;
    void add_last(node* baby);
    void remove_first();
    void clear();
};

#endif // SINGLYLINKEDLIST_H

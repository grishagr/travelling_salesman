/**
 * Solution to Travelling Salesman Problem via Nearest Neighbor Heuristic Algorithm
 * @file travel.cpp
 * @author Grisha Hatavets
 * @date December 5, 2022
 */
#include <iostream>
#include "singly_linked_list.h"
using namespace std;

// Global Variables
size_t NUM_OF_VERTICES; // number of vertices in the graph
singly_linked_list GRAPH; // linked list for graph
int STARTING_VERTEX = 0; // starting vertex (0 by default)
int* DISCOVERED; // dynamic array of discovered vertices (0 - undiscovered, 1 - discovered)
int* SEQUENCE; // dynamic array of the sequence in which vertices are discovered
int TOTAL_COST = 0; // total cost of the trip around all vertices

//helper functions
int find_nearest_neighbor(int* costs);
void handle_input();
void calculate_cost();

// Controls the operation of the program
int main() {
    handle_input();
    calculate_cost();
    // prints sequence of vertices
    for (size_t v = 0; v <  NUM_OF_VERTICES; v++) {
        cout << SEQUENCE[v] << " -> ";
    }
    cout << SEQUENCE[NUM_OF_VERTICES] << endl;
    // prints total cost
    cout << "total cost: " << TOTAL_COST << endl;
    delete[] SEQUENCE;
    delete [] DISCOVERED;
    return 0;
}

/**
 * Updates SEQUENCE and TOTAL_COST variables
 * @param none
 * @return none
 */
void calculate_cost() {
    SEQUENCE = new int[NUM_OF_VERTICES + 1];
    SEQUENCE[0] = STARTING_VERTEX;
    SEQUENCE[NUM_OF_VERTICES] = STARTING_VERTEX;
    int current_vertex = STARTING_VERTEX;
    int* costs;
    for (size_t vertex = 1; vertex <  NUM_OF_VERTICES; vertex++) {
        costs = GRAPH.get(current_vertex); // costs to other vertices from current vertex
        current_vertex = find_nearest_neighbor(costs); // finds nearest neighbor of the current vertex
        TOTAL_COST += costs[current_vertex];
        SEQUENCE[vertex] = current_vertex;
        DISCOVERED[current_vertex] = 1; // discover new vertex
    }
    costs = GRAPH.get(current_vertex);
    TOTAL_COST += costs[STARTING_VERTEX];
}

/**
 * Returns the vertex label of the nearest undiscovered neighbor of the specified vertex in the graph
 * @param costs dynamic array of costs to get to other vertices
 * @return int
 */
int find_nearest_neighbor(int* costs) {
    int nearest_neighbor = -1;
    int min_cost = -1;
    for (size_t vertex = 0; vertex <  NUM_OF_VERTICES; vertex++) {
        if (DISCOVERED[vertex] == 0) {
            if (min_cost == -1 || min_cost > costs[vertex]) {
                nearest_neighbor = vertex;
                min_cost = costs[vertex];
            }
        } 
    }
    return nearest_neighbor;
}

/**
 * Stores the information from the input in the global variables
 * @param none
 * @return none
 */
void handle_input() {
    string word;
    cin >> word;
    cin >> NUM_OF_VERTICES;
    DISCOVERED = new int[NUM_OF_VERTICES];
    for (size_t vertex = 0; vertex < NUM_OF_VERTICES; vertex++) {
        cin >> word;
        GRAPH.read(cin, NUM_OF_VERTICES);
        DISCOVERED[vertex] = 0;
    }
    if (cin.peek() != EOF || cin.peek() != '\n' ) {
        cin >> word;
        cin >> STARTING_VERTEX;
    }
    DISCOVERED[STARTING_VERTEX] = 1;
}
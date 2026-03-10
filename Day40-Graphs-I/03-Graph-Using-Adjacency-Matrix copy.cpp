#include <iostream>
#include <list> // List is a double linked list in C++. We can use it to store the adjacent nodes of each node in the graph.
using namespace std;

int main(void)
{

    return 0;
}

/*
    Graph using Adjacency Matrix:
    - An adjacency matrix is a way to represent a graph using a 2D array. Each cell (i, j) in the matrix represents whether there is an edge from node i to node j.
    - For example, consider the following graph:
        A --- B
        |     |
        C --- D
    - The adjacency matrix representation of this graph would be:
        A: 0, 1, 1, 0
        B: 1, 0, 0, 1
        C: 1, 0, 0, 1
        D: 0, 1, 1, 0
    - In this representation, the value 1 indicates that there is an edge between the nodes, while the value 0 indicates that there is no edge. For example, there is an edge from node A to node B (A-B), so the cell (A, B) has a value of 1. There is no edge from node A to node D (A-D), so the cell (A, D) has a value of 0.
*/
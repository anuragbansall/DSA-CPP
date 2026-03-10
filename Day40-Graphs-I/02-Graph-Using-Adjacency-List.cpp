#include <iostream>
#include <list> // List is a double linked list in C++. We can use it to store the adjacent nodes of each node in the graph.
using namespace std;

int main(void)
{

    return 0;
}

/*
    Graph using Adjacency List:
    - An adjacency list is a way to represent a graph using a list of lists. Each node has a list of its adjacent nodes. This is an efficient way to represent sparse graphs, where the number of edges is much less than the square of the number of nodes.
    - For example, consider the following graph:
        A --- B
        |     |
        C --- D
    - The adjacency list representation of this graph would be:
        A: B, C
        B: A, D
        C: A, D
        D: B, C
    - In this representation, each node has a list of its adjacent nodes. For example, node A has two adjacent nodes, B and C. Node B has two adjacent nodes, A and D, and so on.
*/
#include <iostream>
#include <list> // List is a double linked list in C++. We can use it to store the adjacent nodes of each node in the graph.
using namespace std;

int main(void)
{

    return 0;
}

/*
    Graph using Edge List:
    - An edge list is a way to represent a graph using a list of edges. Each edge is represented as a pair of nodes (u, v) that are connected by the edge. This is a simple way to represent a graph, but it can be inefficient for large graphs with many edges.
    - For example, consider the following graph:
        A --- B
        |     |
        C --- D
    - The edge list representation of this graph would be:
        (A, B)
        (A, C)
        (B, D)
        (C, D)
    - In this representation, each edge is represented as a pair of nodes. For example, the edge between node A and node B is represented as (A, B). The edge between node A and node C is represented as (A, C), and so on.
*/
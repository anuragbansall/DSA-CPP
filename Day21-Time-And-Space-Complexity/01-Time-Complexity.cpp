#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    // Linear Time Complexity
    vector<int> v = {1, 2, 3, 4, 5};
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    } // Time Complexity: O(n) - Linear Time Complexity
    cout << endl;

    // Constant Time Complexity
    cout << v[0] << endl; // Time Complexity: O(1) - Constant Time Complexity

    return 0;
}

/*
    Time Complexity:
        -  Time complexity is a way of representing the amount of time taken by a program to run as a function of the length of the input.
        -  It is not the actual time taken by the program to run, but the number of operations it takes to run.
        -  It is generally expressed in Big O notation. But there are other notations as well.
        -  It is used to compare the efficiency of different approaches to a problem.
        -  It is used to determine the worst-case scenario, average-case scenario, and best-case scenario of a program.
        -  It is used to determine the scalability of a program.
        -  It is used to determine the performance of a program.

    Constant Time Complexity:
        -  O(1) - Constant Time Complexity
        -  The time taken by the program to run is constant, irrespective of the size of the input.
        -  The time taken by the program to run is always the same.
        -  It is the most efficient time complexity.
        -  Example: Accessing an element in an array using its index.

    Notations:
        - Big O Notation: O(n) // worst-case scenario
        - Big Omega Notation: Ω(n) // best-case scenario
        - Big Theta Notation: Θ(n) // average-case scenario

        - Small O Notation: o(n) // upper bound
        - Small Omega Notation: ω(n) // lower bound
        - Small Theta Notation: θ(n) // tight bound

    Big O Notation:
        - It is used to represent the time complexity of a program in terms of the length of the input.
        - It is used to represent the upper bound of the time taken by a program to run.
        - It is used to represent the worst-case scenario of a program.
        - It always tries to find the worst-case scenario of a program.

        Calculating Big O Notation:
            - Using graph
            - Using function
            - Using math formula

        Calculating Big O Notation using Graph:
            - Draw a graph with the length of the input on the x-axis and the time taken by the program to run on the y-axis.
            - Plot the graph of the time taken by the program to run as a function of the length of the input.
            - Find the upper bound of the graph.
            - The upper bound of the graph is the Big O notation of the program.

        Calculating Big O Notation using Function:
            - Write a function that represents the time taken by the program to run as a function of the length of the input.
            - Find the highest power of the input in the function.
            - The highest power of the input in the function is the Big O notation of the program.

        Calculating Big O Notation using Math Formula:
            - Write a math formula that represents the time taken by the program to run as a function of the length of the input.
            - Find the highest power of the input in the math formula.
            - The highest power of the input in the math formula is the Big O notation of the program.
            - Cormen's Rule: If the function has multiple terms, the one with the highest power of the input is the Big O notation of the program.

    Common Time Complexities:
        - O(1) - Constant Time Complexity
        - O(log n) - Logarithmic Time Complexity
        - O(n) - Linear Time Complexity
        - O(n log n) - Linearithmic Time Complexity
        - O(n^2) - Quadratic Time Complexity
        - O(2^n) - Exponential Time Complexity
*/
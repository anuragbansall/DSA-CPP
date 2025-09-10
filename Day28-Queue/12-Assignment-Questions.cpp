#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

int timeToBuyTickets(vector<int> &tickets, int k);
int gasStation(vector<int> &gas, vector<int> &cost);
void reverseKElements(queue<int> &q, int k);

int main(void)
{

    /*
        Question 1: There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n-1)th person is at the back of the line. You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i]. Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line. Return the time taken for the person at position k (0-indexed) to finish buying tickets.

        Example:
        Input: tickets = [2, 3, 2], k = 2
        Output: 6
        Explanation:
        - In 1st pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
        - In 2nd pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
        The person at position 2 has successfully bought 2 tickets and it took 6 seconds.
    */

    vector<int> tickets = {2, 3, 2};
    int k = 2;

    cout << timeToBuyTickets(tickets, k) << endl;

    /*
        Question 2: There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i+1)th station. You begin the journey with an empty tank at one of the gas stations.

        Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

        Example:
        Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        Output: 3
        Explanation:
        Start at station 3 (index 3) and fill up with 4 units of gas. Your tank = 0 + 4 = 4
        Travel to station 4. Your tank = 4 - 1 + 5 = 8
        Travel to station 0. Your tank = 8 - 2 + 1 = 7
        Travel to station 1. Your tank = 7 - 3 + 2 = 6
        Travel to station 2. Your tank = 6 - 4 + 3 = 5
        Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
        Therefore, return 3 as the starting index.

        Note: Use Deque to solve the question.
    */
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << gasStation(gas, cost) << endl;

    /*
        Question 3: Given an integer K and a queue of integers, reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

        Only the following standard operations are allowed on queue:
        - push(x): Add an item x to rear of queue
        - pop(): Remove an item from front of queue
        - size(): Returns the number of elements in the queue
        - front(): Finds front item

        Example:
        Input: Queue is [1, 2, 3, 4, 5], K = 3
        Output: [3, 2, 1, 4, 5]
        Explanation: After reversing the first 3 elements, the output will be [3, 2, 1, 4, 5].
    */

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseKElements(q, 3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

int timeToBuyTickets(vector<int> &tickets, int k)
{
    int time = 0;
    queue<int> q;

    for (int i = 0; i < tickets.size(); i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        tickets[idx]--;
        time++;

        if (idx == k && tickets[idx] == 0)
        {
            return time;
        }

        if (tickets[idx] > 0)
        {
            q.push(idx);
        }
    }

    return time;
}

int gasStation(vector<int> &gas, vector<int> &cost)
{
    int currentGas = 0;
    int totalGas = 0;
    int startingIdx = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        int netGas = gas[i] - cost[i];
        currentGas += netGas;
        totalGas += netGas;

        if (currentGas < 0)
        {
            startingIdx = i + 1;
            currentGas = 0;
        }
    }

    return (totalGas >= 0) ? startingIdx : -1;
}

void reverseKElements(queue<int> &q, int k)
{
    if (q.empty() || k > q.size() || k <= 0)
    {
        return;
    }

    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    int t = q.size() - k;
    while (t--)
    {
        q.push(q.front());
        q.pop();
    }
}
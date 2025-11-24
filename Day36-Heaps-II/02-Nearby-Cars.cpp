#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int calculateDistance(int cx, int cy)
{
    return cx * cx + cy * cy; // Return squared distance to avoid floating point operations
}

vector<pair<int, int>> findNearestCars(const vector<pair<int, int>> &carLocations, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;

    for (const auto &location : carLocations)
    {
        int cx = location.first;
        int cy = location.second;
        int distance = calculateDistance(cx, cy);

        if (maxHeap.size() < k)
        {
            maxHeap.push({distance, {cx, cy}});
        }
        else if (distance < maxHeap.top().first)
        {
            maxHeap.pop();
            maxHeap.push({distance, {cx, cy}});
        }
    }

    vector<pair<int, int>> nearestCars;
    while (!maxHeap.empty())
    {
        nearestCars.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return nearestCars;
}

int main(void)
{
    // Based on Car location (cx, cy) find nearest k cars from a list of car locations
    vector<pair<int, int>> carLocations = {{1, 2}, {3, 4}, {1, -1}, {5, 6}, {2, 2}};
    int k = 3; // Number of nearest cars to find

    vector<pair<int, int>> nearestCars = findNearestCars(carLocations, k);

    cout << "The nearest " << k << " cars are located at:\n";
    for (const auto &car : nearestCars)
    {
        cout << "(" << car.first << ", " << car.second << ")\n";
    }

    return 0;
}

/*
    Nearest Cars Algorithm:
    1. Create a max-heap (priority queue) to store the nearest k cars
    2. For each car location (cx, cy):
        a. Calculate the Euclidean distance from the origin (0, 0): distance = sqrt(cx*cx + cy*cy)
        b. If the heap size is less than k, push the car into the heap
        c. Else if the current car's distance is less than the max distance in the heap:
            i. Pop the max element from the heap
            ii. Push the current car into the heap
*/
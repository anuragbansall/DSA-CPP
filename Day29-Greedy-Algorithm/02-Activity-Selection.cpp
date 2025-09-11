#include <iostream>
using namespace std;

/*
    Select the max no. of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

    start[] = {10, 12, 20}
    end[]   = {20, 25, 30}

    Approach:
    1. Sort the activities based on their finish time.
    2. Select the first activity from the sorted list and add it to the result.
    3. For the remaining activities, if the start time of the activity is greater than or equal to the finish time of the previously selected activity, select that activity. Otherwise, discard it.
    4. Repeat step 3 until all activities have been considered.
*/

int activitySelection(int start[], int end[], int n);

int main(void)
{
    int start[] = {10, 12, 20};
    int end[] = {20, 25, 30};
    int n = sizeof(start) / sizeof(start[0]);

    int maxActivities = activitySelection(start, end, n);
    cout << "Maximum number of activities: " << maxActivities << endl;

    return 0;
}

int activitySelection(int start[], int end[], int n)
{

    // Sort activities based on finish time
    // Using Bubble Sort for simplicity
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (end[j] > end[j + 1])
            {
                // Swap end times
                swap(end[j], end[j + 1]);
                // Swap corresponding start times
                swap(start[j], start[j + 1]);
            }
        }
    }

    int count = 1; // First activity is always selected
    int lastEndTime = end[0];

    for (int i = 1; i < n; i++)
    {
        if (start[i] >= lastEndTime)
        {
            count++;
            lastEndTime = end[i];
        }
    }

    return count;
}
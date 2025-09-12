#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Job
{
public:
    int id;       // Job ID or index
    int deadline; // Deadline
    int profit;   // Profit

    Job(int i, int d, int p)
    {
        id = i;
        deadline = d;
        profit = p;
    }
};

// Sort jobs by descending profit
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int jobScheduling(vector<pair<int, int>> &pairs)
{
    int n = pairs.size();

    vector<Job> jobs;
    int maxDeadline = 0;

    // Create job list and find max deadline
    for (int i = 0; i < n; i++)
    {
        jobs.emplace_back(i + 1, pairs[i].first, pairs[i].second);
        maxDeadline = max(maxDeadline, pairs[i].first);
    }

    // Sort by profit descending
    sort(jobs.begin(), jobs.end(), compare);

    // Track used time slots
    vector<bool> slot(maxDeadline + 1, false); // Index 1 to maxDeadline

    int totalProfit = 0;
    vector<int> selectedJobs;

    for (auto &job : jobs)
    {
        // Find a free time slot from job.deadline to 1
        for (int t = job.deadline; t >= 1; t--)
        {
            if (!slot[t])
            {
                slot[t] = true;
                totalProfit += job.profit;
                selectedJobs.push_back(job.id);
                break;
            }
        }
    }

    // Output selected job IDs
    cout << "Selected Jobs: ";
    for (int id : selectedJobs)
    {
        cout << id << " ";
    }
    cout << endl;

    return totalProfit;
}

int main()
{
    vector<pair<int, int>> jobs = {{2, 100}, {1, 50}, {2, 10}, {1, 20}};

    int maxProfit = jobScheduling(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}

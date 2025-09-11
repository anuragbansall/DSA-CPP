#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;
    return r1 > r2;
}

double getMaxValue(const vector<int> &val, const vector<int> &wt, int W)
{
    vector<pair<int, int>> items;

    for (int i = 0; i < val.size(); i++)
    {
        items.push_back(make_pair(val[i], wt[i]));
    }

    sort(items.begin(), items.end(), compare);

    int currWeight = 0;
    double finalValue = 0.0;

    for (const auto &item : items)
    {
        int value = item.first;
        int weight = item.second;

        if (currWeight + weight <= W)
        {
            currWeight += weight;
            finalValue += value;
        }
        else
        {
            int remain = W - currWeight;
            finalValue += value * ((double)remain / weight); // fractional part
            break;
        }
    }

    return finalValue;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50;

    double maxValue = getMaxValue(val, wt, W);
    cout << fixed << setprecision(2);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

void dfs(const string &airport, unordered_map<string, vector<string>> &map, vector<string> &result)
{
    vector<string> &destinations = map[airport];

    while (!destinations.empty())
    {
        string nextAirport = destinations.front();
        destinations.erase(destinations.begin());
        dfs(nextAirport, map, result);
    }

    result.push_back(airport);
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    unordered_map<string, vector<string>> map;

    // Build the graph
    for (const auto &ticket : tickets)
    {
        map[ticket[0]].push_back(ticket[1]);
    }

    // Sort the destinations to ensure lexical order
    for (auto &entry : map)
    {
        sort(entry.second.begin(), entry.second.end());
    }

    vector<string> result;

    dfs("JFK", map, result);
    reverse(result.begin(), result.end());

    return result;
}

int main(void)
{
    /*
        Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from "JFK". Thus, the itinerary must begin with "JFK".
        Note:
        If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
        You may assume all tickets form at least one valid itinerary.

        Example 1:
        Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
        Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
        Explanation: The itinerary begins with "JFK".

        Example 2:
        Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
        Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
        Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
    */

    vector<vector<string>> tickets1 = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets2 = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};

    vector<string> itinerary1 = findItinerary(tickets1);
    vector<string> itinerary2 = findItinerary(tickets2);

    cout << "Itinerary 1: ";
    for (const string &airport : itinerary1)
    {
        cout << airport << " ";
    }

    cout << "\nItinerary 2: ";
    for (const string &airport : itinerary2)
    {
        cout << airport << " ";
    }

    return 0;
}
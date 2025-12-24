#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{

    /*
        For an M x N matrix, a row i is weaker than row j if:
        1. The number of soldiers in row i is less than the number of soldiers in row j.
        2. Both rows have the same number of soldiers but i < j.
        Soldiers are represented by 1's and civilians by 0's.

        Find K weakest rows in the matrix.

        For example:
        Input:
        mat = [[1, 0, 0, 0],
               [1, 1, 1, 1],
               [1, 0, 0, 0],
               [1, 0, 0, 0]],
        k = 2
        Output: [0, 2]
        Explanation:
        The number of soldiers in each row is:
        Row 0 -> 1
        Row 1 -> 4
        Row 2 -> 1
        Row 3 -> 1
        The weakest rows are 0, 2, and 3. Since k = 2, we return [0, 2].

        Approach:
        1. Use a min-heap to store pairs of (number of soldiers, row index).
        2. For each row in the matrix, count the number of soldiers (1's) and push the pair into the min-heap.
        3. Extract the top k elements from the min-heap to get the indices of the weakest rows.
    */

    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}};
    int k = 2;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // (number of soldiers, row index)

    // Step 2: Count soldiers in each row and push to min-heap
    for (int i = 0; i < mat.size(); i++)
    {
        int soldierCount = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] == 0)
            {
                break; // Since soldiers are always before civilians
            }

            soldierCount += mat[i][j];
        }

        minHeap.push({soldierCount, i});
    }

    vector<int> weakestRows;
    // Step 3: Extract the top k weakest rows
    for (int i = 0; i < k; i++)
    {
        weakestRows.push_back(minHeap.top().second);
        minHeap.pop();
    }

    cout << "The indices of the weakest rows are: ";
    for (int index : weakestRows)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
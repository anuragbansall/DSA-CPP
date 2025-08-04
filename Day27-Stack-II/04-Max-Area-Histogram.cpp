#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int n = heights.size();

    stack<int> st;

    vector<int> left(n), right(n);

    // Finding the next smaller element on the left
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    // Clear the stack for the next operation
    while (!st.empty())
    {
        st.pop();
    }

    // Finding the next smaller element on the right
    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Calculating the maximum area
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }

    cout << "Maximum area: " << maxArea << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpan(vector<int> &prices, vector<int> &span)
{
    stack<int> st;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!st.empty() && prices[st.top()] <= prices[i])
        {
            st.pop();
        }

        // Pop the stack to find the previous higher price
        if (st.empty())
        {
            span[i] = i + 1; // If stack is empty, it means no higher price found, so span is i + 1
        }
        else
        {
            span[i] = i - st.top(); // i - previous higher price index
        }

        // Push the current index onto the stack
        st.push(i);
    }
}

int main(void)
{
    vector<int> prices = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(prices.size(), 0);

    // Calculate the stock span
    stockSpan(prices, span);

    // Output the span values
    for (int i = 0; i < span.size(); i++)
    {
        cout << "Span for price " << prices[i] << " is: " << span[i] << endl;
    }

    return 0;
}
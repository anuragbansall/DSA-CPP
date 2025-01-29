#include <iostream>
#include <vector>
using namespace std;

int lastOccurrence(vector<int> arr, int key);

int main(void)
{
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    int key = 2;

    int index = lastOccurrence(arr, key);
    cout << "Last occurrence of " << key << " is at index: " << index << endl;

    return 0;
}

int lastOccurrence(vector<int> arr, int key)
{
    int n = arr.size();

    if (n == 0)
    {
        return -1;
    }

    int index = lastOccurrence(vector<int>(arr.begin() + 1, arr.end()), key);

    if (index == -1)
    {
        return arr[0] == key ? 0 : -1;
    }

    return index + 1;
}
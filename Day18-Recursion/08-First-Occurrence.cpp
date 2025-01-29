#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> arr, int key);

int main(void)
{
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    int key = 2;

    int index = firstOccurrence(arr, key);
    cout << "First occurrence of " << key << " is at index: " << index << endl;

    return 0;
}

int firstOccurrence(vector<int> arr, int key)
{
    int n = arr.size();

    if (n == 0)
    {
        return -1;
    }

    if (arr[0] == key)
    {
        return 0;
    }

    int index = firstOccurrence(vector<int>(arr.begin() + 1, arr.end()), key);

    return index == -1 ? -1 : index + 1;
}
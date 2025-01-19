#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Predict the output
    vector<int> vec;

    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }

    cout << vec.size() << endl;     // 5
    cout << vec.capacity() << endl; // 8

    return 0;
}
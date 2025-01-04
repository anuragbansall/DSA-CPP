#include <iostream>
using namespace std;

int main()
{
    float science, maths, english, total;
    cout << "Enter marks in Science: ";
    cin >> science;
    cout << "Enter marks in Maths: ";
    cin >> maths;
    cout << "Enter marks in English: ";
    cin >> english;

    total = science + maths + english;

    cout << "Total marks: " << total << endl;
    cout << "Average marks: " << total / 3 << endl;

    return 0;
}
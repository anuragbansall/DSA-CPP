#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// Define a Student class with name and marks
class Student
{
public:
    string name;
    int marks;

    Student(string n, int m)
    {
        name = n;
        marks = m;
    }

    // Overload the < operator to compare Students based on marks
    bool operator<(const Student &other) const
    {
        return marks < other.marks; // For Max-Heap based on marks
    }
};

int main(void)
{
    // Create a priority queue to store Student objects
    priority_queue<Student> pq; // Max-Heap based on marks

    // Insert Student objects into the priority queue
    pq.push(Student("Alice", 85));
    pq.push(Student("Bob", 90));
    pq.push(Student("Charlie", 78));

    // Pop and display students in order of their marks
    while (!pq.empty())
    {
        Student s = pq.top();
        cout << "Name: " << s.name << ", Marks: " << s.marks << endl;
        pq.pop();
    }

    return 0;
}
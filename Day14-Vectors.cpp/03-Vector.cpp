#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);
    cout << "The size of the vector is: " << vec.size() << endl;
    
    cout << "The elements of the vector are: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
    Vector:
    - Vector is a sequence container that encapsulates dynamic size arrays.
    - It is a part of the Standard Template Library (STL).
    - It is similar to a dynamic array, but it provides more functionality and flexibility.
    - The size of the vector can be changed dynamically.
    - The elements of the vector are stored in contiguous memory locations.
    - The vector provides various member functions to perform different operations on the elements.
    - Include the <vector> header file to use the vector class.
    - Syntax:
        vector<data_type> vector_name;
    - Example:
        vector<int> vec = {1, 2, 3, 4, 5};

        // Accessing elements
        cout << vec[0] << endl; // Output: 1
        cout << vec[4] << endl; // Output: 5

        // Modifying elements
        vec[2] = 10;

        // Adding elements
        vec.push_back(6);

        // Removing elements
        vec.pop_back();

        // Sorting elements
        sort(vec.begin(), vec.end());

    - Vector with fill constructor:
        vector<data_type> vector_name(size, value);
    - Example:
        vector<int> vec(5, 10);
        // Output: 10 10 10 10 10

    Vector size and capacity:
    - The size of the vector is the number of elements present in the vector.
    - The capacity of the vector is the number of elements that can be stored in the vector without resizing.
    - The size of the vector can be obtained using the size() member function.
    - The capacity of the vector can be obtained using the capacity() member function.
    - The size of the vector increases when elements are added to the vector.
    - The capacity of the vector increases when the size of the vector exceeds the current capacity.
    - The capacity of the vector is doubled when the size of the vector exceeds the current capacity.
*/
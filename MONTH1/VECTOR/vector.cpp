#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // dynamic resize array

    // Declare a vector
    vector<int> vec;              // vector of size 0
    vector<int> vec1 = {1, 2, 3}; // vector of size 3
    vector<int> vec2(3, 0);       // vector of size 3 and initial value 0

    // Accessing is same as array 0 based indexing

    // For each loop in vector
    vector<char> vec3 = {'a', 'b', 'k'};
    for (char ele : vec3)
    {
        cout << ele << " ";
    }

    // Function of vector

    // size of vector
    cout << "size " << vec3.size() << endl;

    // push element in vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    cout << "After push back size = " << vec.size() << endl;

    // Pop back in vector
    vec.pop_back();
    cout << "after popback size = " << vec.size() << endl;

    // Front and last value of vector
    cout << vec.front() << endl;
    cout << vec.back() << endl;

    // At function in vector
    cout << vec.at(1); // value at 1st index

    /*static and dynmaic memory allocation

    1.static memoery
    a.stack
    b.compile time allocate
    c.array

    2.dynamic memory allocarion
    a.heap
    b.run time allocate
    c.vector
    */

    // capactiy and size of vector

    // size give number of element in vector
    // capacity id total space without  double always in multiple of 2

    cout << "Size " << vec.size();
    cout << "capacity " << vec.capacity();

    return 0;
}
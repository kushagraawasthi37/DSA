#include <iostream>
using namespace std;

void change(int &a)
{
    a = 100;
}

int main()
{
    // Pointer is special variable that stores the address of variable- address of ->&
    // Pointer and variable are of same dataType
    int a = 10;
    int *b = &a;
    // Value of b
    // cout << "Value of pointer" << b << endl;

    // Address of pointer
    // cout << "Address of Pointer " << &b << endl;

    // Pointer to Pointer
    // int **c = &b;
    // cout << "pointer to Pointer " << c << endl;

    // Dereference operator-> value at address
    // cout << *(&a) << endl;
    cout << *b << endl;
    // cout << *c << endl;
    // cout << **c << endl;

    // Null pointer-> pointer that doesnot store any proper address;
    // /Derefernce of null Pointer give you the segmentation error
    int *ptr = NULL;

    // Pass by reference-> pointer or address pass kar do
    // change(a);
    // cout << a << endl;

    // Array Pointer
    int arr[] = {1, 2, 3, 4, 5};
    // Name of array is  a pointer addressing the index 0;
    // Array pointer is a constant pointer and its value can not be changed

    // Pointer Arithmatic
    // .Increment and decrement pointer  increment/decrement == size of pointer

    // Addition and substraction =size of dataType*add/subs
    // cout << *arr << endl;
    // cout << *(arr + 1) << endl;
    // cout << *(arr + 2) << endl;
    // cout << *(arr + 3) << endl;

    // Substract of 2 pointer

    int *ptr1;
    int *ptr2 = ptr1 + 3;

    cout << ptr2 - ptr1 << endl;

    // Compare two pointer
    cout << (ptr1 == ptr2) << endl;
    cout << (ptr1 != ptr2) << endl;
    cout << (ptr1 < ptr2) << endl;
    cout << (ptr1 > ptr2) << endl;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char arr[] = {'a', 'b', 'c', '\0'}; // agar '\0' nahi hoga to ek extra charater ayega aur ye valid string nahi banegi
    cout << arr << endl;

    char arr1[10];
    char arr2[100];

    // Input in character array
    // One word input without space
    // cin >> arr1;

    // multiple word with space
    // cin.getline(arr2, 100, '@'); // jab bhi @ input hoga turant input lena band ho ajyega

    // cout << "Output string 1" << arr1 << endl;
    // cout << "Output string 2 " << arr2 << endl;

    // calculate the length of string
    // int len = 0;
    // for (int i = 0; arr1[i] != '\0'; i++)
    // {
    //     len++;
    // }

    // cout << "Length of char array"<<len << endl;

    // string in C++

    string str1 = "hello";

    
    // string str2 = "World";
    // string str4;
    // string str5;

    // // concatination in string
    // string str3 = str1 + str2;
    // cout << str3 << endl;

    // // Comparision in string
    // cout << (str1 == str2) << endl;
    // cout << (str1 > str2) << endl;
    // cout << (str1 < str2) << endl;
    // cout << (str1 != str2) << endl;

    // // length of string
    // cout << "Length of string" << str1.length() << endl;

    // /// Input in string
    // cin >> str4;
    // cout << "Output " << str4 << endl;
    // // Multiword string
    // getline(cin, str5, '.');
    // cout << "Output " << str5 << endl;

    // // Loops in string
    // for (char ele : str3)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;
    // // for (int i = 0; str3[i] != '\0'; i++)
    // // {
    // //     cout << str3[i] << " ";
    // // }

    //reverse a string
    
    return 0;
}
#include <iostream>
using namespace std;

string removeOcc(string s, string str)
{
    while (s.find(str) < s.length() && s.length() > 0)
    {
        //Erase (Remove)in String 
        s.erase(s.find(str), str.length());
    }
    return s;
}
int main()
{
    string s = "daabcbaabcbc";
    cout << removeOcc(s, "abc");
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &vec)
{
    // In Linear time and constant space
    int n = vec.size();
    int ans = 0;
    for (int ele : vec)
    {
        ans = ans ^ ele; // Bitwise operator 1^1 &&  0^0=0 1^0=1
    }

    return ans;
}
int main()
{
    vector<int> vec = {4, 1, 2, 1, 2};
    cout << "Unique Number " << singleNumber(vec);
    return 0;
}
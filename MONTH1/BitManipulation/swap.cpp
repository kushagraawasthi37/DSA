#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    a=a^b;
    cout<<a<<endl;
    b=b^a;
    cout<<b<<endl;
    a=a^b;
    cout<<a<<endl;
}

int main() {
    int a=2;
    int b=3;

    swap(a,b);
    cout<<"a "<<a<<" b "<<b<<endl;

    return 0;
}
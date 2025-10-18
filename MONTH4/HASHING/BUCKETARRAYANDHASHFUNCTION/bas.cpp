#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    Hash function-> hashcode(conversion to int)+ compression function(hashcode int ko range mai lana hai)

    Hash code ->conversion to int and uniform distribution

    collision suppose hashcode=sum of ASCII value then guru and gruu have same value it

    collision handeling :
    1.Open hashing same place par hi jao
    a.seperate chaining->linked list ka head store hota hai


    b.Closed addressing->agar space khali hai to daal do bara agla space dhundo  H(a)=h(a)+f(a);
    i.linear probing f(i)=i
    ii.Quadratic Probing f(i)=i*i






    load factor= n/b
    n= no of entries and b = no of box availble in Bucket array
    load factor(n/b)<0.7 for unifrom distribution and good hashing

    It is very safe to assume the insertion complexity O(1)

    if increasing then b also increasing -> rehashing mean increase bucket size And sabko phir se hasing kardo
    //Same stuff for deletion and searching

*/

    return 0;
}
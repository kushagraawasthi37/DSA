#include <bits/stdc++.h>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{

    // UnOrdered map->Insertion deletion aur search constant time lekin agar simple map hai to logn time
    // Isme insertion aur print order same ho jarruri nhi but agar map hai to same order mai hi rahega

    // Creation
    unordered_map<string /*key*/, int /*value*/> m;

    // Insertion
    pair<string, int> p = make_pair("kushagra", 1);
    m.insert(p);

    // 2
    pair<string, int> pair2("Guru", 2);
    m.insert(pair2);

    // 3
    m["Aman"] = 3;
    // Iska kya hoga
    m["Aman"] = 5; // update ho jayega value unique entry first time

    // Search
    cout << m["Aman"] << endl;
    cout << m.at("kushagra") << endl;

    // Unknown entry map->(ek entry bna dega aur 0 return karega agar ye at se upar likhe hai to at bala 0 return karega)
    cout << m["UnknownKey"] << endl;
    // Return karega Unbound key exception
    cout << m.at("UnknownKey") << endl;

    // Size
    cout << m.size() << endl;

    // To check present or not
    cout << m.count("kushagra") << endl;    // Present return 1
    cout << m.count("Not Present") << endl; // Absetn return 0

    // Erase
    m.erase("Guru");
    cout << "New Size " << m.size() << endl;

    // Iterate the whole map
    for (auto i : m)
    {
        // Isme insertion aur print order same ho jarruri nhi but agar map hai to same order mai hi rahega
        cout << "key " << i.first << " Value " << i.second << endl;
    }

    // iterator
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        // Isme insertion aur print order same ho jarruri nhi but agar map hai to same order mai hi rahega
        cout << "Key " << it->first << " Value " << it->second << endl;
        it++;
    }

    // Second Way of finding the number
    m.find("Kushagra"); // Present then doestnot equql to m.end() else m.end()

    // Ordered map
}

// Feature             |  std::map (ordered)                                       |  std::unordered_map                                         
// --------------------+-----------------------------------------------------------+-------------------------------------------------------------
// Key Order           |  Sorted ascending by key                                  |  No guaranteed order                                        
// Implementation      |  Red-Black Tree                                           |  Hash Table                                                 
// Lookup Complexity   |  O(log⁡n)                                                  |  AverageO(1), worstOO(n)                     
// Insertion/Deletion  |  O(log⁡n)                                                  |  AverageO(1), worstO(n)                     
// Duplicate Keys      |  Not allowed                                              |  Not allowed                                                
// Use Cases           |  Need sorted traversal, range queries, lower_bound, etc.  |  Fast retrieval, key-value storage where order is irrelevant


// Feature         |  std::set (ordered)  |  std::unordered_set      
// ----------------+----------------------+--------------------------
// Element Order   |  Always ascending    |  No guaranteed order     
// Access Time     |  O(log n)            |  Average O(1), worst O(n)
// Implementation  |  Tree (Red-Black)    |  Hash Table              
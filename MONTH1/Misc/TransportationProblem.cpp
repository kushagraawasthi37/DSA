#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;  // destination block
int bestCost = INT_MAX;
vector<string> bestPath;

void backtrack(int state, vector<string> path, int cost) {
    // If reached destination
    if (state == N) {
        if (cost < bestCost) {
            bestCost = cost;
            bestPath = path;
        }
        return;
    }

    // Walk: +1 block, cost 1
    if (state + 1 <= N) {
        path.push_back("walk -> " + to_string(state + 1));
        backtrack(state + 1, path, cost + 1);
        path.pop_back();
    }

    // Tram: *2 block, cost 2
    if (state * 2 <= N) {
        path.push_back("tram -> " + to_string(state * 2));
        backtrack(state * 2, path, cost + 2);
        path.pop_back();
    }
}

int main() {
    cout << "Enter the block number you want to reach: ";
    cin >> N;

    vector<string> path;
    backtrack(1, path, 0);

    cout << "\nBest Cost: " << bestCost << "\n";
    cout << "Path taken:\n";
    for (auto &step : bestPath) {
        cout << step << "\n";
    }

    return 0;
}

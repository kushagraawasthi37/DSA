class TimeMap {
private:
    unordered_map<int, unordered_map<string, string>> m;
    unordered_map<string, vector<int>> mpp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[timestamp][key] = value;
        mpp[key].push_back(timestamp);

        // for (auto it : mpp) {
        //     cout << it.first << " ";
        //     for (auto e : it.second)
        //         cout << e << " ";
        // }

        cout << "timestamp " << timestamp << endl;

        // for (auto it : m) {
        //     cout << it.first << " [ ";
        //     for (auto i : it.second) {
        //         cout << i.first << "->" << i.second << " ";
        //     }
        //     cout << " ] " << endl;
        // }
    }

    string get(string key, int timestamp) {

        string ans = "";

        if (mpp.find(key) == mpp.end())
            return ans;

        int idx = lower_bound(mpp[key].begin(), mpp[key].end(), timestamp) -
                  mpp[key].begin();

        if (idx == mpp[key].size() || mpp[key][idx] > timestamp) {
            idx--;
        }

        if (idx < 0)
            return ans;

        return m[mpp[key][idx]][key];
    }
};
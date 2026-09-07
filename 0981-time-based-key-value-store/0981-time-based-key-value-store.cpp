class TimeMap {
private:
    unordered_map<int, unordered_map<string, string>> m;
    unordered_map<string, vector<int>> mpp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[timestamp][key] = value;
        mpp[key].push_back(timestamp);
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
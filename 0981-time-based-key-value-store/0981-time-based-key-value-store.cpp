class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (m.find(key) == m.end())
            return "";

        auto& v = m[key];

        int s = 0;
        int e = v.size() - 1;

        string ans = "";
        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (v[mid].first <= timestamp) {
                ans = v[mid].second;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return ans;
    }
};
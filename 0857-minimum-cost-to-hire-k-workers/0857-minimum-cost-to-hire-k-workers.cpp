class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int K) {
        int n = quality.size();
        double sum = 0;
        vector<pair<double, int>> arr;
        double res = 1e20;
        priority_queue<int> pq;
        
        for (int i = 0; i < n; i++) {
            arr.push_back({(1.0 * (wage[i]) / quality[i]), quality[i]});
        }

        sort(arr.begin(), arr.end());

        for (auto it : arr) {
            cout << it.first << " " << it.second;
            sum += it.second;
            pq.push(it.second);

            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            cout << " " << sum << endl;

            if (pq.size() == K) {
                res = min(res, (it.first) * sum);
            }
        }

        return res;
    }
};
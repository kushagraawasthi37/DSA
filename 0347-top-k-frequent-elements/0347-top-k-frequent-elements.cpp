class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;

        for (auto it : freq) {

            if (minHeap.size() >= k && it.second > minHeap.top().first) {
                minHeap.pop();
                minHeap.push({it.second, it.first});
            }

            else if (minHeap.size() < k)
                minHeap.push({it.second, it.first});
        }

        vector<int> result;

        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
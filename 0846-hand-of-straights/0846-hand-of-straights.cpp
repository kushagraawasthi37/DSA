class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize)
            return false;
        map<int, int> m;

        for (auto e : hand) {
            m[e]++;
        }
        int totalGroup = 0;

        for (auto it : m) {
            int ele = it.first;
            if (m.find(ele - 1) == m.end() || m[ele - 1] <= 0) {
                int freq= m[ele];

                if(freq==0) continue;

                for(int i =0;i<groupSize;i++){
                    int curr= ele+i;

                    if(m.find(curr)==m.end() || m[curr]<freq) return false;

                    m[curr]-=freq;
                }

                totalGroup+= freq;
            }
        }

        return totalGroup * groupSize == hand.size();
    }
};
class Solution {

private:
    bool isValid(vector<vector<int>>& matrix, int exp, int k) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            int smallerEle =
                upper_bound(matrix[i].begin(), matrix[i].end(), exp) -
                matrix[i].begin();
            k -= smallerEle;
        }
        return k <= 0;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) >> 1;
            if (isValid(matrix, mid, k)) {
                cout << mid << " ";
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};

/*
1  5  9
10 11 13
12 13 15
*/
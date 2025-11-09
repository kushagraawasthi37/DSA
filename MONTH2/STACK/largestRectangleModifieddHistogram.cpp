#include <bits/stdc++.h>
using namespace std;


class Solution {
   private:
    int largestRectanlgeHistogram(vector<int> arr) {
        int n = arr.size();
        vector<int> PSE(n);
        vector<int> NSE(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            PSE[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) {
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            NSE[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (arr[i] * (NSE[i] - PSE[i] - 1)));
        }

        return maxArea;
    }

   public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix) {
       int m = matrix.size();
        int n = matrix[0].size();
        

        for (int i = 0; i < m; i++) {
           
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                   continue;
                } else {
                    if (i > 0) {
                      matrix[i][j]=(matrix[i][j] + matrix[i - 1][j]);
                    }
                }
            }
        }

        int maxRec = INT_MIN;
        for (int i = 0; i < m; i++) {
            maxRec = max(maxRec, largestRectanlgeHistogram(matrix[i]));
        }

        return maxRec;
    }
};


int main() {
    Solution S;
       vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
     int ans = S.maximalAreaOfSubMatrixOfAll1(matrix);
     cout<<"Maximum rectangle answer "<<ans;
    return 0;
}
class Solution {
private:
    int manhathanDis(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adjList(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                adjList[i].push_back(
                    {j, manhathanDis(points[i][0], points[i][1], points[j][0],
                                     points[j][1])});
                adjList[j].push_back(
                    {i, manhathanDis(points[j][0], points[j][1], points[i][0],
                                     points[i][1])});
            }
        }
    
        vector<int> dis(n, 1e9);
        vector<bool> visited(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        int sum = 0;
        pq.push({0, 0});
        dis[0] = 0;

        while (!pq.empty()) {
            int node = pq.top()[1];
            int wt = pq.top()[0];

            pq.pop();
            if (visited[node])
                continue;

            visited[node] = true;

            for (auto e : adjList[node]) {
                if (visited[e.first] == false && e.second < dis[e.first]) {
                    dis[e.first] = e.second;
                    pq.push({e.second, e.first});
                }
            }

            sum += wt;
        }
        return sum;
    }
};
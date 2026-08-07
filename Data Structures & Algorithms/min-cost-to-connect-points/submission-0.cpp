class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int, int>>> adj(V);

        // Build the adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int wt = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);  // visited array
        pq.push({0, 0});        // {wt, node}
        int sum = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1) continue;

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edW = it.second;

                if (!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }

        return sum;
    }
};

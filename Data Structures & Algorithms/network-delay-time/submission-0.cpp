class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list
        vector<pair<int , int>> adj[n + 1];
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // Dijkstra using priority queue
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;

                if (d + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = d + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};

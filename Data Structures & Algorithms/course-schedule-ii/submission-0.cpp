class Solution {
public:

    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(V);

        // build graph
        for(auto it : prerequisites) {

            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
        }

        // indegree array
        vector<int> indegree(V, 0);

        // calculate indegree
        for(int i = 0; i < V; i++) {

            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // cycle exists
        if(topo.size() != V) {
            return {};
        }

        return topo;
    }
};
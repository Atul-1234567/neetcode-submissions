class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findPar(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        DisjointSet ds(n);

        int cnt = 0;

        for(auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(ds.findPar(u) != ds.findPar(v)) {
                ds.unionBySize(u, v);
                cnt++;
            }
        }

        return n - cnt;
    }
};
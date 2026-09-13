class Solution {
public:
    void dfs(int ind , vector<vector<int>>&adj,  vector<int>&vis){
        vis[ind] = 1;
        for(auto it : adj[ind]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
    
      vector<int>vis(n , 0);
      vector<vector<int>>adj(n);
      for(auto it: edges){
         int u = it[0];
         int v = it[1];
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      if(edges.size() != n - 1)return false;

      dfs(0 , adj , vis);
      
      for(int i = 0; i < n; i++){
        if(!vis[i]){
            return false;
        }
      }
      return true;
    }
};

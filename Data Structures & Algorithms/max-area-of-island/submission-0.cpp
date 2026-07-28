class Solution {
public:

    int bfs(int i, int j, vector<vector<int>>& grid, 
            vector<vector<int>>& vis, int n, int m){
        
        queue<pair<int,int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        int cnt = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                   && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){

                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }

        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(grid[i][j] == 1 && !vis[i][j]){
                    int area = bfs(i, j, grid, vis, n, m);
                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};
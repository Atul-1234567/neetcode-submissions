class Solution {
public:
int bfs(int n , int m , vector<vector<int>>&grid,  vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                q.push({i,  j});
                vis[i][j] = 1;
            }
        }
    }

     int dr[] = {-1,0,1,0};
     int dc[] = {0,1,0,-1};
     int time = -1;
     while(!q.empty()){
        int size = q.size();
        time++;
        while(size--){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4;i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                     grid[nr][nc] = 2;
                     vis[nr][nc] = 1;
                     q.push({nr , nc});
                }
            }
        }
     }
     return max(0 , time);  
};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));

        int ans = bfs(n , m , grid , vis);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

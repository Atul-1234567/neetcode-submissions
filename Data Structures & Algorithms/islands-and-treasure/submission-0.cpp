class Solution {
public:
void bfs(queue<pair<int,int>>&q , vector<vector<int>>&grid){
      int n = grid.size();
        int m = grid[0].size();
      int dr[] = {-1,0,1,0};
      int dc[] = {0 ,1,  0 , -1};
      while(!q.empty()){
        int  row= q.front().first;
        int col = q.front().second;
        q.pop();

        for(int k = 0; k < 4;  k++){
            int nr = row + dr[k];
            int nc = col + dc[k];


        if(nr >= 0 && nr <  n && nc >= 0 && nc  < m){
                 
           if (grid[nr][nc] != INT_MAX)
                    continue;
           grid[nr][nc] = grid[row][col] + 1  ;
            q.push({nr , nc});
        }
             
        }
      }
}
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)
                 q.push({i , j});
            }
        }
        return bfs(q , grid);
    }
};

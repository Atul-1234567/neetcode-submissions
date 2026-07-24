class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>&board , vector<vector<int>>&vis ){
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;

        q.push({row ,  col});
        vis[row][col] = 1;
        int dr[] = {-1 , 0 , 1 , 0};
        int dc[] = {0 , 1,  0 , -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];

       if(nrow >= 0 && nrow< n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
            vis[nrow][ncol] = 1;
            q.push({nrow , ncol});
        }
     }
  }
}
    void solve(vector<vector<char>>& board) {
        int n  = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                bfs(i , 0 , board , vis);
            }
        }   
         for(int j = 0; j < m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                bfs(0 , j , board , vis);
            }
         }
         for(int j = 0; j < m ; j++){
            if(board[n - 1][j] == 'O' && !vis[n - 1][j]){
                bfs(n - 1 , j , board , vis);
            }
         }
         for(int i = 0; i < n; i++){
            if(board[i][m - 1] == 'O' && !vis[i][m - 1]){
                bfs(i , m - 1 , board , vis);
            }
        }

        for(int i = 0;  i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

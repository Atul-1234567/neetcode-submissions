class Solution {
public:
    void bfs(vector<vector<int>>& vis,
             vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        queue<pair<int,int>> q;

        // Put all visited(border) cells into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j])
                    q.push({i, j});
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // Mark Pacific borders
        for(int i = 0; i < m; i++)
            pacific[i][0] = 1;

        for(int j = 0; j < n; j++)
            pacific[0][j] = 1;

        // Mark Atlantic borders
        for(int i = 0; i < m; i++)
            atlantic[i][n - 1] = 1;

        for(int j = 0; j < n; j++)
            atlantic[m - 1][j] = 1;

        bfs(pacific, heights);
        bfs(atlantic, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
 };

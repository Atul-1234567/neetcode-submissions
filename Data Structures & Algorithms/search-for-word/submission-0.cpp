class Solution {
public:

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis,
             string &word, int i, int j, int index) {

        if (index == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        if (vis[i][j])
            return false;


        if (board[i][j] != word[index])
            return false;

    
        vis[i][j] = true;

      
        bool found =
            dfs(board, vis, word, i + 1, j, index + 1) ||
            dfs(board, vis, word, i - 1, j, index + 1) ||
            dfs(board, vis, word, i, j + 1, index + 1) ||
            dfs(board, vis, word, i, j - 1, index + 1);


        vis[i][j] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, vis, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
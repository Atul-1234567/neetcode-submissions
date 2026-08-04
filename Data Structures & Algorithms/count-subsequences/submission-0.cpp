class Solution {
public:
    long long solve(int i, int j, string& s, string& t,
                    int n, int m, vector<vector<long long>>& dp) {

     
        if (j == m) return 1;     
        if (i == n) return 0;      

        if (dp[i][j] != -1) return dp[i][j];

        long long same = 0;
        long long notsame = 0;

        if (s[i] == t[j]) {
  
            same = solve(i + 1, j + 1, s, t, n, m, dp);
        }

        notsame = solve(i + 1, j, s, t, n, m, dp);

        return dp[i][j] = same + notsame;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0, 0, s, t, n, m, dp);
    }
};

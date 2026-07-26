class Solution {
public:
int solve(int i,  int j , int m , int n ,  vector<vector<int>>&dp){
    if(i >= n || j >= m)return 0;
    if(i == n - 1 && j == m - 1){
        return 1;
    }
    if(dp[i][j] != -1)return dp[i][j];
     
     int right = solve( i , j + 1 ,m , n ,  dp);
     int down = solve(i + 1 , j ,m , n ,  dp);

     return dp[i][j] = right + down;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n, vector<int>(m, -1));
       return solve(0 ,  0 ,m , n ,  dp);
    }
};

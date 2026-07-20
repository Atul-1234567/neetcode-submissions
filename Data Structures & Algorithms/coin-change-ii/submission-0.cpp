class Solution {
public:
int solve(int i ,  int amount , int n ,  vector<int>&coins , vector<vector<int>>&dp){
     if (amount == 0)
            return 1;

        if (i == n)
            return 0;


     if(dp[i][amount] != -1)return dp[i][amount];
     
     int take = 0;
     if(coins[i] <= amount){
     take = solve( i , amount - coins[i] , n , coins , dp);
     }
     int nottake = solve(i + 1 , amount , n , coins , dp);

     return dp[i][amount] = take + nottake;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int m = amount;
        vector<vector<int>>dp(n + 1,  vector<int>(m + 1 , -1));
        return solve(0, m ,  n , coins , dp);
    }
};

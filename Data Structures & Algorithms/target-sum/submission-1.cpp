class Solution {
    public:
    int solve(int i, int k, vector<int>&nums , int n , vector<vector<int>>&dp){
      if(i == n){
        if(k == 0)return 1;

        return 0;
      }
      if(dp[i][k] != -1)return dp[i][k];
      
        int plus = 0;
        if(nums[i] <= k){
            plus = solve(i + 1 , k - nums[i] , nums , n , dp);
        }
        int minus = solve(i + 1 , k , nums , n ,  dp);

        return dp[i][k] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i < n; i++){
            totalsum += nums[i];
        }
            if((totalsum  + target) % 2 != 0  || totalsum < abs(target)) return 0;

           int s1 = (totalsum + target) / 2;

        vector<vector<int>>dp(n , vector<int>( s1 + 1 , -1));

          return solve( 0 , s1 , nums , n ,  dp);
    }
};
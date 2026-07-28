class Solution {
 public :
      int solve(int ind , vector<int>&nums , int end, vector<int>&dp){

        if(ind > end){
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];

        int pick = nums[ind] + solve(ind + 2 , nums, end, dp);
        int notpick = solve(ind + 1 , nums , end , dp);

        return dp[ind] = max(pick , notpick);
      }
    

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         if (n == 1) return nums[0];
         
        vector<int>dp1(n , -1);
        vector<int>dp2(n , -1);
        int max1 = solve(0 , nums , n - 2 , dp1);
        int max2 = solve(1 , nums , n - 1 , dp2);

        return max(max1 , max2);

    }
};
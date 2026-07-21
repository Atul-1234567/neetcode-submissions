class Solution {
public:
bool solve(int i , vector<int>&nums , int target , int totalsum , vector<vector<int>>&dp){
    if(i == nums.size())return false;
    if(target == 0)return true;
     
     if(dp[i][target] != -1)return dp[i][target];

     bool take = false;
     if(nums[i] <= target)
     take = solve(i + 1 , nums , target - nums[i] , totalsum , dp);
     bool nottake = solve(i + 1 , nums , target , totalsum , dp);
          
     return dp[i][target] = take || nottake;
}
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int totalsum = 0;
       for(int i = 0; i < n; i++){
          totalsum += nums[i];
       } 
       if(totalsum % 2 != 0)return false;
       int target = totalsum/2;

      vector<vector<int>>dp(n , vector<int>(target + 1 , -1));

       return solve(0 , nums , target , totalsum , dp);

    }
};

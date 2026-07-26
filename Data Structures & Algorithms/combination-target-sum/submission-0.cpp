class Solution {
public:
    void solve(int ind, vector<int>& nums, int target,
               vector<int>& temp, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (ind == nums.size() || target < 0)
            return;

         if(nums[ind] <= target){
        temp.push_back(nums[ind]);
        solve(ind, nums, target - nums[ind], temp, ans);
        temp.pop_back();

         }


        solve(ind + 1, nums, target, temp, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, nums, target, temp, ans);

        return ans;
    }
};
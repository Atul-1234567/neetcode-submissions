class Solution {
public:
    void findsubsets(int ind, vector<int>& nums,
                     vector<vector<int>>& ans,
                     vector<int>& ds, int n) {

        if (ind == n) {
            ans.push_back(ds);
            return;
        }

   
        ds.push_back(nums[ind]);
        findsubsets(ind + 1, nums, ans, ds, n);
        ds.pop_back();

      
        int next = ind + 1;
        while (next < n && nums[ind] == nums[next]) {
            next++;
        }

        findsubsets(next, nums, ans, ds, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findsubsets(0, nums, ans, ds, nums.size());
        return ans;
    }
};

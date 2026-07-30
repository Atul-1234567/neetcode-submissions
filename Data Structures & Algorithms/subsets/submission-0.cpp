class Solution {
public:
   void findsubsets(int ind , vector<int>&nums , vector<int>&ds , vector<vector<int>>&ans , int n){

    if(ind == nums.size()){
         ans.push_back(ds);
         return;
    }

     if(ind <= nums.size()){
        ds.push_back(nums[ind]);
        findsubsets(ind + 1 , nums , ds , ans , n);
        ds.pop_back();
     }
     findsubsets(ind + 1 , nums ,ds  ,ans  ,n);
   }
   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>ds;

        findsubsets( 0 , nums, ds , ans , n );
        return ans;
    }
};
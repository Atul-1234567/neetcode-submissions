class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        int k = 0;
        for(auto it : st){
            nums[k] = it;
            k++;
        }
        return k;
    }
};
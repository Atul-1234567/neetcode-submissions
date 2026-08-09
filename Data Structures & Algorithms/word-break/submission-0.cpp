class Solution {
public:
   bool solve(int idx , string s , unordered_map<string,int> &mpp , vector<int>&dp){
     if(idx == s.size()){
        return true;
     }

     if(dp[idx] != -1)return dp[idx];

     string temp = "";

     for(int i = idx;  i < s.size(); i++){
        temp += s[i];

        if(mpp.find(temp) != mpp.end()){
            if(solve(i + 1 , s , mpp ,dp)){
                return dp[idx] = true;
            }
        }
     }
     return dp[idx] = false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , int>mpp;

        for(string x : wordDict){
             mpp[x]++;
        }
        vector<int>dp(s.size() , -1);

        return solve(0 , s , mpp , dp);
    }
};

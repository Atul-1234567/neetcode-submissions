class Solution {
public:
int solve(int ind , int n , string & s  , vector<int>&dp){
    if(ind == n)return 1;
    if(dp[ind] != -1)return dp[ind];

    if(s[ind] == '0')return 0;

     int first = solve(ind + 1 , n , s , dp);
     int second = 0;
     if(ind + 1 < n){
     if(s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6'){
        second = solve(ind + 2 , n , s , dp);
     }
     }
     return dp[ind] = first + second;
}
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return solve(0 , n , s , dp);
    }
};
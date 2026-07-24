class Solution {
public:
bool ispalindrome(string &s , int ind , int i){
     while(ind < i){
        if(s[ind] != s[i]){
            return false;
        }
        ind++;
        i--;
     }
     return true;
}
     void solve(int ind , vector<string>&ans , vector<vector<string>>&res , string s , int n){
        if(ind == n){
            res.push_back(ans);
            return;
        }
        for(int i = ind ; i < n; i++){
             if(ispalindrome(s , ind , i)){
                ans.push_back(s.substr(ind , i - ind + 1));
                solve(i + 1 , ans , res , s , n);
                ans.pop_back();
             }
        }
     }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>res;
        vector<string>ans;
        solve(0 , ans,  res , s , n);
        return res;
    }
};

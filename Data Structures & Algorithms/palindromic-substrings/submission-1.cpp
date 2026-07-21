class Solution {
public:
    int countSubstrings(string s) {
        int n =  s.size();
        int cnt = 0;

        for(int center = 0; center < n; center++){
            int left = center;
            int right = center;
            while(left >= 0 && right < n && s[left] == s[right]){
                cnt++;
                left--;
                right++;
            }

            left = center;
            right = center + 1;
             while(left >= 0 && right < n && s[left] == s[right]){
                cnt++;
                left--;
                right++;
            }
        }
        return cnt;
    }
};

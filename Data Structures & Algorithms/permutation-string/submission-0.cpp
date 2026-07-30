class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i = 0; i < n; i++){
            freq1[s1[i] - 'a']++;
        }

        int left = 0;

        for(int right = 0; right < m; right++){
            freq2[s2[right] - 'a']++;

            if(right - left + 1 == n){
                if(freq1 == freq2){
                    return true;
                }

                freq2[s2[left] - 'a']--;
                left++;
            }
        }

        return false;
    }
};
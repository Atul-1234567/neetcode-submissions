class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxlength = 0;
        int maxFreq = 0;
        unordered_map<char, int> mpp;

        for (int right = 0; right < s.size(); right++) {
           mpp[s[right]]++;

            maxFreq = max(maxFreq, mpp[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                mpp[s[left]]--;
                left++;
            }

            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};
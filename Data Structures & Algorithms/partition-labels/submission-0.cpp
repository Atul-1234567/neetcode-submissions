class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]] = i;
        }

        int left = 0;
        int right = 0;
        int end = 0;
        vector<int>ans;

        for(int right = 0; right < n; right++){
            end = max(end , mpp[s[right]]);
            if(right == end){
               int length = right - left + 1;
               ans.push_back(length);
               left = right  + 1;
            }
        }
        return ans;

    }
};

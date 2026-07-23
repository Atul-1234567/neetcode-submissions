class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int len = INT_MAX;
        unordered_map<char,int>mpp;
        for(int c :  t){
            mpp[c]++;
        }
        int count = mpp.size();
         int start = 0;
         int left = 0;
        for(int right = 0; right < n; right++){
            if(mpp.find(s[right]) != mpp.end()){
                mpp[s[right]]--;

                if(mpp[s[right]] == 0) count--;
            }
            while(count == 0){
               if(right - left + 1 < len){
                len = right - left + 1;
                 start = left;
               }

               if(mpp.find(s[left]) != mpp.end()){
                    mpp[s[left]]++;

                    if(mpp[s[left]] == 1){
                        count++;
                    }
               }
               left++;
            }
        }
          if(len == INT_MAX)return "";
        return s.substr(start , len);
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string ans = "";

        priority_queue<pair<int,char>> pq;
        vector<int> freq(26, 0);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], 'a' + i});
            }
        }

        char prev = '#';

        while(!pq.empty()) {

            auto temp = pq.top();
            pq.pop();

            int count = temp.first;
            char ch = temp.second;

            if(prev != ch) {
                ans += ch;
                prev = ch;
                count--;

                if(count > 0) {
                    pq.push({count, ch});
                }
            }
            else {

                if(pq.empty()) {
                    return "";
                }

                auto temp2 = pq.top();
                pq.pop();

                int count2 = temp2.first;
                char ch2 = temp2.second;

                ans += ch2;
                prev = ch2;
                count2--;

                if(count2 > 0) {
                    pq.push({count2, ch2});
                }

                pq.push({count, ch});
            }
        }

        return ans;
    }
};
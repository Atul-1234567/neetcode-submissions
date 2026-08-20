class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {

            auto first = pq.top();
            pq.pop();

            int freq1 = first.first;
            char ch1 = first.second;

            // Cannot use first character
            if (ans.size() >= 2 &&
                ans[ans.size() - 1] == ch1 &&
                ans[ans.size() - 2] == ch1) {

                // No alternative character
                if (pq.empty())
                    break;

                auto second = pq.top();
                pq.pop();

                int freq2 = second.first;
                char ch2 = second.second;

                // Use second character
                ans += ch2;
                freq2--;

                if (freq2 > 0)
                    pq.push({freq2, ch2});

                // First character was NOT used
                pq.push({freq1, ch1});
            }
            else {

                // Use first character
                ans += ch1;
                freq1--;

                if (freq1 > 0)
                    pq.push({freq1, ch1});
            }
        }

        return ans;
    }
};
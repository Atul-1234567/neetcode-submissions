class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Step 1: Initialize all characters
        for (auto &word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }

        // Step 2: Build graph
        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    adj[s1[j]].push_back(s2[j]);
                    indegree[s2[j]]++;
                    found = true;
                    break;
                }
            }

            // Invalid case
            if (!found && s1.size() > s2.size())
                return "";
        }

        // Step 3: Topological Sort (BFS)
        queue<char> q;

        for (auto it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        string ans = "";

        while (!q.empty()) {

            char node = q.front();
            q.pop();

            ans += node;

            for (char nei : adj[node]) {

                indegree[nei]--;

                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Step 4: Cycle check
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};
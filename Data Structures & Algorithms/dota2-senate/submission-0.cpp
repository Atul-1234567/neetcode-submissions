class Solution {
public:
    string predictPartyVictory(string senate) {

        int n = senate.size();

        queue<int> R;
        queue<int> D;

        // Store positions
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                R.push(i);
            else
                D.push(i);
        }

        while (!R.empty() && !D.empty()) {

            int r = R.front();
            int d = D.front();

            R.pop();
            D.pop();

            if (r < d) {
                // R bans D
                R.push(r + n);
            }
            else {
                // D bans R
                D.push(d + n);
            }
        }

        if (!R.empty())
            return "Radiant";
        else
            return "Dire";
    }
};
class Solution {
public:
    vector<vector<int>> dp;

    bool match(int i, int j, string &s, string &p) {

        if (i < 0 && j < 0) return true;

        if (j < 0) return false;

        if (i < 0) {
            while (j >= 0) {
                if (p[j] == '*')
                    j -= 2;
                else
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // normal character or '.'
        if (p[j] == s[i] || p[j] == '.')
            return dp[i][j] = match(i - 1, j - 1, s, p);

        // '*'
        if (p[j] == '*') {

            // ignore x*
            bool notTake = match(i, j - 2, s, p);

            // take one occurrence
            bool take = false;
            if (p[j - 1] == s[i] || p[j - 1] == '.')
                take = match(i - 1, j, s, p);

            return dp[i][j] = take || notTake;
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {

        dp.assign(s.size(), vector<int>(p.size(), -1));

        return match(s.size() - 1, p.size() - 1, s, p);
    }
};
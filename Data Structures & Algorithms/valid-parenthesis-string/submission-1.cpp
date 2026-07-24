class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;

        for (char ch : s) {
            if (ch == '(' || ch == '*')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        balance = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*')
                balance++;
            else
                balance--;

            if (balance < 0)
                return false;
        }

        return true;
    }
};

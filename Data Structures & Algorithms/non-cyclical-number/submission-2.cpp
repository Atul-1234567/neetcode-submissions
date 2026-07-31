class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (true) {
            if (n == 1)
                return true;

            if (seen.count(n))
                return false;

            seen.insert(n);

            string x = to_string(n);
            int sum = 0;

            for (char ch : x) {
                int digit = ch - '0';
                sum += digit * digit;
            }

            n = sum;
        }
    }
};
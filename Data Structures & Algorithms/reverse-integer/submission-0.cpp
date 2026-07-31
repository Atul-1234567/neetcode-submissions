class Solution {
public:
    int reverse(int x) {
        // 1. Separate the sign from the number
        bool isNegative = x < 0;
        
        // 2. Use long long to handle absolute value of INT_MIN safely
        string n = to_string(abs((long long)x)); 
        
        // 3. Your way: Reverse the string
        ::reverse(n.begin(), n.end()); 
        
        // 4. Use stoll to prevent crash on overflow during conversion
        long long rev = stoll(n); 
        
        // 5. Restore the negative sign if needed
        if (isNegative) {
            rev = -rev;
        }
        
        // 6. Return 0 if the reversed number overflows 32-bit int bounds
        if (rev < INT_MIN || rev > INT_MAX) {
            return 0;
        }
        
        return rev;
    }
};


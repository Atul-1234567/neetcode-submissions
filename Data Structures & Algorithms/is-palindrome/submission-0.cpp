class Solution {
public:
    bool isalpha(char ch){
        return (ch >= 'A' && ch <= 'Z') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= '0' && ch <= '9');
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){

            if(!isalpha(s[left])){
                left++;
                continue;
            }

            if(!isalpha(s[right])){
                right--;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
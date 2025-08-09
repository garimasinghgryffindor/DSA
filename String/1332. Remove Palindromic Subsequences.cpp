class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length()/2; i++) {
            if(s[i] != s[s.length() - i - 1]) return false;
        }
        return true;
    }

    int removePalindromeSub(string s) {
        int n = s.length();
        if(n == 0) return 0;
        if(isPalindrome(s)) return 1;
        return 2; // return all a's and the all b's
    }
};


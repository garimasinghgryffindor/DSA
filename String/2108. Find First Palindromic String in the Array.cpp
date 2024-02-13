class Solution {
public:
    bool palindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(auto x: words) {
            if(palindrome(x)) return x;
        }
        
        return "";
    }
};

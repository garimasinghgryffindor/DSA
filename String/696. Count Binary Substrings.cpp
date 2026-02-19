class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros = 0, ones = 0, res = 0;

        if(s[0] == '0') zeros++;
        if(s[0] == '1') ones++;

        for(int i = 1; i < s.length(); i++) {
            if(s[i] != s[i-1]) {
                // switching
                res += min(zeros, ones);
                if(s[i] == '1') ones = 0;
                else zeros = 0;
            } 
            if(s[i] == '0') zeros++;
            else ones++;
        }

        res+=min(zeros, ones);

        return res;
    }
};

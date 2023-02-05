class Solution {
public:
    int balancedStringSplit(string s) {
        int f = 0;
        int res = 0;
        for(int i=0 ; i<s.length() ; i++) {
            if(s[i] == 'L') {
                f++;
            } else {
                f--;
            }
            
            if(f==0) {
                res++;
            }
        }
        
        return res;
    }
};



// LEETCODE 1221

// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

// Given a balanced string s, split it into some number of substrings such that:

// Each substring is balanced.
// Return the maximum number of balanced strings you can obtain.


class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for(int i=0 ; i<32 ; i++) {
            string x;
            int num = 1 << i;
            x = to_string(num);
            sort(x.begin(), x.end());
            if(s == x)
                return true;
        }
        
        return false;
    }
};


// LEETCODE 869

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

// Return true if and only if we can do this so that the resulting number is a power of two.




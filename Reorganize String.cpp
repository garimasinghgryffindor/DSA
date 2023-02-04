class Solution {
public:
    string reorganizeString(string s) {
        vector<int>count(26,0);
        int maxFreq=0,i=0;
        for(auto ch: s) {
            count[ch-97]++;
            if(count[ch-97] > count[maxFreq]) {
                maxFreq = ch-97;
            }
        }
        
        if(2*count[maxFreq]-1 > s.length()) return "";
        
        while(count[maxFreq]) {
            s[i] = maxFreq+'a';
            i+=2;
            count[maxFreq]--;
        }
        
        for(int j=0 ; j<26 ; j++) {
            while(count[j]) {
                if(i >= s.length()) i = 1;
                s[i] = j+97;
                count[j]--;
                i+=2;
            }
        }
        
        return s;
    }
};


// LEETCODE 767

// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.



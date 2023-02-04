class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
            return false;
        
        vector<int> mainFreq(26,0);
        for(auto ch: s1) {
            mainFreq[ch-97]++;
        }
        
        vector<int>tempFreq(26,0);
        for(int i=0 ; i<s2.length()-s1.length()+1 ; i++) {
                if(i==0) {
                    for(int j=i ; j<i+s1.length() ; j++) {
                        tempFreq[s2[j]-97]++;
                    }
                } else {
                    tempFreq[s2[i-1] - 97]--;
                    tempFreq[s2[i+s1.length()-1] - 97]++;
                }
                
                if(tempFreq == mainFreq) {
                        return true;
                }
        }
        return false;
    }
};


// LEETCODE 567

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.



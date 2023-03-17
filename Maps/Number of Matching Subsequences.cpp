class Solution {
public:
    bool isSubsequence(string s,string word,int n,int m) {
        int j=0 ;
        for(int i=0 ; i<n && j<m ; i++) {
            if(s[i] == word[j]) j++;
        }
        return j==m;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int res = 0;
        map<string, bool> mp;
        
        for(auto word : words) {
            if(mp.find(word) != mp.end()) {
                // you found the word
                if(mp[word] == true) {
                    res++;
                } else {
                    continue;
                }
            }
            else {
                mp[word] = isSubsequence(s,word,s.size(),word.size());
                res += (mp[word]==true);
            }
        }
        
        return res;
    }
};


Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

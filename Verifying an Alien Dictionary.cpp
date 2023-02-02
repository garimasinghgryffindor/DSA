class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for(int i=0 ; i<order.length() ; i++) {
            mp[order[i]] = i;
        }
        
        for(int i=0 ; i<words.size()-1 ; i++) {
            int x = i, y = i+1;
            int l1 = words[x].length();
            int l2 = words[y].length();
            int len = min(l1, l2);
            int iter=0;
            while(iter<len) {
                if(mp[words[x][iter]] < mp[words[y][iter]]) {
                    break;
                } 
                else if(words[x][iter] == words[y][iter]) {
                    iter++;
                    if(iter == len && l1>l2) {
                        return false;
                    }
                    continue;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};


// LEETCODE 953
// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
  
  
  

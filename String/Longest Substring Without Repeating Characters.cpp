class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0 || s.length()==1)
            return s.length();
        
        int res = 0, tempLength = 1;
        
        int i=0 , j=1, n=s.length();
        unordered_map<char,int> mp;
        mp[s[i]] = i;
        
        while(j<n) {
            if(mp.find(s[j]) == mp.end()) {
                // if not repeating
                tempLength++;
                mp[s[j]] = j;
                j++;
            } else {
                int x = mp[s[j]];
                int l = x;
                while(l>=i && mp.find(s[l])!= mp.end()) {
                    mp.erase(s[l--]);
                }
                
                mp[s[j]] = j;
                i = x+1;
                tempLength = j-i+1;
                j++;
            }
            
            res = max(res,tempLength);
        }
        
        return res;
    }
};




LEETCODE 3
  
 
Given a string s, find the length of the longest substring without repeating characters.




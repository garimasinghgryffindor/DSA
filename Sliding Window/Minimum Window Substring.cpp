class Solution {
public:
    string minWindow(string str, string pat) {        
        int res = INT_MAX;
        int n = str.length();
        unordered_map<char,int>mp;
        for(char x: pat) {
            mp[x]++;
        }
        string ans = "";
        int count = mp.size();
        int l = 0, r = 0;
        while(r < n) {
            if(mp.find(str[r]) != mp.end()) {
                mp[str[r]]--;
                if(mp[str[r]] == 0) {
                    count--;
                }
            }
            
            if(count == 0) {
                // found
                // also shrink from the LHS
                while(l < r) {
                    if(mp.find(str[l]) == mp.end()) {
                        l++;
                    } else if(mp[str[l]] < 0) {
                        mp[str[l]]++;
                        l++;
                    } else break;
                }
                
                if(r-l+1 < res) {
                    res = r-l+1;
                    ans = str.substr(l,r-l+1);
                }
                r++;
            } else {
                // not found
                r++;
            }
        }
        
        return ans;
    }
};




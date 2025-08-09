class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0;
        int curr = 0;
        int n = s.length();
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < n; i++) {
            if(mp1.find(s[i]) == mp1.end()) {
                //. gooodie
                curr++;
                mp1[s[i]] = i;
            } else if(mp2.find(s[i]) == mp2.end()){
                curr++;
                mp2[s[i]] = i;
            } else {
                int last = mp1[s[i]];
                int start = i-curr;
                
                while(start <= last) {
                    if(mp1.find(s[start]) != mp1.end()) {
                        mp1.erase(s[start]);
                        if(mp2.find(s[start]) != mp2.end()) {
                            mp1[s[start]] = mp2[s[start]];
                            mp2.erase(s[start]);
                        }
                    } 
                    
                    start++;
                    curr--;
                }
                
                curr++;
                mp2[s[i]] = i;
            }
            res = max(res, curr);
        }

        return res;
    }
};

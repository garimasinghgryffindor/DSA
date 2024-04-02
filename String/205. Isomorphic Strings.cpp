class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> mp;
        unordered_map<char , bool> chk;
        for(int i=0 ; i<s.size() ; i++){
            if(mp[s[i]] == 0){
                if(chk[t[i]] == 0){
                    mp[s[i]] = t[i]; 
                    chk[t[i]] = 1;
                } else return false;
            }
            else {
                if(mp[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};

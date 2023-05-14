bool checkPalindrome(string s) {
        for(int i=0 ; i<s.length()/2 ; i++) {
            if(s[i] != s[s.length()-1-i])
                return false;
        }
        return true;
    }
    
    void recur(string s,vector<vector<string>>&res,vector<string>temp, int idx) {
        if(idx == s.length()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=idx ; i<s.length() ; i++) {
            if(checkPalindrome(s.substr(idx,i-idx+1))) {
                temp.push_back(s.substr(idx,i-idx+1));
                recur(s,res,temp,i+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>temp;
        int idx = 0;
        recur(s,res,temp,idx);
        
        return res;
    }

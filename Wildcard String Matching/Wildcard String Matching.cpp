class Solution {
public:
    bool recur(string&s,string&p,int i,int j) {
        if(i < 0 && j < 0) return true;
        if(j < 0 && i >= 0) return false;
        if(i < 0 && j >= 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }
        
        if(s[i] == p[j] || p[j] == '?') return recur(s,p,i-1,j-1);
        if(p[j] == '*') {
            return recur(s,p,i-1,j) || recur(s,p,i,j-1);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
        // using Recursion
        int n = s.length(), m = p.length();
        return recur(s,p,n-1,m-1);
    }
};






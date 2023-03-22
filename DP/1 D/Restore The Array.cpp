// MEMOIZATION

class Solution {
public:
    long long MOD = 1e9+7;
    vector<int> dp;
    long long recur(string&s,int k,int pos) {
        if(pos == s.length())
            return 1;
        
        if(s[pos]=='0') return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
        
        int res = 0;
        long long x = 0;
        for(int i=pos ; i<s.length() ; i++) {
            x = x*10 + s[i]-'0';
            if(x>=1 && x<=k) {
                // A ok
                res += recur(s,k,i+1);
                res %= MOD;
            } else {
                break;
            }
        }
        
        return dp[pos]=res;
    }
    
    int numberOfArrays(string s, int k) {
        dp.resize(s.length()+1, -1);
        return recur(s,k,0);
    }
};



// TABULATION

class Solution {
public:
    long long MOD = 1e9+7;
    
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length()+1,0);
        
        dp[s.length()] = 1;
        
        for(int i=s.length()-1 ; i>=0 ; i--) {
            if (s[i] == '0')
                continue;
            
            long long res = 0;
            long long x = 0;
            for(int j=i ; j<s.length() ; j++) {
                x = x*10 + s[j]-'0';
                if(x>=1 && x<=k) {
                    // A ok
                    res += dp[j+1];
                    res %= MOD;
                } else {
                    break;
                }
            }
            
            dp[i] = res;
        }
        
        return dp[0];
    }
};

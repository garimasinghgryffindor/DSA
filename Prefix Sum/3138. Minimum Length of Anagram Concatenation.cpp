class Solution {
public:
    vector<int> divisors(int n) {
        vector<int>res;
        // res.push_back(n);
        for(int i = 1; i <= sqrt(n); i++) {
            if(n%i == 0) {
                res.push_back(i);
                if(n/i != i)
                    res.push_back(n/i);
            }
        }
        
        sort(res.rbegin(), res.rend());
        return res;
    }
    
    int minAnagramLength(string s) {
        int n = s.length(); 
        vector<int>div = divisors(n);
        int res = n;
        
        vector<vector<int>>freq(n, vector<int>(26, 0));
        
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                freq[i] = freq[i-1];
            }
            freq[i][s[i]-'a']++;
        }
        
        
        for(int i = 0; i < div.size(); i++) {
            int x = div[i];
            
            bool flag = true;
            for(int i = x+x-1; i < n; i+=x) {
                for(int j = 0; j < 26; j++) {
                    if(freq[i][j]-freq[i-x][j] != freq[x-1][j]) {
                        flag = false;   break;
                    }
                }
                if(!flag) break;
            }
            if(flag) {
                res = x;
            }
        }
        
        return res;
    }
};

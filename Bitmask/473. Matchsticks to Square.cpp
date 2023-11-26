// BRUTE FORCE  -----> TLE
class Solution {
public:
    
    bool recur(vector<int>&vec, int idx, int s1, int s2, int s3, int s4) {
        if(s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0) return true;
        if(s1 < 0 || s2 < 0 || s3 < 0 || s4 < 0) return false;
        
        if(idx < 0) return false;
        
        if(recur(vec, idx-1, s1-vec[idx], s2, s3, s4) || recur(vec, idx-1, s1, s2-vec[idx], s3, s4) || recur(vec, idx-1, s1, s2, s3-vec[idx], s4) || recur(vec, idx-1, s1, s2, s3, s4-vec[idx])) return true;
        
        return false;               
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int peri = 0;
        
        for(int x: matchsticks) {
            peri += x;
        }
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        if(peri % 4 != 0) return false;
        
        int idealLength = peri / 4;
        int n = matchsticks.size();
        if(matchsticks[0] > idealLength) return false;
        
        return recur(matchsticks, n-1, idealLength, idealLength, idealLength, idealLength);
        
    }
};


// BITMASK
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int peri = 0;
        unordered_map<int, int> freq;
        
        for(int x: matchsticks) {
            peri += x;
            freq[x]++;
        }
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        
        if(peri % 4 != 0) return false;
        
        int idealLength = peri / 4;
        if(matchsticks[0] > idealLength) return false;
        
        int N = matchsticks.size();
        vector<int>dp(1<<N, -1); dp[0] = 0;
        
        for(int i = 1; i < 1<<N; i++) {
            for(int j = 0; j < N; j++) {
                int exclude = dp[i^(1<<j)];
                if(exclude >= 0 && matchsticks[j] + exclude <= idealLength && (i & (1<<j))) {
                    dp[i] = (matchsticks[j] + exclude)%idealLength;
                    break;
                }
            }
        }
        
        return dp.back() == 0;
    }
};

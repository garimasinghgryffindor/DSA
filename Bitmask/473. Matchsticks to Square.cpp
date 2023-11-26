// BRUTE FORCE  -----> TLE
// class Solution {
// public:
    
//     bool recur(unordered_map<int,int>mp, int idealLength, int n, int currLength) {
//         if(n == 0) return true;
        
//         int reqLength = idealLength - currLength;
        
//         for(auto x: mp) {
//             int len = x.first, freq = x.second;
//             if(freq) {
//                 if(len < reqLength) {
//                     mp[len]--;
//                     if(recur(mp, idealLength, n-1, currLength + len)) return true;
//                     mp[len]++;
//                 } else if(len == reqLength) {
//                     mp[len]--;
//                     if(recur(mp, idealLength, n-1, 0)) return true;
//                     mp[len]++;
//                 }
//             }
//         }
        
//         return false;               
//     }
    
//     bool makesquare(vector<int>& matchsticks) {
//         int peri = 0;
//         unordered_map<int, int> freq;
        
//         for(int x: matchsticks) {
//             peri += x;
//             freq[x]++;
//         }
        
//         sort(matchsticks.rbegin(), matchsticks.rend());
        
//         if(peri % 4 != 0) return false;
        
//         int idealLength = peri / 4;
//         if(matchsticks[0] > idealLength) return false;
        
//         return recur(freq, idealLength, matchsticks.size(), 0);
        
//     }
// };


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

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        int sum = 0;
        int res = 0;
        
        // to keep track of previous sums;
        unordered_map<int,int> mp;
        for(int i=0 ; i<n ; i++) {
            if(hours[i] > 8) {
                sum++;
            } else {
                sum--;
            }
            
            if(sum > 0) {
                res = i+1;
            }
            else {
                if(mp.find(sum-1) != mp.end()) {
                    int idx = mp[sum-1];
                    res = max(res, i-idx);
                }
            }
            
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return res;
    }
};

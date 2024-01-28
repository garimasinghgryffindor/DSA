// QUESTION: Prefix Sum in 2D basically!!!!
// MUST DO!!!!!!!!!!!

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        int count = 0;
        
        for(int i = 0; i < r; i++) {
            vector<int>cummulativeSum = matrix[i];
            
            for(int j = i; j < r; j++) {
                unordered_map<int, int> mp;
                int tot = 0;
                for(int k = 0; k < c; k++) {
                    tot += cummulativeSum[k];
                    if(tot == target) count++;
                    if(mp[(tot-target)]) {
                        count+=mp[tot-target];
                    }
                    mp[tot]++;
                    if(j+1 <= r-1) cummulativeSum[k] += matrix[j+1][k];
                }
            }
        }
        
        return count;
    }
};

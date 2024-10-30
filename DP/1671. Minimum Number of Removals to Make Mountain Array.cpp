class Solution {
public:
    
    int recurL(vector<int>&nums, int idx, int prev, vector<vector<int>>&dpL) {
        if(idx < 0) return 0;
        if(prev != -1 && dpL[idx][prev] != -1) return dpL[idx][prev];
        
        int curr = 0;
        if(prev == -1 || nums[idx] < nums[prev]) {
            curr = max(curr, 1 + recurL(nums, idx-1, idx, dpL));
            curr = max(curr, recurL(nums, idx-1, prev, dpL));
        } else {
            curr = max(curr, recurL(nums, idx-1, prev, dpL));
        }
        
        if(prev == -1) return curr;
        return (dpL[idx][prev] = curr);
        // return curr;
    }
    
    int recurR(vector<int>&nums, int idx, int prev, vector<vector<int>>&dpR) {
        if(idx >= nums.size()) return 0;
        if(prev != -1 && dpR[idx][prev] != -1) return dpR[idx][prev];
        
        int curr = 0;
        if(prev == -1 || nums[idx] < nums[prev]) {
            curr = max(curr, 1 + recurR(nums, idx+1, idx, dpR));
            curr = max(curr, recurR(nums, idx+1, prev, dpR));
        } else {
            curr = max(curr, recurR(nums, idx+1, prev, dpR));
        }
        
        if(prev == -1) return curr;
        return (dpR[idx][prev] = curr);
        // return curr;
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        // DP approach
        int res = INT_MAX;
        int n = nums.size();
        vector<vector<int>>dpL(n, vector<int>(n, -1));
        vector<vector<int>>dpR(n, vector<int>(n, -1));
        
        for(int i = 1; i < n-1 ; i++) {
            int ansL = recurL(nums, i, -1, dpL);
            if(ansL == -1 || ansL == 1) continue;
            int ansR = recurR(nums, i, -1, dpR);
            if(ansR == -1 || ansR == 1) continue;
            res = min(res, n-(ansL+ansR-1));
        }
        
        return res;
    }
};

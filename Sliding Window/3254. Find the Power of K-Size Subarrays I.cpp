class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        
        int n = nums.size();
        int res_size = n-k+1;
        vector<int>res(res_size, 0);
        
        vector<int>consec(n, 0);
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1] + 1) {
                consec[i] = 1;
            }
        }
        
        vector<int>pref(n, 0);
        for(int i = 1; i < n; i++) {
            pref[i] += pref[i-1] + consec[i];
        }
        
        for(int i = k-1; i < n; i++) {
            if(i == k-1) {
                if(pref[i] == k-1) {
                    res[i-k+1] = nums[i];
                } else {
                    res[i-k+1] = -1;
                }
            } else {
                if(pref[i] - pref[i-k+1] == k-1) {
                    res[i-k+1] = nums[i];
                } else {
                    res[i-k+1] = -1;
                }
            }
        }
        
        return res;
    }
};

class Solution {
public:
    bool possible(vector<int>&nums, vector<vector<int>>&queries, int mid) {
        int n = nums.size();
        vector<int>prefix(n+1, 0);
        for(int i = 0; i <= mid; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            prefix[l] += k;
            prefix[r+1] -= k;
        }

        for(int i = 1; i < n; i++) {
            prefix[i] += prefix[i-1];
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] > prefix[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        int l = 0, r = q-1;
        int res = -1;

        bool allzeroes = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                allzeroes = false;  break;
            }
        }

        if(allzeroes == true) return 0;

        while(l <= r) {
            int mid = l + (r-l)/2;
            if(possible(nums, queries, mid)) {
                res = mid+1;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
    }
};

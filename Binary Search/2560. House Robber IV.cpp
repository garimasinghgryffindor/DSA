class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // questions boils down to exactly k rather than at least
        int res = INT_MAX, n = nums.size();
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while(l <= r) {
            int mid = l + (r-l)/2;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(nums[i] <= mid) {
                    cnt++;
                    i++;
                    if(cnt == k) {
                        res = mid;
                        r = mid-1;
                        break;
                    }
                }
            }
            if(cnt < k) {
                l = mid+1;
            }
        }
        return res;
    }
};




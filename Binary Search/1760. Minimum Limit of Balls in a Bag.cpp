class Solution {
public:
    int utils(vector<int>&nums, int mid) {
        int res = 0;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] <= mid) return res+i+1;
            res += nums[i]/mid;
            if(nums[i]%mid != 0) res++;
        }

        return res;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int res = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mx = nums[n-1];
        int l = 1, r = mx;
        while(l <= r) {
            int mid = l + (r-l)/2;
            int nm_of_elements = utils(nums, mid);
            
            if(nm_of_elements <= n+maxOperations) {
                res = min(res, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return res;
    }
};



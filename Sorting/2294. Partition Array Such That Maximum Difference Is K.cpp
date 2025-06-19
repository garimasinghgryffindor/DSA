class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int iter = 1;
        int last = 0;
        int n = nums.size();
        while(iter < n) {
            if(nums[iter] - nums[last] <= k) {
                // all good
                iter++;
            } else {
                res++;
                last = iter;
            }
        }
        res++;

        return res;
    }
};

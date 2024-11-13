class Solution {
public:
    long long utils(vector<int>&nums, int sum) {
        long long res = 0;
        int l = 0, r = nums.size()-1;
        while(l < r) {
            if(nums[l] + nums[r] <= sum) {
                res += (long long) (r-l);
                l++;
            } else r--;
        }
        
        return res;
    }
    
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int res = 0;
        sort(nums.begin(), nums.end());
        
        long long temp = utils(nums, upper);
        long long temp2 = utils(nums, lower-1);
        
        return temp - temp2;
    }
};

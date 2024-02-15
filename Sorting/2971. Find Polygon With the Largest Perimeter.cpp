class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // correct answer will be a sum of set of consecutive elements
        
        long long sum = 0;
        for(int x: nums) {
            sum += x;
        }
        
        for(int i = n-1; i >= 2; i--) {
            sum -= nums[i];
            if(sum > nums[i]) return sum+nums[i];
        }
        return -1;
    }
};

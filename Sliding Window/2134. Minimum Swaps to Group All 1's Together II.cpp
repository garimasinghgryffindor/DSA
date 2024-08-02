class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOnes = 0;
        for(int x: nums) {
            countOnes += x;
        }
        int count = 0, res = INT_MAX;
        for(int i = 0; i < countOnes; i++) {
            count += nums[i];
        }
        res = min(res, countOnes - count);
        for(int i = countOnes; i < nums.size(); i++) {
            count -= nums[i-countOnes];
            count += nums[i];
            res = min(res, countOnes - count);
        }
        
        for(int i = 0; i < countOnes-1; i++) {
            count -= nums[nums.size()+i-countOnes];
            count += nums[i];
            res = min(res, countOnes - count);
        }
        
        return res;
    }
};


class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long int sum = 0;
        long int res = 0;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i]==0) {
                sum++;
            } else {
                if(sum != 0) {
                    // sum of n numbers-> n(n+1)/2
                    res += sum*(sum+1)/2;
                }
                sum = 0;
            }
        }
        
        if(sum != 0) {
            res += sum*(sum+1)/2;
        }
        
        return res;
    }
};

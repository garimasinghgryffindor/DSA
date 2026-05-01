class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        int sum = 0, sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            sum2 += nums[i] * i;
        }

        res = max(res, sum2);

        for(int i = 0; i < n-1; i++) {
            sum2 -= sum;
            sum2 += nums[i]*n;
            res = max(res, sum2);
        }

        return res;
    }
};

// [1, 2, 3, 4, 5] -> 0 + 2*1 + 3*2 + 4*3 + 5*4
// [2, 3, 4, 5, 1] -> 40 - 15 + 5 = 30
// -> 2*0 + 3*1 + 4*2 + 5*3 + 1*4 = 30


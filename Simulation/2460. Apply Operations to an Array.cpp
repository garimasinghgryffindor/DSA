class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        int cnt = 0;
        int i;
        for(i = 0; i < n-1; i++) {
            if(nums[i] != 0) {
                if(nums[i] == nums[i+1]) {
                    res[cnt] = nums[i]*2;
                    i++;
                } else {
                    res[cnt] = nums[i];
                }
                cnt++;
            }
        }

        if(i != n) {
            res[cnt] = nums[n-1];
        }

        return res;
    }
};

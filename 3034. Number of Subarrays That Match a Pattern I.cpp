class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int res = 0;
        int n = nums.size(), p = pattern.size();
        vector<int>vec(n, 0);
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                vec[i] = 1;
            } else if(nums[i] == nums[i-1]) {
                vec[i] = 0;
            } else {
                vec[i] = -1;
            }
        }

        for(int i = 1; i <n-p+1; i++) {
            bool flag = true;
            for(int j = 0; j < p; j++) {
                if(vec[i+j] != pattern[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) res++;
        }

        return res;
    }
};

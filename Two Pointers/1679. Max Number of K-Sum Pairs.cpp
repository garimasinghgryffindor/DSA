class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // using unordered map to keep track and count
        unordered_map<int, int> frq;
        int res = 0;
        
        for(auto x: nums) {
            if(frq[k-x] != 0) {
                res++;
                frq[k-x]--;
            } else {
                frq[x]++;
            }
        }
        
        return res;
    }
};



class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // using two pointers
        int res = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right) {
            if(nums[left] + nums[right] == k) {
                res++;
                left++;
                right--;
            } else if(nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        
        return res;
    }
};



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums[0];
        for(auto x: nums) {
            if(count == 0) {
                count = 1;
                candidate = x;
            } else if(candidate == x) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};

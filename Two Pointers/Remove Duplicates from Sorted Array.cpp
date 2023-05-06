// Two Pointer

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0 , j=i+1;
        int n = nums.size();
        
        while(j<n) {
            if(nums[i] != nums[j]) {
                // A ok
                i++;
                nums[i] = nums[j];
            } else {
                j++;
            }
        }
        
        return i+1;
    }
};

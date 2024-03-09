class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0, l2 = 0, r1 = nums1.size()-1, r2 = nums2.size()-1;
        
        while(l1 <= r1 && l2 <= r2) {
            if(nums1[l1] == nums2[l2]) {
                return nums1[l1];
            }
            
            if(nums1[l1] < nums2[l2]) {
                l1++;
            } else {
                l2++;
            }
            
            if(nums1[r1] < nums2[r2]) {
                r2--;
            } else if(nums1[r1] == nums2[r2]) {
                // do nothing
            } else {
                r1--;
            }
        }
        
        return -1;
    }
};

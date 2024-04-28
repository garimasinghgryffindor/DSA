class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int mn1 = INT_MAX;
        for(int x: nums1) mn1 = min(mn1, x);
        int mn2 = INT_MAX;
        for(int x: nums2) mn2 = min(mn2, x);
        
        return mn2 - mn1;
        
    }
};

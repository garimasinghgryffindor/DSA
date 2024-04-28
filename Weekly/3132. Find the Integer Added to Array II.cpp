class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MAX;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums1.size(); j++) {
                if(i != j) {
                    int x = 0;
                    int k = 0;
                    int diff = -1;
                    bool flag = true;
                    while(k < nums2.size()) {
                        if(i != x && j != x) {
                            if(k == 0) diff = nums2[k] - nums1[x];
                            else {
                                int c = nums2[k] - nums1[x];
                                if(diff != c) {
                                    flag = false;
                                    break;
                                }
                            }
                            k++;
                        }
                        x++;
                    }
                    
                    if(flag) {
                        if(res > abs(diff)) {
                            res = diff;
                        }
                    }
                }
            }
        }
        return res;
        // return nums2[0] - nums1[2];
    }
};

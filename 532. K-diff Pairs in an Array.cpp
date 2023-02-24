class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        if(nums.size() == 1)
            return 0;
        sort(nums.begin(),nums.end());
        // auto it = unique(nums.begin(), nums.end());
        // nums.resize(distance(nums.begin(), it));
        int n = nums.size();
        int i=0, j=1;
        
        while(i<n-1) {
            j = i+1;
            while(j<n) {
                if(nums[j]-nums[i] == k) {
                    res++;
                    break;
                }
                else if(nums[j]-nums[i] <k) {
                    j++;
                }
                else {
                    break;
                }
            }
            
            if(nums[i]!=nums[i+1]) {
                i++;
                continue;
            }
            else {
                while(i<n && i+1<n && nums[i] == nums[i+1]) {
                    i++;
                }
                i++;
            }
        }
        
        return res;
        
    }
};

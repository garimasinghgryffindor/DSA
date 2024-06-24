class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int>isFlipped(n, 0);
        int flipped = 0;
        for(int i = 0; i < n; i++) {
            if(i >= k) {
                flipped ^= isFlipped[i-k];
            }
            
            if(flipped == nums[i]) {
                // required to be flipped
                if(i+k > n) {
                    // not possible
                    return -1;
                }
                flipped ^= 1;
                res++;
                isFlipped[i] = 1;
            }
        }
        
        return res;
    }
};

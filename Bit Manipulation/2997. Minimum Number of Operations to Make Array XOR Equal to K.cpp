class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // curr -> 010 ^ 001 ^ 011 ^ 100 = > 100  => 001  (diff bits)
        int res = 0;
        int xor_ = 0;
        for(int x: nums) {
            xor_ ^= x;
        }
        
        while(k || xor_) {
            int x = k%2;
            int y = xor_%2;
            if(x != y) {
                res++;
            }
            k/=2;
            xor_/=2;
        }
        
        return res;
    }
};

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_ = start ^ goal;
        int res = 0;
        while(xor_) {
            res += xor_&1;
            xor_ >>=1;
        }
        return res;
    }
};

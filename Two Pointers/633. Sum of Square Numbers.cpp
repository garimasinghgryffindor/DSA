class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);
        while(l <= r) {
            long temp = (long)l*l + (long)r*r;
            if(temp == c) return true;
            else if(temp < c) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }
};

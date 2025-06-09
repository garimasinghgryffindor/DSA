class Solution {
public:
    int findKthNumber(int n, int k) {
        long prefix = 1;
        k--;

        while(k > 0) {
            long sz = 0;
            long curr = prefix;
            long next = prefix+1;

            while(curr <= n) {
                sz += min((long)n+1, next) - curr;
                curr *= 10;
                next *= 10;
            }

            if(sz <= k) {
                prefix++;
                k-=sz;
            } else {
                prefix*=10;
                k--;
            }
        }

        return (int)prefix;
    }
};

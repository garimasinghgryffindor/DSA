class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans = x;
        for(long long i = 0; n; i++) {
            if(!(ans&(1ll<<i))) {
                if(n&1) {
                    ans ^= (1ll<<i);
                }
                n/=2;
            }
        }
        
        return ans;
    }
};

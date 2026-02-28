class Solution {
public:
    int concatenatedBinary(int n) {
        long long int res = 0;
        int M = 1e9+7;
        for(int i = 1; i <= n; i++) {
            int pos = 1 + (int)log2(i);
            res = ((res << pos)%M + i)%M;
        }

        return (int)res;
    }
};

class Solution {
public:
    int findbits(int n) {
        int cnt = 0;
        while(n) {
            int bit = n & 1;
            cnt+=bit;
            n>>=1;
        }
        return cnt;
    }

    bool isPrime(int n) {
        if(n == 1) return false;
        if(n == 2 || n == 3) return true;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n%i == 0) return false;
        }
        return true;;
    }

    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(int i = left; i <= right; i++) {
            int bits = findbits(i);
            res += isPrime(bits);
        }

        return res;
    }
};

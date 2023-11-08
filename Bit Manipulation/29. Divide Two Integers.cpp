class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        bool minus = false;
        
        if((dividend < 0 && divisor >= 0) || (divisor < 0 && dividend >= 0)) {
            minus = true;
        }
        
        long divid = abs(dividend);
        long divis = abs(divisor);
        long res = 0;
        
        while(divid >= divis) {
            long x = 1;
            long div = divis;
            while((div << x) <= divid) {
                x++;
            }
            x--;
            divid -= (div << x);
            res += (1ll << x);
        }
        
        if(minus) return -res;
        if(res == 2147483648) return INT_MAX;
        return res;
    }
};

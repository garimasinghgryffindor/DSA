class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        double res = 1.0;
        
        if(nn < 0) nn = -1*nn;
        
        while(nn > 0) {
            if(nn%2 == 1) {
                // odd
                res = res*x;
                nn--;
            } else {
                // even
                x = x*x;
                nn/=2;
            }
        }
        
        if(n < 0) 
            res = 1.0 / res;
        
        return res;
    }
};

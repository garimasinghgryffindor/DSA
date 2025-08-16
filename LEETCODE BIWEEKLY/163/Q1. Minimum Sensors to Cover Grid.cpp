class Solution {
public:
    int minSensors(int n, int m, int k) {
        int res = 0;
        int factor = 2*k+1;
        int row_wise = m/factor;
        if(m%factor != 0) row_wise++;

        int col_wise = n/factor;
        if(n%factor != 0) col_wise++;

        res = row_wise*col_wise;
        
        return res;
    }
};©leetcode

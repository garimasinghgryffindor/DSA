class Solution {
public:
    int uniquePaths(int m, int n) {
        // m+n-2Cn-1  or m+n-2Cm-1 
        int N = m+n-2;
        int r = n-1;
        long long res = 1;
        for(int i=1 ; i<=r ; i++) {
            res = res*(N-r+i)/i;
        }
        
        return res;
    }
};

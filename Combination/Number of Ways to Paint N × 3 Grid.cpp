class Solution {
public:
    int numOfWays(int n) {
        long same = 6 , diff = 6;
        long mod = (long)1e9 + 7;
        for(int i=0 ; i<n-1 ; i++) {
            long sameTemp = 3*same + 2*diff;
            long diffTemp = 2*diff + 2*same;
            
            same = sameTemp%mod;
            diff = diffTemp%mod;
        }
        
        return (same + diff)%mod;
    }
};



LEETCODE 1411
  
  
You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.


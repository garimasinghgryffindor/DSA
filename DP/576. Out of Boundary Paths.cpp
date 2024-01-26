class Solution {
public:
    // Approach 1
    // using recursion
    // trying every possible path
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // let us try using dfs
        if(startRow == -1 || startColumn == -1 || startRow == m || startColumn == n) {
            return 1;
        }
        
        if(maxMove == 0) return 0;
        
        int sum = 0;
        sum = (sum + findPaths(m, n, maxMove-1, startRow+1, startColumn)) % mod;
        sum = (sum + findPaths(m, n, maxMove-1, startRow-1, startColumn)) % mod;
        
        sum = (sum + findPaths(m, n, maxMove-1, startRow, startColumn+1)) % mod;
        sum = (sum + findPaths(m, n, maxMove-1, startRow, startColumn-1)) % mod;
        
        return sum;
    }
};


class Solution {
public:
    // Approach 1
    // using recursion
    // Memoization
    int mod = 1e9 + 7;
    int dp[51][51][51];
    
    int recur(int m,int n,int maxMove,int startRow,int startColumn) {
        // let us try using dfs
        if(startRow <= -1 || startColumn <= -1 || startRow >= m || startColumn >= n) {
            return 1;
        }
        
        if(maxMove <= 0) return 0;
        
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        
        long sum = 0;
        sum = (sum + recur(m, n, maxMove-1, startRow+1, startColumn)) % mod;
        sum = (sum + recur(m, n, maxMove-1, startRow-1, startColumn)) % mod;
        
        sum = (sum + recur(m, n, maxMove-1, startRow, startColumn+1)) % mod;
        sum = (sum + recur(m, n, maxMove-1, startRow, startColumn-1)) % mod;
        
        return dp[startRow][startColumn][maxMove] = (int)sum;
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return recur(m, n, maxMove, startRow, startColumn);
    }
    
};

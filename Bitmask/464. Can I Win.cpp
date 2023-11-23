class Solution {
public:
    bool dfs(int max, int tot, int k) {
        if(mem[k] != 0) return mem[k] > 0;
        
        if(tot <= 0) return false;
        
        for(int i = 0; i < max; i++) {
            if(!(k&(1<<i)) && !dfs(max, tot - (i+1), k|(1<<i))) {
                mem[k] = 1;
                return true;
            }
        }
        
        mem[k] = -1;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int max = maxChoosableInteger; 
        int tot = desiredTotal;
        
        int sum = max*(max+1)/2;
        
        if(tot < 2) return true;
        if(sum < tot) return false;
        if(sum == tot) return max%2;
        
        return dfs(max, tot, 0);
    }
    int mem[1<<20] = {};
};


class Solution {
  public:
    int MaxMoney(int M, vector<int> &B, vector<int> &A) {
        // code here
        int res = M;
        for(int i = 0; i < 3; i++) {
            if(B[i] > M) continue;
            int coins = M/B[i];
            if(A[i] >= B[i]) {
                res = max(res, coins*A[i] + M%B[i]);
            }
        }
        
        return res;
    }
};

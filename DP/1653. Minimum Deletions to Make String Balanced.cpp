class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int res = INT_MAX;
        vector<int>as(n, 0), bs(n, 0);
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            auto x = s[i];
            if(x == 'a') a++;
            else b++;
            as[i] = a;
            bs[i] = b;
        }
        
        for(int i = 0; i <= n; i++) {
            int b_before = 0, a_after = 0;
            
             if(i == 0) {
                 a_after = as[n-1];
             } else if(i == n) {
                 b_before = bs[n-1];
             } else {
                 a_after = as[n-1] - as[i-1];
                 b_before = bs[i-1];
             }
            
            res = min(res, a_after + b_before);
        }
        
        return res;
    }
};

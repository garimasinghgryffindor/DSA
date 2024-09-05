class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int x: rolls) {
            sum += x;
        }
        
        int rem_sum = (n+m)*mean - sum;
        
        // this remaining sum has to be achieved by n values
        
        if(rem_sum < n) return {};
        
        int q = rem_sum/n;
        if(q > 6) return {};
        
        vector<int>res;
        if(rem_sum%n == 0) {
            res.resize(n, q);
            return res;
        } else {
            if(q == 6) return {};
            
            res.resize(n, q);
            int rest = rem_sum % n;
            for(int i = 0; i < n; i++) {
                if(rest > 5) {
                    rest -= 6-res[i];
                    res[i] = 6;
                } else {
                    if(res[i] != 6) {
                        int capa = 6 - res[i];
                        if(capa < rest) {
                            rest -= capa;
                            res[i] = 6;
                        } else {
                            res[i] += rest;
                            rest = 0;
                            return res;
                        }
                    }
                }
            }
            return res;
        }
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, n = customers.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                res += customers[i];
            }
        }
        
        ans = max(res, ans);
        
        int temp = 0;
        for(int i = 0; i < minutes; i++) {
            if(grumpy[i]) {
                temp += customers[i];
            }
        }
        
        res += temp;
        ans = max(ans, res);
        
        for(int i = minutes; i < n; i++) {
            if(grumpy[i-minutes]) {
                res -= customers[i-minutes];
            }
            if(grumpy[i]) {
                res += customers[i];
            }
            ans = max(ans, res);
        }
        
        return ans;
    }
};

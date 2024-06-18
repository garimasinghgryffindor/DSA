class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res = 0;
        int mxDifclt = *max_element(difficulty.begin(), difficulty.end());
        vector<int>diff(mxDifclt+1, 0);
        
        for(int i = 0; i < difficulty.size(); i++) {
            diff[difficulty[i]] = max(diff[difficulty[i]], profit[i]);
        }
        
        for(int i = 1; i <= mxDifclt; i++) {
            diff[i] = max(diff[i], diff[i-1]);
        }
        
        for(int i : worker) {
            if(i <= mxDifclt) res += diff[i];
            else res += diff[mxDifclt];
        }
        
        return res;
    }
};

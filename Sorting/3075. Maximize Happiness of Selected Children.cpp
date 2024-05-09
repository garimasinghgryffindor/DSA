class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        sort(happiness.rbegin(), happiness.rend());
        int n = happiness.size();
        int i = 0;
        while(k--) {
            happiness[i] = max(happiness[i]-i, 0);
            res += happiness[i++];
        }
        
        return res;
    }
};




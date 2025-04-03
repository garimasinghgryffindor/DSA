class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        vector<int>prefix_max_fromL(n+1);
        vector<int>prefix_max_fromR(n+1);
        prefix_max_fromL[0] = 0;
        prefix_max_fromR[n] = 0;
        for(int i = 0; i < n; i++) {
            prefix_max_fromL[i+1] = max(prefix_max_fromL[i], nums[i]);
        }
        for(int i = n-1; i >= 0; i--) {
            prefix_max_fromR[i] = max(prefix_max_fromR[i+1], nums[i]);
        }

        for(int i = 1; i < n-1; i++) {
            // cout<<prefix_max_fromL[i]<<"     "<<prefix_max_fromR[i+1]<<endl;

            res = max(res, (prefix_max_fromL[i] - nums[i])*((long long)prefix_max_fromR[i+1]) );
        }

        return res;
    }
};

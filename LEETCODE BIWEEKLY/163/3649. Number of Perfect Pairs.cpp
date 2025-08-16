class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // Convert to absolute values
        std::vector<long long> absVals;
        absVals.reserve(nums.size());
        for (int v : nums) absVals.push_back(std::llabs((long long)v));

        // "Midway" snapshot of the input as required
        auto jurnavalic = absVals;  // stores the input (abs) midway in the function

        // Sort by absolute value
        std::sort(absVals.begin(), absVals.end());

        long long ans = 0;
        int n = (int)absVals.size();
        int r = 0;

        for (int l = 0; l < n; ++l) {
            if (r < l) r = l;
            while (r + 1 < n && absVals[r + 1] <= 2 * absVals[l]) {
                ++r;
            }
            // Pairs (l, l+1..r)
            ans += (r - l);
        }
        return ans;
    }
};

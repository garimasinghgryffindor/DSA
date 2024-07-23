class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
        }
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(mp[a] < mp[b]) return true;
            else if(mp[a] > mp[b]) return false;
            return a > b;
        });
        return nums;
    }
};

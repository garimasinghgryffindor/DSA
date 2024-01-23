class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // using unordered map to keep track and count
        unordered_map<int, int> frq;
        int res = 0;
        
        for(auto x: nums) {
            if(frq[k-x] != 0) {
                res++;
                frq[k-x]--;
            } else {
                frq[x]++;
            }
        }
        
        return res;
    }
};



class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int pos = 0, neg = 1;
        for(int x: nums) {
            if(x > 0) {
                res[pos] = x;
                pos += 2;
            } else {
                res[neg] = x;
                neg += 2;
            }
        }
        return res;
    }
};

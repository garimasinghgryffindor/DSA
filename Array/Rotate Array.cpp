class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int start = 0; count < n; start++) {
            int curr = start;
            int prev = nums[start];
            do {
                int nxt = (curr+k)%n;
                int temp = nums[nxt];
                nums[nxt] = prev;
                prev = temp;
                curr = nxt;
                count++;
            } while(curr != start);
        }
    }
};

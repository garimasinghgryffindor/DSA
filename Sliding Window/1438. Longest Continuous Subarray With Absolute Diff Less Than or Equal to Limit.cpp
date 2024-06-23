// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         // brute force
//         int n = nums.size();
//         int res = 0;
//         for(int i = 0; i < n; i++) {
//             int mn = nums[i], mx = nums[i];
//             for(int j = i; j < n; j++) {
//                 mn = min(mn, nums[j]);
//                 mx = max(mx, nums[j]);
//                 if(mx - mn <= limit) {
//                     res = max(res, j-i+1);
//                 }
//             }
//         }
        
//         return res;
//     }
// };


// SLIDING WINDOW
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> increase;
        deque<int> decrease;
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (!increase.empty() && nums[right] < increase.back()) {
                increase.pop_back();
            }
            increase.push_back(nums[right]);

            while (!decrease.empty() && nums[right] > decrease.back()) {
                decrease.pop_back();
            }
            decrease.push_back(nums[right]);

            while (decrease.front() - increase.front() > limit) {
                if (nums[left] == decrease.front()) {
                    decrease.pop_front();
                }
                if (nums[left] == increase.front()) {
                    increase.pop_front();
                }
                ++left;
            }

            max_len = std::max(max_len, right - left + 1);
        }

        return max_len;
    }
};

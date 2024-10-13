class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int curr_max = INT_MIN;
        for(int i = 0; i < n; i++) {
            minHeap.push({nums[i][0], i, 0});
            curr_max = max(curr_max, nums[i][0]);
        }
        
        int start = 0, end = INT_MAX;
        
        while(minHeap.size() == n) {
            auto temp = minHeap.top();      minHeap.pop();
            int ele = temp[0], idx = temp[1], col = temp[2];
            
            if(curr_max - ele < end - start) {
                start = ele;
                end = curr_max;
            }
            
            if(col + 1 < nums[idx].size()) {
                minHeap.push({nums[idx][col+1], idx, col+1});
                curr_max = max(curr_max, nums[idx][col+1]);
            }
        }
        
        return {start, end};
        
    }
};

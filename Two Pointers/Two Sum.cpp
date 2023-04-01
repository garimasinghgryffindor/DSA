class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> newNums;
        for(int i=0 ; i<nums.size() ; i++) {
            newNums.push_back({nums[i], i});
        }
        
        sort(newNums.begin(), newNums.end());
        
        int left = 0, right = nums.size()-1;
        
        while(left < right) {
            if(newNums[left].first + newNums[right].first == target) {
                return {newNums[left].second, newNums[right].second};
            } else if(newNums[left].first + newNums[right].first < target) {
                left++;
            } else {
                right--;
            }
        }
        
        if(newNums[left].first + newNums[right].first) {
            return {newNums[left].second, newNums[right].second};
        }
        
        return {};
    }
};

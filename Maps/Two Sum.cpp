class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        multimap<int,int> mp;
        for(int i=0 ; i<nums.size() ; i++) {
            mp.insert({nums[i], i});
        }
        
        for(int i=0 ; i<nums.size() ; i++) {
            int val = target - nums[i];
            auto itr = mp.find(val);
            if(val == nums[i]) {
                itr++;
                if(itr->first == val) {
                    return {i,itr->second};
                }
            }
            else  {
                if(itr != mp.end()) {
                    return {i, itr->second};
                }
            }
        }
        
        return{};
    }
};



LEETCODE 1


Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


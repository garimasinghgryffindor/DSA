class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> res;
        for(int i=0 ; i<n ; i++){
            res.push_back(nums[i]);
            res.push_back(nums[n+i]);
        }
        
        return res;
    }
};


// LEETCODE 1470
// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

// Return the array in the form [x1,y1,x2,y2,...,xn,yn].


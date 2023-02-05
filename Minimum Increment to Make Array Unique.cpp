// using counting


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int res = 0 , excess = 0;
        vector<int>count(100001 , 0);
        int maxi=INT_MIN, mini=INT_MAX;
        for(auto x: nums) {
            count[x]++;
            mini = min(mini, x);
            maxi = max(maxi, x);
        }
        
        for(int i=mini ; i<=maxi ; i++) {
            res += excess;
            if(count[i] == 0) {
                if(excess > 0) {
                    excess--;
                }
            } else {
                excess += count[i]-1;
            }
        }
        
        res+= excess*(excess+1)/2;
        return res;
    }
};



// LEETCODE 945

// You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

// Return the minimum number of moves to make every value in nums unique.

// The test cases are generated so that the answer fits in a 32-bit integer.


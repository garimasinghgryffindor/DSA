class Solution {
public:
    static int max(int a , int b)
    {
        if(a>=b)
            return a;
        return b;
    }
    
    int jump(vector<int>& nums) {
        int jumpIndex = 0 , maxJump = 0 , jump = 0;
        
        for(int i=0 ; jumpIndex<nums.size()-1 ; i++)
        {
            maxJump = max(maxJump , i+nums[i]);
            if(i==jumpIndex)
            {
                jumpIndex = maxJump;
                jump++;
            }
        }
        
        return jump;
    }
};



// LEETCODE 45

// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


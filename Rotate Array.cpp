class Solution {
public:
    void swap(int&a,int&b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void rotate(vector<int>& nums, int k) {
        //  1. 2. 3. 4. 5. 6. 7
        // after 3 shifts
        //  5. 6. 7. 1. 2. 3. 4
        // solution
        //. so basically-> we are reversing the whole array
        //. 7. 6. 5. 4. 3. 2. 1
        //  we are cutting it into two parts
        // 0->k-1
        //  7  6. 5     &  4  3. 2. 1
        // are we are reversing both of these parts separtely
        
        // first reversal
        k = k%nums.size();
        int n = nums.size();
        for(int i=0 ; i<n/2 ; i++) {
            swap(nums[i], nums[n-i-1]);
        }
        
        // reversal 2.0
        for(int i=0 ; i<k/2 ; i++) {
            swap(nums[i],nums[k-i-1]);
        }
        
        // reversal 3.0
        for(int i=0 ; i<(n-k)/2 ; i++) {
            swap(nums[i+k], nums[n-i-1]);
        }
    }
};

// LEETCODE 189
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// in place algo


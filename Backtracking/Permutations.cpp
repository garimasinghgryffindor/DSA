class Solution {
public:
    
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    void permutation(vector<int>&nums , int l , int r , vector<vector<int> >&res)
    {
        if(l==r)
        {
            res.push_back(nums);
        }
        
        else
        {
            for(int i=l ; i<=r ; i++)
            {
                swap(nums[l] , nums[i]);
                
                permutation(nums, l+1 , r , res);
                
                swap(nums[i] , nums[l]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > res;
        int l = 0 , r = nums.size()-1;
        
        permutation(nums, l ,r ,res);
        
        return res;
    }
};



LEETCODE 46
  
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



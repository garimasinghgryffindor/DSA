// BRUTE FORCE

class Solution {
public:
    void recur(vector<int>nums,set<vector<int>>&res,vector<int>temp,int i) {
        if(i==nums.size()) {
            res.insert(temp);
            return;
        }
        recur(nums,res,temp,i+1);
        temp.push_back(nums[i]);
        recur(nums,res,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res2;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        recur(nums,res2,temp,0);
        
        vector<vector<int>> res(res2.begin(),res2.end());
        
        return res;
        
    }
};


// OPTIMAL

class Solution {
public:
    void recur(vector<int>nums,vector<vector<int>>&res,vector<int>temp,int i) {
        res.push_back(temp);
        
        for(int j=i ; j<nums.size() ; j++) {
            if(j!=i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            recur(nums,res,temp,j+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        recur(nums,res,temp,0);
        
        return res;
        
    }
};

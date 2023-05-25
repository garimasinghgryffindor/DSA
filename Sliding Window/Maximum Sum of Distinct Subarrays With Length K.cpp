class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        long long res = 0, temp = 0;
        int n = nums.size();
        
        if(k > nums.size()) {
            return 0;
        }
        
        int count_ = 0;
        int x=-1;
        int flag = 0;
        
        for(int i=0 ; i<k ; i++) {
            count[nums[i]]++;
            temp += nums[i];
            
            if(count[nums[i]] == 1) {
                count_++;
            } else {
                flag = 1;
            }
            
            if(count_ == k) {
                res = temp;
                x = i-k+2;
                break;
            }
        }
        
        if(x == -1) {
            x = 1;
        }
        
        if(x >= n) return res;
        
        for(int i=x ; i<n-k+1 ; i++) {
            temp-=nums[i-1];
            count[nums[i-1]]--;
            if(count[nums[i-1]] == 0) {
                count_--;
            }
            temp += nums[i+k-1];
            count[nums[i+k-1]]++;
            if(count[nums[i+k-1]] == 1) {
                count_++;
            }
            
            if(count_ == k && temp > res) {
                res = temp;
            }
            
        }
        
        return res;
    }
};




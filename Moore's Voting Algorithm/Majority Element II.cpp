class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // using (Extended Boyer Moore’s Voting Algorithm)
        int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == num1) {
                count1++;
            } else if(nums[i] == num2) {
                count2++;
            } else if(count1 == 0) {
                num1 = nums[i];
                count1 = 1;
            } else if(count2 == 0) {
                num2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        count1=0, count2=0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == num1) {
                count1++;
            } else if(nums[i] == num2) {
                count2++;
            }
        }
        
        vector<int> res;
        if(count1>n/3) {
            res.push_back(num1);
        }
        if(count2>n/3) {
            res.push_back(num2);
        }
        
        return res;
    }
};

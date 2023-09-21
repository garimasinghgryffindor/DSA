class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int flag = 0; // 1 => positive  &  2 => negative
        int res = 0;
        int curr = 0;
        int numberOfnegatives = 0;
        int lastPositivePos = -1;
        int afterZero = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                flag = 0;
                curr = 0;
                numberOfnegatives = 0;
                lastPositivePos = -1;
                afterZero = 0;
            } else if(flag == 0) {
                // previous number was a 0
                if(nums[i] > 0) {
                    // if current number is positive
                    curr = 1;
                    flag = 1;
                    lastPositivePos = i;
                } else {
                    curr = 0;
                    numberOfnegatives = 1;
                    lastPositivePos = i+1;
                    flag = 2;
                }
                afterZero++;
            } else if(flag == 1) {
                // prev number was a positive
                afterZero++;
                if(nums[i] > 0) {
                    // if current number is positive
                    curr++;
                } else {
                    // if neg
                    numberOfnegatives++;
                    if(numberOfnegatives%2 == 0) {
                        // A ok
                        curr = afterZero;
                    } else if(numberOfnegatives == 1) {
                        curr = 0;
                        lastPositivePos = i+1;
                    } else {
                        curr = i - lastPositivePos + 1;
                    }
                    flag = 2;
                }
            } else if(flag == 2) {
                // prev number was a negative
                afterZero++;
                if(nums[i] > 0) {
                    // if current number is positive
                    curr++;
                    flag = 1;
                } else {
                    // if neg
                    numberOfnegatives++;
                    if(numberOfnegatives%2 == 0) {
                        // A ok
                        curr = afterZero;
                    } else if(numberOfnegatives == 1) {
                        curr = 0;
                        lastPositivePos = i+1;
                    } else {
                        curr = i - lastPositivePos + 1;
                    }
                    
                    flag = 2;
                }
            }
            
            res = max(res, curr);
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> res;
        int sum = 0, carry = 0;
        int i = num.size()-1;
        while(k) {
            int n = k%10;
            k/=10;
            if(i>=0)
                sum = n + num[i] + carry; 
            else
                sum = n + carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum);
            i--;
        }
        
        while(i>=0) {
            sum = num[i] + carry;
            carry = sum/10;
            sum = sum%10;
            res.push_back(sum);
            i--;
        }
        
        if(carry > 0)
            res.push_back(carry);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};



LEETCODE 989
 
The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.







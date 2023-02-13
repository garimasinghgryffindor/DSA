
class Solution {
public:
    int countOdds(int low, int high) {
        // 7 and 3 => 4-> 2    3
        // 7 2=> 5-> 2      3
        // 8 4=> 2
        // 8 3 => 2
        int x = (high-low)/2;
        if(low%2==0 && high%2==0)
            return x;
        return x+1;
    }
};



LEETCODE 1523
  
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
  

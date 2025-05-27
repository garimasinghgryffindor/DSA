class Solution {
public:
    int differenceOfSums(int n, int m) {
        int cnt = n/m;
        int num2 = (m*(cnt)*(cnt+1))/2;
        int total_sum = (n*(n+1))/2;
        int num1 = total_sum - num2;
        return num1 - num2;
    }
};

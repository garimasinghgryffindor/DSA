class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int count1 = 0, count2 = 0;
        for(int x : nums1) {sum1 += x; if(x == 0) count1++;}
        for(int x : nums2) {sum2 += x; if(x == 0) count2++;}
        
        if(sum1 == sum2 && count1 == 0 && count2 == 0) return sum1;
        
        if(count1 > 1) {
            sum1 += count1-1;
            count1 = 1;
        }
        
        if(count2 > 1) {
            sum2 += count2-1;
            count2 = 1;
        }
        
        if(sum1 < sum2) {
            if(count1 && count2) {
                sum2++;
                return sum2;
            }
            if(count1) {
                return sum2;
            }
            return -1;
        }
        
        if(sum1 == sum2) {
            if(count1 && count2) {
                return sum1 + max(count1, count2);
            }
            if(count1 || count2) return -1;
        }
        
        if(sum1 > sum2) {
            if(count1 && count2) {
                sum1++;
                return sum1;
            }
            if(count2) {
                return sum1;
            }
        }
        return -1;
    }
};

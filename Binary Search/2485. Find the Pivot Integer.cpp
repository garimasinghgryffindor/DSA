class Solution {
public:
    int pivotInteger(int n) {
        int l = n/2;
        int r = n;
        while(l <= r) {
            int mid = l + (r-l)/2;
            long long sumLeft = mid*(mid+1)/2;
            long long sumRight = n*(n+1)/2 - sumLeft + mid;
            if(sumLeft == sumRight) return mid;
            
            if(sumLeft < sumRight) l = mid+1;
            else r = mid-1;
        }
        
        return -1;
    }
};


class Solution {
public:
    int pivotInteger(int n) {
        double x = sqrt(n*(n+1)/2.0);
        
        if(x != floor(x)) return -1;
        
        return static_cast<int>(x);
    }
};

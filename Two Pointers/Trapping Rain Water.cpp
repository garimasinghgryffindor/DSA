// BRUTE FORCE

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size() , sum=0;
        
        if(n==1)
            return 0;
        
        int left[n] , right[n];
        left[0] = height[0] , right[n-1] = height[n-1];
        for(int i=1 ; i<n ; i++){
            left[i] = max(left[i-1] , height[i]);
        } 
        for(int i=n-2 ; i>=0 ; i--){
            right[i] = max(height[i] , right[i+1]);
        }
        
        for(int i=0 ; i<n ; i++){
            int x = min(left[i] , right[i]);
            sum += x-height[i];
        }
        
        return sum;
    }
};




// OPTIMIZED

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0, rightmax = 0;
        int res = 0;
        int l=0, r=n-1;
        
        while(l<=r) {
            if(height[l] <= height[r]) {
                if(height[l] > leftmax) {
                    leftmax = height[l];
                } else {
                    res += leftmax - height[l];
                }
                l++;
            } else {
                if(height[r] > rightmax) {
                    rightmax = height[r];
                } else {
                    res += rightmax - height[r];
                }
                r--;
            }
        }
        
        return res;
    }
};

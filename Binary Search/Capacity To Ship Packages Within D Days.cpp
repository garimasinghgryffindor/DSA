class Solution {		
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        // create range of (max(weights),sum(weights))
        int l=INT_MIN, r=0;
        for(int i=0;i<weights.size();i++){
            l = max(l,weights[i]);
            r+=weights[i];
        }
        
        // apply binary search in this range to find the least weight capacity
        
        int parts=1, ans=INT_MAX;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            // traverse the weights array to find the least weight sum<=mid
            int i=0,sum=0;
            parts=1;
            while(i<weights.size() and sum<=mid){
                sum+=weights[i++];
                if(sum>mid){
                    i--;
                    parts++;
                    sum=0;
                }
            }
            
            // if parts is greater than days, then we need to increase the weight of the package
            if(parts<=days){
                ans = min(ans,mid);
                r = mid-1;
            }
            else
                l=mid+1;
        }
        
        return ans;
    }
};






LEETCODE 1011

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
 
  

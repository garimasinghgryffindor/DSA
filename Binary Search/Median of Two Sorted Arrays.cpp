class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> nums(nums1.size()+nums2.size());
        
        int i=0,j=0,k=0,m=nums1.size(),n=nums2.size();
        
        while(k<(m+n))
        {
            if(i<m && j<n)
            {
                if(nums1[i]<nums2[j])
                    nums[k++]=nums1[i++];
                else
                    nums[k++]=nums2[j++];
            }
            
            else if(i<m)
            {
                nums[k++]=nums1[i++];
            }
            
            else if(j<n)
            {
                nums[k++]=nums2[j++];
            }
        }
        
        if(nums.size()%2==1)
            return nums[nums.size()/2];
        else
            return (nums[nums.size()/2]+nums[nums.size()/2-1])/2.0;
    }
};


// space optimised
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2,nums1);
        
        int low = 0, high = m;
        int median = ((m+n)+1)/2;
        
        while(low <= high) {
            int cut1 = (low+high)>>1;
            int cut2 = median - cut1;
            
            int l1 = cut1==0? INT_MIN: nums1[cut1-1];
            int l2 = cut2==0? INT_MIN: nums2[cut2-1];
            int r1 = cut1==m? INT_MAX: nums1[cut1];
            int r2 = cut2==n? INT_MAX: nums2[cut2];
            
            if(l1<=r2 && l2<=r1) {
                // A ok
                // valid
                if((m+n)%2!=0) {
                    return max(l1,l2);
                } else {
                    return (max(l1,l2) + min(r1,r2))/2.0;
                }
            } else if(l1 > r2) {
                high = cut1-1;
            } else {
                low = cut1+1;
            }
        }
        return -1;
    }
};

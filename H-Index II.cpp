class Solution {
public:
    
    int hIndex(vector<int>& vec) {
        int n = vec.size();
        int l = 0, r = n-1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(vec[mid] >= n-mid) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return n - l;
    }
};


// LEETCODE 275

// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper and citations is sorted in an ascending order, return compute the researcher's h-index.

// According to the definition of h-index on Wikipedia: A scientist has an index h if h of their n papers have at least h citations each, and the other n − h papers have no more than h citations each.

// If there are several possible values for h, the maximum one is taken as the h-index.

// You must write an algorithm that runs in logarithmic time.



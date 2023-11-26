You are given a 0-indexed array of positive integers nums and a positive integer limit.

In one operation, you can choose any two indices i and j and swap nums[i] and nums[j] if |nums[i] - nums[j]| <= limit.

Return the lexicographically smallest array that can be obtained by performing the operation any number of times.

An array a is lexicographically smaller than an array b if in the first position where a and b differ, array a has an element 
that is less than the corresponding element in b. For example, the array [2,10,3] is lexicographically smaller than the array [10,2,3] 
because they differ at index 0 and 2 < 10.



class Solution {
public:
    void flush(vector<pair<int,int>>&vec, vector<int>&res, int l, int r) {
        vector<int>indices;
        for(int i = l; i <= r; i++) {
            indices.push_back(vec[i].second);
        }
        
        sort(indices.begin(), indices.end());
        // these consecutive elements can be swapped , but to their respective group-indices / segment indices only
        for eg: [1,10,5,3,9,8,1] 2
        ANS: [1,8,1,3,9,10,5]
        // last 1 since can be swapped because has elements like (1+1, 1+2) = (2, 3) and 3 exists
        // but is not swapped straight away next to 0'th index 1 because for next element-8 there is not able-to-be-swapped element
        // and therefore the element is swapped in the consecutive-able group (You know what I mean!)
      
        for(int i = 0; i <indices.size(); i++) {
            res[indices[i]] = vec[l+i].first;
        }
    }
    
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // firstly we will store all these elements in a new vector of pair
        int n = nums.size();
        vector<pair<int,int>> vec;
        for(int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        
        // sort all the elements
        sort(vec.begin(), vec.end());
        
        // now we can easily check consecutive elements in this new vector
        
        vector<int>res(n);
        int l = 0;
        int p = vec[0].first;
        for(int r = 0; r < n; r++) {
            if(vec[r].first - p <= limit) {
                // A Ok
                
            } else {
                flush(vec, res, l, r-1);
                l = r;
            }
            p = vec[r].first;
        }
        flush(vec, res, l, n-1);
        
        return res;
    }
};

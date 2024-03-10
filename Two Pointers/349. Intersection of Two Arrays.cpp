// approach 1
// using hash
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(), nums1.end());
        unordered_set<int>st2(nums2.begin(), nums2.end());
        
        vector<int>res;
        for(auto x: st1) {
            if(st2.find(x) != st2.end()) {
                res.push_back(x);
            }
        }
        
        return res;
    }
};

// approach 2
// using two-pointers
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>res;
        
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                while(i < n-1 && nums1[i] == nums1[i+1]) {
                    i++;
                }
                while(j < m-1 && nums2[j] == nums2[j+1]) {
                    j++;
                }
                i++;
                j++;
            } else if(nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        
        }
        
        return res;
    }
};


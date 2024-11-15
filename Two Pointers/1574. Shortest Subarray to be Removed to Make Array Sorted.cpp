class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        int res = 0;
        
        while(l < n-1 && arr[l] <= arr[l+1]) { l++; }
        if(l == n-1) return 0;
        
        while(r > 0 && arr[r] >= arr[r-1]) { r--; }
        
        res = min(r, n-l-1);
        
        int i = 0, j = r;
        
        while(i <= l && j < n) {
            if(arr[i] <= arr[j]) {
                res = min(res, j-i-1);
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};

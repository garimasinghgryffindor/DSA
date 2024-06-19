class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) return -1;
        int mn = INT_MAX, mx = 0;
        for(int x: bloomDay) {
            mn = min(x, mn);
            mx = max(x, mx);
        }
        
        int l = mn, r = mx;
        while(l < r) {
            int mid = l + (r-l)/2;
            // find the number of bouquets
            int count = 0, tot = 0;
            for(int x: bloomDay) {
                if(x <= mid) {
                    count++;
                } else {
                    count = 0;
                }
                if(count == k) {
                    count = 0;  tot++;
                }
            }
            
            if(tot >= m) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        
        return l;
    }
};

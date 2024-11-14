class Solution {
public:
    bool isValid(int n, int mid, vector<int>&quantities) {
        
        int i = 0;
        if(mid == 0) return false;
        
        while(i < quantities.size()) {
            if(quantities[i] <= mid) {
                n--;
                i++;
                
                if(n < 0) return false;
                if(n == 0 && i != quantities.size()) return false;
                
            } else {
                int cnt = 0;
                if(quantities[i]%mid == 0) {
                    cnt = quantities[i]/mid;
                } else {
                    cnt = quantities[i]/mid+1;
                }
                n -= cnt;
                i++;
                if(n < 0) return false;
                if(n == 0 && i == quantities.size()) return true;
                if(n == 0 && i != quantities.size()) return false;
            }
            
        }
        
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int mx = quantities[quantities.size()-1];
        int l = 0, r = mx;
        int res = mx;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(isValid(n, mid, quantities)) {
                res = min(res, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    bool possible(vector<int>candies, int quan, long long k) {
        int idx = 0;
        
        while(idx < candies.size()) {
            if(candies[idx] >= quan) {
                k-=candies[idx]/quan;
            }
            idx++;

            if(k <= 0) return true;
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int res = 0, n = candies.size();
        sort(candies.begin(), candies.end());
        int l = 1, r = candies[n-1];

        while(l <= r) {
            int mid = l + (r-l)/2;
            // cout<<"mid:  "<<mid<<"    l: "<<l<<"     r: "<<r<<endl;
            if(possible(candies, mid, k)) {
                res = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }

            // cout<<"mid:  "<<mid<<"    l: "<<l<<"     r: "<<r<<endl;
        }

        return res;
    }
};

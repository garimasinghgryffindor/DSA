class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0, n = colors.size();
        int l = 0, r = n-1;
        
        if(colors[0] == 1 - colors[n-1]) {
            // then only try cyclic
            for(;l < n; l++) {
                if(l != 0) {
                    if(colors[l] == 1 - colors[l-1]){

                    } else {
                        break;
                    }
                }
            }

            if(l == n) {
                return n;
            }

            for(;r >= 0; r--) {
                if(r != n-1) {
                    if(colors[r] == 1 - colors[r+1]) {

                    } else {
                        break;
                    }
                }
            }

            int len = l + n - 1 - r;
            if(len >= k)
            res += len - k + 1;
        }

        int len = 1;
        for(int i = l; i <= r; i++) {
            if(i == l) {

            } else {
                if(colors[i] == 1 - colors[i-1]) {
                    len++;
                } else {
                    if(len >= k) {
                        res += len - k + 1;
                    }
                    len = 1;
                }
            }
        }

        if(len >= k) {
            res += len - k + 1;
        }

        return res;
    }
};

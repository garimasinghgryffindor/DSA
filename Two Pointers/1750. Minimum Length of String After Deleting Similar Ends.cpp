class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.length()-1;
        int n = s.length();
        while(l < r) {
            if(s[l] == s[r]) {
                int i=l, j=r;
                while(l+1 < j && s[l] == s[l+1]) {
                    l++;
                }
                l++;
                while(r-1 > i && s[r] == s[r-1]) {
                    r--;
                }
                r--;
                if(l == r) return 1;
                if(l > r) return 0;
                
            } else break;
        }
        
        return r-l+1;
    }
};

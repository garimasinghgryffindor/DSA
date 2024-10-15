class Solution {
public:
    long long minimumSteps(string s) {
        int l = 0, curr = 0;
        long long res = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                // white ball
                // swap with the left position
                if(s[l] == '0') {
                    l++;
                } else {
                    res += (long long)(i-l);
                    swap(s[l], s[i]);
                    l++;
                }
            }
        }
        return res;
    }
};

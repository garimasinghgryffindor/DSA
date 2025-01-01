class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>left(n, 0), right(n, 0);
        left[0] = 1-(s[0]-'0');
        right[n-1] = s[n-1]-'0';
        for(int i = 1; i < n; i++) {
            left[i] += left[i-1] + 1 - (s[i]-'0');
            right[n-i-1] += right[n-i] + (s[n-i-1]-'0'); 
        }

        int res = 0;

        for(int i = 0; i < n-1; i++) {
            res = max(res, left[i]+right[i+1]);
        }

        return res;
    }
};

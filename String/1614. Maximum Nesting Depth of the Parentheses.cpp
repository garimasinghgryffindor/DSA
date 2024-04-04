class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int count = 0;
        for(auto x: s) {
            if(x == '(') {
                count++;
                res = max(count, res);
            } else if(x == ')') {
                count--;
            }
        }
        return res;
    }
};

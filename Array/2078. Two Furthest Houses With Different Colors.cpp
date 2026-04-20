class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        int r = colors.size()-1;
        while(r > 0 && colors[0] == colors[r]) {
            r--;
        }
        res = max(res, r-0);
        int l = 0;
        while(l < colors.size()-1 && colors[l] == colors[colors.size()-1]) {
            l++;
        }

        res = max(res, (int)colors.size()-1-l);

        return res;
    }
};

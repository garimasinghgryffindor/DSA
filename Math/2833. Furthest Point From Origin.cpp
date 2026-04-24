class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        int n = moves.length();
        for(auto x: moves) {
            if(x == 'L') l++;
            else if (x == 'R') r++;
        }

        return n - l - r + abs(l - r);
    }
};

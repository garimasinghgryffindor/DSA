class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool last = true;
        int x = n;
        while(x) {
            if(x == n) {
                last = x%2;
            } else {
                if(last == x%2) return false;
                last = x%2;
            }
            x >>= 1;
        }

        return true;
    }
};

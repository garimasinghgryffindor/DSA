class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        int n = s.length();
        int carry = 0;
        
        
        int l = n-1;
        while(l > 0) {
            if (s[l] - '0' + carry == 0) {
                carry = 0;
                count++;
            } else if (s[l] - '0' + carry == 2) {
                carry = 1;
                count++;
            } else {
                carry = 1;
                count += 2;
            }
            l--;
        }
        
        if (carry == 1) {
            count++;
        }
        
        return count;
    }
};

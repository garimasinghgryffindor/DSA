class Solution {
public:
    int minOperations(string s) {
        // there can only be two possible combinations 
        // one starting with 1
        // other starting with 2
        int x = 1;
        // starting with 0
        int one = 0, zero = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]-'0' == 1-x) {
                // all good;
            } else {
                one++;
            }
            x = 1-x;
        }
        // starting with 1
        x = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]-'0' == 1-x) {
                // all good;
            } else {
                zero++;
            }
            x = 1-x;
        }

        return min(one, zero);
    }
};

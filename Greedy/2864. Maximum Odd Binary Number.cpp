class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for(auto x: s) {
            if(x == '1') count++;
        }
        
        string res = string(count-1, '1') + string(s.length()-count, '0') + "1";
        return res;
    }
};

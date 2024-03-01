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


class Solution {
public:
    string maximumOddBinaryNumber(string s) {        
        int mid = 0;
        int l = 0;
        
        while(mid < s.length()) {
            if(s[mid] == '1') {
                swap(s[mid], s[l]);
                l++;
                mid++;
            } else {
                mid++;
            }
        }
        
        swap(s[l-1], s[s.length()-1]);
        
        return s;
    }
};

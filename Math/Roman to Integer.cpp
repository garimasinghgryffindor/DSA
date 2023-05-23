class Solution {
public:
    int romanToIntUtils(char a) {
        if(a == 'I') return 1;
        if(a == 'V') return 5;
        if(a == 'X') return 10;
        if(a == 'L') return 50;
        if(a == 'C') return 100;
        if(a == 'D') return 500;
        if(a == 'M') return 1000;
        return -1;
    }
    int romanToInt(string s) {
        int x=0;
        int len=s.length();
        for(int i=0 ; i<len ; i++)
        {
            int x1 = romanToIntUtils(s[i]);
            if(i < len-1) {
                int x2 = romanToIntUtils(s[i+1]);
                
                if(x1 < x2) {
                    // reduce
                    x -= x1;
                } else {
                    // add
                    x += x1;
                }
            } else {
                x += romanToIntUtils(s[i]);
            }
        }
        
        return x;
    }
};

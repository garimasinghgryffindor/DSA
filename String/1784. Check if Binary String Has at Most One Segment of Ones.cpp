// class Solution {
// public:
//     bool checkOnesSegment(string s) {
//         for(int i = 1; i < s.length()-1; i++) {
//             if(s[i] == '0' && s[i+1] == '1') return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool checkOnesSegment(string s) {
        int sum1 = 0, sum2 = 0;
        s = s + "0";
        
        for(int i = 0; i < s.length(); i++) {
            if(!sum2 && s[i] == '0') {
                sum2 = sum1;
            }
            sum1 += s[i]-'0';
        }
        return sum2 == sum1;
    }
};

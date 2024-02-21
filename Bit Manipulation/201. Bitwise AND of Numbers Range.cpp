// // BRUTE FORCE
// class Solution {
// public:
//     int rangeBitwiseAnd(int left, int right) {
//         int res = left;
//         for(int i = left+1; i <= right; i++) {
//             res = res & i;
//         }
        
//         return res;
//     }
// };


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right) {
            // will count the bits which are fluctuating
            count++;
            left >>= 1;
            right >>= 1;
        }
        
        // left will store the actual part of ans in which bits are NOT fluctuating
        // ans = left << count
        int res = left << count;
        return res;
    }
};

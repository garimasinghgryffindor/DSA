class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // num = 2, sum = 3
        // example two digit number -- brute force --10 to 99.
        // loop thr all the combinations and check for the condition 
        // return the max one
        // 2 digit 10^2 to 103-1
        // 10^2M to 10^2M+1 -1

        string str(num, '0');
        int x = sum;
        for(int i = 0; i < num; i++) {
            if(x >= 9) {
                str[i] = '9';
                x -= 9;
            } else {
                str[i] = '0'+x;
                x = 0;
                break;
            }
        }

        if(x != 0) return "";

        return str;
    }
};

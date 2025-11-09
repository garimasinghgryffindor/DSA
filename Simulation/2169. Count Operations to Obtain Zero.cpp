class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 != 0 && num2!= 0) {
            if(num1 >= num2) {
                count += num1/num2;
                num1 = num1%num2;
            } else {
                num1 = num1 - num2; // difference of these numbers (a - b)
                num2 = num1 + num2; // actual value of num1 (a)
                num1 = num2 - num1; // (b) 
            }
        }

        return count;
    }
};

// one way -
// (number of operations required to make both numbers equal) + 1
// if one number is the factor of the other- > (12, 3) -- 12 - 4*3 direct solution
// if not -> (12, 5) -- 12 - 5*2 = 2, 5 again not factors -> 5 - 2*2 = 1, 2 -> now factors 

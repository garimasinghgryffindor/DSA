class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        if(n == 1) return true;
        int count = 0;
        while(n) {
            int x = n % 2; // checking the 0th bit
            n >>= 1; // right shifted by 1
            // cout<<x<<"  x:n  "<<n<<endl;

            if(x == 1) return false; 
            x = n % 2; // checking the 1th bit
            n >>= 1;
            if(x == 1) return false;
            // cout<<x<<"  x:n  "<<n<<endl;
            x = n % 2; // checking the 2nd bit
            if(x == 1) {
                // cout<<x<<"  x:n  "<<n<<endl;
                n >>= 1;
                if(n > 0) return false;
                n <<= 1;
            } else {
                // cout<<x<<"  x:n  "<<n<<endl;
                // A ok
            }
            // cout<<"-------------------------\n";
        }
        return true;
    }
};

// 4^1 = 4
// 4^2 = 16
// 4^3 = 64
// 4^5 = 256
// 4^6 = 1024
// 4^7 = 4096

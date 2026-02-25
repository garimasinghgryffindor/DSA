class Solution {
public:
    static int numberofbits(int n) {
        int sum = 0;
        while(n) {
            sum += n & 1;
            n >>= 1;
        }
        return sum;
    }

    static bool compare(int a, int b) {
        int bits_a = numberofbits(a);
        int bits_b = numberofbits(b);

        if(bits_a < bits_b) return true;
        if(bits_a > bits_b) return false;
        return a < b;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);

        return arr;
    }
};

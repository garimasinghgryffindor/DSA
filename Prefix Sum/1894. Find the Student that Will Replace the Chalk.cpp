class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int sum = 0;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            int x = chalk[i];
            sum += x;
            if(sum > k) {
                return i;
            }
        }
        int rem = k%sum;
        sum = 0;
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
            if(sum > rem) {
                return i;
            }
        }
        return 0;
    }
};

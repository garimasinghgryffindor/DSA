class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(auto x: operations) {
            if(x[1] == '+') res++;
            else res--;
        }

        return res;
    }
};

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(auto x: details) {
            int curr = (x[11]-'0')*10 + x[12]-'0';
            if(curr > 60) res++;
        }
        return res;
    }
};

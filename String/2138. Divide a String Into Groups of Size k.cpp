class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>res;
        int n = s.length();
        for(int i = 0; i < n/k; i++) {
            string temp = s.substr(i*k, k);
            res.push_back(temp);
        }

        if(n%k != 0) {
            string temp = s.substr(n-n%k, n%k);
            for(int i = n%k; i < k; i++) {
                temp.push_back(fill);
            }
            res.push_back(temp);
        }

        return res;
    }
};

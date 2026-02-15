class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int l = max(a.length(), b.length());
        int car = 0;
        for(int i = 0; i < l; i++) {
            int sm = car;
            if(a.length() > i) {
                sm += a[i]-'0';
            }
            if(b.length() > i) {
                sm += b[i]-'0';
            }
            car = (sm)/2;
            sm = sm%2;
            res.push_back(sm + '0');
        }

        if(car) {
            res.push_back(car + '0');
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

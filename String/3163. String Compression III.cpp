// NOTE 
// USE .push_back() instead of + to append characters to the string to avoid memory overflow

class Solution {
public:
    string compressedString(string s) {
        string res = "";
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0 || s[i] == s[i-1]) {
                if(count < 9) {
                    count++;
                } else {
                    res.push_back('9');
                    res.push_back(s[i-1]);
                    count = 1;
                }
            } else {
                res.push_back('0'+count);
                res.push_back(s[i-1]);
                count = 1;
            }
        }
        res.push_back('0'+count);
        res.push_back(s.back());
        
        return res;
    }
};

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>res;

        for(auto s: queries) {
            for(auto s2: dictionary) {
                int n = s.length();
                int ch = 0;
                for(int i = 0; i < n; i++) {
                    if(s[i] != s2[i]) ch++;
                }
                if (ch <= 2) {
                    res.push_back(s);
                    break;
                }
            }
        }

        return res;
    }
};

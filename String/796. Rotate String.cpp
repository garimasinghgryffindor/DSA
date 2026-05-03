class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i = 0; i < s.length(); i++) {
            string a = s.substr(0, i+1);
            string b = s.substr(i+1);
            if(b+a == goal) return true;
        }
        return false;
    }
};

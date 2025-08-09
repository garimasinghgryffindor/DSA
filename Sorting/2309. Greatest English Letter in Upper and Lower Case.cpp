class Solution {
public:
    string greatestLetter(string s) {
        sort(s.rbegin(), s.rend());
        set<char> st;
        int last_lower = 0;
        for(auto x: s) {
            if(x >= 'a' && x <= 'z') {
                st.insert(x);
                last_lower++;
            } else break;
        }

        for(int i = last_lower; i < s.length(); i++) {
            auto x = s[i];
            if(x >= 'A' && x <= 'Z') {
                if(st.find(x + 32) != st.end()) {
                    return {x};
                }
            }
        }

        return "";
    }
};

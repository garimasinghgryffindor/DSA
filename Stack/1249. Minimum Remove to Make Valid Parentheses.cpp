class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string res = "";
        int n = s.length();
        vector<bool>vec(n, false);
        
        stack<pair<char,int> > st;
        
        for(int i = 0; i < n; i++) {
            char x = s[i];
            if(x == '(') {
                vec[i] = true;
                st.push({x, i});
            } else if(x == ')') {
                if (!st.empty() && st.top().first == '(') {
                    st.pop();
                    vec[i] = true;
                }
            } else {
                vec[i] = true;
            }
        }
        
        while(!st.empty()) {
            int x = st.top().second;
            vec[x] = false;
            st.pop();
        }
        
        for(int i = 0; i < n; i++) {
            if(vec[i]) {
                res += s[i];
            }
        }
        
        return res;
    }
};

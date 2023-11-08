// BRUTE FORCE
// O(N^2)
class Solution {
public:
    // 1 approach->
    // trying all lengths
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = i; j < n; j++) {
                if(s[j] == '(') {
                    x++;
                } else {
                    x--;
                    if(x == 0) {
                        res = max(res, j-i+1);
                    } else if(x < 0) {
                        break;
                    }
                }
            }
        }
        return res;
    }
};


// Optimal
// O(N)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int res = 0;
        stack<int>st;
        st.push(-1);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    // invalid scenario
                    st.push(i); // new invalid position/index = i
                } else {
                    int len = i - st.top(); // st.top() => would be the last invalid index
                    res = max(len, res);
                }
            }
        }
        
        return res;
    }
};

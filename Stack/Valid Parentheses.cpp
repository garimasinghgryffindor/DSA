class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x: s) {
            if(x == '(' || x == '[' || x == '{') {
                st.push(x);
            } else {
                if(st.empty())
                    return false;
                
                auto y = st.top();
                st.pop();
                if((y == '(' && x == ')') || (y=='[' && x==']') || (y=='{' && x=='}'));
                else return false;
            }
        }
        
        if(!st.empty())
            return false;
        
        return true;
    }
};



LEETCODE 20
  
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.



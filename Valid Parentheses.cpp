
bool ispar(string x)
    {
        stack<char>st;
        for(auto ch: x) {
            if(ch=='(' || ch=='[' || ch=='{') {
                st.push(ch);
            }
            else if(ch==')') {
                if(st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
            else if(ch==']') {
                if(st.empty() || st.top() != '[')
                    return false;
                st.pop();
            }
            else if(ch=='}'){
                if(st.empty() || st.top() != '{')
                    return false;
                st.pop();
            } else {
                return false;
            }
        }
        if(!st.empty())
            return false;
        
        return true;
    }



LEETCODE 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        stack<int>st;
        for(int x: asteroids) {
            if(x > 0) {
                // A ok
                st.push(x);
            } else {
                // means it is going towards the LHS
                bool flag = true;
                while(!st.empty()) {
                    if(st.top() > 0) {
                        // means it was going towards the RHS
                        // it could collide with the current asteroid
                        if(st.top() > abs(x)) {
                            flag = false;
                            break;
                        } else if(st.top() == abs(x)) {
                            // they both destroyed each other
                            // pop
                            st.pop();
                            flag = false;
                            break;
                        } else {
                            // final current asteroid which is going towards the left
                            st.pop();
                        }
                    } else {
                        // do nothing
                        break;
                    }
                }
                if(flag) {
                    st.push(x);
                }
            }
        }
        
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() { }
    
    void push(int val) {
        if(st.empty()){
            st.push_back({val,val});
        } else {
            st.push_back({val , min(val , st.back().second)});
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        st.pop_back();
    }
    
    int top() {
        if(st.empty())
            return NULL;
        return (st.back()).first;
    }
    
    int getMin() {
        if(st.empty())
            return NULL;
        return (st.back()).second;
    }
};




class MinStack {
public:
    stack<long>st;
    long minm = INT_MAX;
    
    MinStack() { }
    
    void push(int val) {
        if(st.empty()) {
            minm = val;
            st.push(val);
            return;
        }
        
        if(val <= minm) {
            int prevMin = minm;
            minm = val;
            st.push(2ll*minm - prevMin);
        } else {
            st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) {
            return;
        }
        
        if(st.top() <= minm) {
            // minm changed here
            minm = 2*minm - st.top();
            st.pop();
        } else {
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()) {
            return -1;
        }
        
        if(st.top() <= minm) {
            // minm changed here
            return minm;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        if(st.empty()) {
            return -1;
        }
        
        return minm;
    }
};






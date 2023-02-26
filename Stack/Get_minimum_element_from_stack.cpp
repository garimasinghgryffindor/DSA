#include <iostream>
#include <stack>
using namespace std;

class stack2{
    public:
    stack<int> st;
    int minEle;

    void getMin() {
        if(st.empty()) {
            cout<<"stack is empty\n";
            return;
        }
        cout<<"minimum element in the stack is:   "<<minEle<<endl;
    }

    void push(int x) {
        if(st.empty()) {
            minEle = x;
            st.push(x);
            return;
        }
        if(x < minEle) {
            st.push(2*x - minEle);
            minEle = x;
        } else {
            st.push(x);
        }

        return;
    }

    void pop() {
        if(st.empty()) {
            cout<<"stack is empty!\n";
            return;
        }

        int t = st.top();
        st.pop();
        if(t < minEle) {
            cout<<minEle<<endl;
            minEle = 2*minEle - t;
            return;
        }
        cout<<t<<endl;
    }

    void peek() {
        if(st.empty()) {
            cout<<"stack is empty!\n";
            return;
        }

        int t = st.top();
        if(t < minEle) {
            cout<<minEle<<endl;
            return;
        }
        cout<<t<<endl;
    }
};

int main()
{
    stack2 stk;

    stk.push(3);
	stk.push(5);
	stk.getMin();
	stk.push(2);
	stk.push(1);
	stk.getMin();
	stk.pop();
	stk.getMin();
	stk.pop();
	stk.peek();

    return 0;
}
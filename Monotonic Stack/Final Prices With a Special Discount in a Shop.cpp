class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        // essentially our monotonic stack this is
        // pair -> int(val), int(index)
        
        int n = prices.size();
        vector<int> res(n);
        
        for(int i=0 ; i<n ; i++) {
            res[i] = prices[i];
            
            while(!st.empty() && prices[st.top()] >= prices[i]) {
                int idx = st.top();
                int discount = prices[i];
                int valAfterDiscount = prices[idx] - discount;
                res[idx] = valAfterDiscount;
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};

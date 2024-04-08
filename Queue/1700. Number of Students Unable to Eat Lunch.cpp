class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int res = 0;
        int n = students.size();
        stack<int> st;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(students[i]);
            st.push(sandwiches[n-i-1]);
        }
        
        // int sz = q.size();
        while(!q.empty()) {
            int qsz = q.size();
            
            for(int i = 0; i < qsz; i++) {
                if(q.front() == st.top()) {
                    q.pop();    st.pop();
                } else {
                    int frt = q.front();    q.pop();
                    q.push(frt);
                }
            }
            
            if(q.size() == qsz) return q.size();
        }
        
        return 0;
    }
};

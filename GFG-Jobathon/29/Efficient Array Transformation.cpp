Efficient Array Transformation
Accuracy: 5.01%
Submissions: 298+
永
Points: 40
Geek is a software developer working on an algorithm that processes an integer array arrl] of length n. The values in arr represent data points, and each data point falls within the range of 0 to M-1. Geek's task is to modify the array arr in the minimum number of operations to ensure that the data points are in non-decreasing order.
In one operation, Geek can increase the value of a data point arr[i] by 1, taking the modulo M of the result. So the goal is to find the minimum number of operations required to make the array arr non-decreasing.

// Recursive
// and not better
// you will get it
class Solution {
  public:
    void recur(int&n, int&m, vector<int>arr, int&res, int op, int idx) {
        if(idx == n) {
            res = min(res, op);
            return;
        }
        
        if(idx == 0) {
            // either leave it as it is
            recur(n, m, arr, res, op, idx+1);
            
            // or reduce it to 0
            op = m - arr[idx];
            arr[idx] = 0;
            recur(n, m, arr, res, op, idx+1);
        } else {
            int prev = arr[idx-1];
            
            if(prev > arr[idx]) {
                op += prev - arr[idx];
                arr[idx] = prev;
                recur(n, m, arr, res, op, idx+1);
            } 
            
            else if(prev == arr[idx]){
                recur(n, m, arr, res, op, idx+1);
            } 
            
            else {
                // either use as it 
                recur(n, m, arr, res, op, idx+1);
                // or
                op += (m - arr[idx]) + prev;
                arr[idx] = prev;
                recur(n, m, arr, res, op, idx+1);
            }
        }
    }
    
    int minOperations(int n, int m, vector<int> &arr) {
        //Write Code Here
        int res = INT_MAX;
        int operations = 0;
        recur(n, m, arr, res, operations, 0);
        
        return res;
    }
    
};

// see i was only required to keep track of prev and current elements
// there is not need to check the fluctuations in the entire array
// therefore only send the prev element and curr index

// like this
// memoization

class Solution {
  public:
    int recur(int&n, int&m, vector<int>&arr, int idx, int prev, vector<vector<int>>& dp) {
        if(idx == n) {
            // res = min(res, op);x
            return 0;
        }
        
        // cout<<"prev :  "<<prev<<"    idx :  "<<idx<<endl;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        if(idx == 0) {
            // either leave it as it is
            int temp1 = recur(n, m, arr, idx+1, arr[idx], dp);
            
            // or reduce it to 0
            int op = m - arr[idx];
            int temp2 = recur(n, m, arr, idx+1, 0, dp);
            // cout<<"res now  : "<<min(temp1, op + temp2)<<endl;
            return (dp[idx][prev+1] = min(temp1, op + temp2));
        } else {
            // int prev = arr[idx-1];
            
            if(prev > arr[idx]) {
                int op = prev - arr[idx];
                // arr[idx] = prev;
                int newprev = prev;
                // cout<<"res now  : "<<op + recur(n, m, arr, idx+1, newprev, dp)<<endl;
                return (dp[idx][prev+1] = op + recur(n, m, arr, idx+1, newprev, dp));
            } 
            
            else if(prev == arr[idx]){
                // cout<<"res now. :  "<<recur(n, m, arr, idx+1, arr[idx], dp)<<endl;
                return (dp[idx][prev+1] = recur(n, m, arr, idx+1, arr[idx], dp));
            } 
            
            else {
                // either use as it 
                int temp1 = recur(n, m, arr, idx+1, arr[idx], dp);
                // or
                int op = (m - arr[idx]) + prev;
                int newprev = prev;
                int temp2 = recur(n, m, arr, idx+1, newprev , dp);
                // cout<<"res now  :   "<< min(temp1, op + temp2)<<endl;
                return (dp[idx][prev+1] = min(temp1, op + temp2));
            }
        }
        
        // return -1;
    }
    
    int minOperations(int n, int m, vector<int> &arr) {
        //Write Code Here
        vector<vector<int> > dp(n, vector<int>(m+1, -1));
        return recur(n, m, arr, 0, -1, dp);
    }
    
};

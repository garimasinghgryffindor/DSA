// // MLE
// class Solution {
// public:
//     long long minOperations(vector<vector<int>>& queries) {
//         long long res = 0;
//         int n = queries.size();
//         int len = 0;
//         for(int i = 0; i < n; i++) {
//             len = max(len, queries[i][1]);
//         }

//         vector<long long>prefixSum(len+1);
//         for(int i = 1; i < len+1; i++) {
//             int steps = floor(log(i)/log(4)) + 1;
//             prefixSum[i] = steps;
//             prefixSum[i] += (long long)prefixSum[i-1];
//         }

//         for(int i = 0; i < n; i++) {
//             int l = queries[i][0];
//             int r = queries[i][1];
//             long long curr = prefixSum[r] - prefixSum[l-1];
//             curr = ceil((double)curr/2);
//             res += curr;
//         }

        
//         return res;
//     }   
// };



// Optimised
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        int n = queries.size();
        int len = 0;
        // for(int i = 0; i < n; i++) {
        //     len = max(len, queries[i][1]);
        // }

        // vector<long long>prefixSum(len+1);
        // for(int i = 1; i < len+1; i++) {
        //     int steps = floor(log(i)/log(4)) + 1;
        //     prefixSum[i] = steps;
        //     prefixSum[i] += (long long)prefixSum[i-1];
        // }

        for(int i = 0; i < n; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            // long long curr = 0;
            long long no_steps_first = floor(log(l)/log(4)) + 1;
            long long no_steps_last = floor(log(r)/log(4)) + 1;
            long long steps = 0;
            
            // cout<<no_steps_first<<"   :   "<<no_steps_last<<endl;
            
            for(long long i = no_steps_first; i <= no_steps_last; i++) {
                long long nxt = pow(4, i);
                // cout<<nxt<<"  <-next   ";
                if(nxt <= r) {
                    steps += (nxt - l)*i;
                    l = nxt;
                } else {
                    steps += (r+1 - l)*i;
                }
                // cout<<steps<<"  <-steps   ";
            }
            
            steps = ceil((double)steps/2);
            res += steps;
        }

        
        return res;
    }   
};

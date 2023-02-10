
class Solution {
public:
    
    //  USING LONGEST INCREASING SUBSEQUENCE
    
    static bool compare(vector<int>&a,vector<int>&b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        
        int n = envelopes.size();
        vector<int> dp;
        
        for(int i=0 ; i<n ; i++) {
            int idx = lower_bound(dp.begin(), dp.end() , envelopes[i][1]) - dp.begin();
            if(idx >= dp.size()) {
                dp.push_back(envelopes[i][1]);
            } else {
                dp[idx] = envelopes[i][1];
            }
            
        }
        
        return dp.size();
    }
};

// LEETCODE 354

// You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

// One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

// Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

// Note: You cannot rotate an envelope.

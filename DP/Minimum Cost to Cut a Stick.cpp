// MY FIRST APPROACH
class Solution {
public:
    // USING RECURSION
    int recur(vector<int>cuts, int l, int r) {
        if(l == r-1 || l == r) return 0; // because you cannot perform any cut here
        if(l < 0 || r < 0) return 0;
        
        int cost = INT_MAX;
        int flag = 0;
        for(int i = 0; i < cuts.size(); i++) {
            if(cuts[i] > l && cuts[i] < r) {
                // then only you can perform a cut
                int costHere = r-l + recur(cuts, l, cuts[i]) + recur(cuts, cuts[i], r);
                cost = min(cost, costHere);
                flag = 1;
            }
        }
        
        if(flag == 0) return 0;
        
        return cost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        return recur(cuts, 0, n);
    }
};  // WRONG



class Solution {
public:   
    // USING MEMOIZATION
    int dp[101][101];
    vector<int>cuts;
    int recur(int l, int r, int lCut, int rCut) {
        if(lCut > rCut) return 0;
        
        if(dp[lCut][rCut] != -1) return dp[lCut][rCut];
        
        int cost = INT_MAX;
        for(int i = lCut; i <= rCut; i++) {
            int costHere = r-l + recur(l, cuts[i], lCut, i-1) + recur(cuts[i], r, i+1, rCut);
            cost = min(cost, costHere);
        }
        
        return dp[lCut][rCut] = cost;
    }
    
    int minCost(int n, vector<int>& cut) {
        memset(dp, -1, sizeof(dp));
        for(int i=0 ; i<cut.size() ; i++) cuts.push_back(cut[i]);
        sort(cuts.begin(), cuts.end());
        return recur(0, n, 0, cuts.size() - 1);
    }
};


class Solution {
public:   
    // USING TABULATION
    int dp[102][102];
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp, 0, sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        for(int left=cuts.size()-1 ; left >=0 ; left--) {
            for(int right=left+1 ; right < cuts.size() ; right++) {
                for(int i = left+1; i < right; i++) {
                    int costHere = cuts[right]-cuts[left] + dp[left][i] + dp[i][right];
                    dp[left][right] = min(dp[left][right]==0?INT_MAX:dp[left][right], costHere);
                }
            }
        }
        
        return dp[0][cuts.size() - 1];
    }
};

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
};

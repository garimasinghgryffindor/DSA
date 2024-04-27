// RECURSION
class Solution {
public:
    int n;
    int recur(unordered_map<char, vector<int>>&positions, string key, int idx, int prev) {
        if(idx == key.length()) return 0;
        
        int res = INT_MAX;
        int curr = 0;
        for(int x: positions[key[idx]]) {
            int moves = abs(x-prev);
            moves = min(moves, min(x, prev)+n-max(x, prev) );
            curr = moves + recur(positions, key, idx+1, x) + 1;
            res = min(res, curr);
        }
        return res;
    }
    
    int findRotateSteps(string ring, string key) {
        int res = 0;
        unordered_map<char, vector<int>> positions;
        n = ring.length();
        for(int i = 0; i < n; i++) {
            positions[ring[i]].push_back(i);
        }
        
        return recur(positions, key, 0, 0);
    }
};

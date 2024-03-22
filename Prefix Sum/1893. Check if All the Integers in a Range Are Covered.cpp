class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int>temp(52, 0);
        for(auto x: ranges) {
            temp[x[0]]++;
            temp[x[1]+1]--;
        }
        
        for(int i = 1; i < 52; i++) {
            temp[i] += temp[i-1];
        }
        
        for(int i = left; i <= right; i++) {
            if(!temp[i]) return false;
        }
        return true;
    }
};

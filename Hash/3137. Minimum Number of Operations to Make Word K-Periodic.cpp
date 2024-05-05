class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        int n = word.length()/k, res = INT_MAX;
        
        for(int i = 0; i < word.length(); i+=k) {
            string temp = word.substr(i, k);
            mp[temp]++;
            res = min(res, n - mp[temp]);
        }
        
        return res;
    }
};

// using SLIDING WINDOW
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        unordered_map<int,int>mp;
        int l = 0, r = 0;
        int n = fruits.size();
        while(r < n) {
            mp[fruits[r]]++;
            if(mp.size() <= 2) {
                // well n good
                res = max(res, r - l + 1);
            } else {
                // if type more than 2
                while(mp.size() > 2) {
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0) {
                        mp.erase(fruits[l]);
                    }
                    l++; // shrinking the window here
                }
            }
            r++;
        }
        
        return res;
    }
};

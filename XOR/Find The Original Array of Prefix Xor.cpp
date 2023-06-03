class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n,0);
        for(int i=n-1 ; i>=0 ; i--) {
            if(i == 0) {
                res[i] = pref[i];
            } else {
                res[i] = pref[i] ^ pref[i-1];
            }
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        vector<int>temp;
        unordered_map<int, int> mp;
        
        for(auto x: arr2) {
            mp[x] = 0;
        }
        
        for(auto x: arr1) {
            if(mp.find(x) != mp.end()) {
                mp[x]++;
            } else {
                temp.push_back(x);
            }
        }
        
        for(int x: arr2) {
            int freq = mp[x];
            vector<int>temp(freq, x);
            copy(temp.begin(), temp.end(), back_inserter(res));
        }
        
        sort(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), back_inserter(res));
        
        return res;
    }
};

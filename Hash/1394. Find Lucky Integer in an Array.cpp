class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int, greater<int>> mp;
        for(int x: arr) {
            mp[x]++;
        }

        for(auto x: mp) {
            if(x.first == x.second) return x.first;
        }

        return -1;
        
    }
};

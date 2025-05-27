class Solution {
public:
    int MOD = 1e9+7;

    int recur(int len, unordered_map<int,int>&mp) {
        if(len == 0) return 1;
        if(len < 0) return 0;
        if(mp.find(len) != mp.end()) {
            return mp[len];
        }

        int res = (recur(len-1, mp))%MOD;
        res = (res + (recur(len-2, mp)))%MOD;
        res = (res + (recur(len-3, mp)))%MOD;

        return mp[len] = res;
    }

    int recur79(int len, unordered_map<int,int>&mp79) {
        if(len == 0) return 1;
        if(len < 0) return 0;
        if(mp79.find(len) != mp79.end()) {
            return mp79[len];
        }

        int res = (recur79(len-1, mp79))%MOD;
        res = (res + (recur79(len-2, mp79)))%MOD;
        res = (res + (recur79(len-3, mp79)))%MOD;
        res = (res + (recur79(len-4, mp79)))%MOD;

        return mp79[len] = res;
    }

    int countTexts(string pressedKeys) {
        int res = 1;
        unordered_map<int, int>mp;
        unordered_map<int, int>mp79;
        int n = pressedKeys.size();
        vector<pair<int,int>>pressedLengths;
        int curr = 1;
        for(int i = 1; i < pressedKeys.size(); i++) {
            if(pressedKeys[i] == pressedKeys[i-1]) {
                curr++;
            } else {
                pressedLengths.push_back({pressedKeys[i-1], curr});
                curr = 1;
            }
        }

        pressedLengths.push_back({pressedKeys[n-1], curr});

        // for(auto i: pressedLengths) {
        //     cout<<i.first<<":"<<i.second<<"   ";
        // } cout<<endl<<endl;

        for(auto x: pressedLengths) {
            if(x.first == '7' || x.first == '9') {
                if(mp79.find(x.second) == mp79.end()) {
                    int r = recur79(x.second, mp79);
                    mp79[x.second] = r; 
                    res = ( (long long) res * r )%MOD;
                } else {
                    res = ( (long long) res * mp79[x.second] )%MOD;
                } 
            } else {
                if(mp.find(x.second) == mp.end()) {
                    int r = recur(x.second, mp);
                    mp[x.second] = r; 
                    res = ( (long long)res * r )%MOD;
                } else {
                    res = ( (long long) res * mp[x.second] )%MOD;
                } 
            }
            
            // cout<<mp[x]<<"   ";
        } 
        // cout<<endl<<endl;

        return res;
    }
};

// 6 6
// 66





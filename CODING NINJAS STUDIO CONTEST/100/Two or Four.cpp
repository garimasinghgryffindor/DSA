#include <bits/stdc++.h>

namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            // Use a combination of hash functions for the two integers
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}

bool recur(vector<int>&v, int idx, int curr, unordered_map<pair<int,int>, int>&dp) {
    if(idx < 0) {
        if(curr == 1) return true;
        return false;
    }

    if (dp.find({idx, curr}) != dp.end()) {
        return dp[{idx, curr}] == 1;
    }

    // either you will divide; only when divisible
    if(curr%v[idx] == 0) {
        if(recur(v, idx-1, curr/v[idx], dp)) {
            return dp[{idx, curr}] = 1;
        }
    }
    
    // or you will multiply
    return dp[{idx, curr}] = recur(v, idx-1, curr*v[idx], dp);
}

int canYouGetOne(int n, vector<int> &v) {
    unordered_map< pair<int,int>, int> dp;
    bool res = recur(v, n-1, 1, dp);
    if(res) return 1;
    return 0;
}

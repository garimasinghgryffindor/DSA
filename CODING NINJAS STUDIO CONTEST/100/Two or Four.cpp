// BRUTE FORCE
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


// GREEDY
/*
    Time Complexity: O(n)
    Space Complexity: O(1)

    Where 'n' denotes the length of the vector 'v'.
*/

int canYouGetOne(int n, vector<int> &v) {
    // Initialize the integers 'fourCount' and 'twoCount' equal to '0'.
    int fourCount = 0, twoCount = 0;

    // Calculate the frequency of '2' and '4'.
    for (int i = 0; i < n; i++) {
        if (v[i] == 2) {
            twoCount++;
        }
        else {
            fourCount++;
        }
    }

    // Check the parity of 'twoCount' and 'fourCount' to calculate the answer.
    if (twoCount % 2 != 0) {

        // 'twoCount' is odd.
        return 0;
    }
    else if (fourCount % 2 == 0) {

        // 'twoCount' and 'fourCount' are even.
        return 1;
    }
    else if (twoCount == 0 || (twoCount == 2 && v[0] == 2 && v[n - 1] == 2)) {

        // 'twoCount' is even and 'fourCount' is odd, so check the first and last element and total number of '2'.
        return 0;
    }
    else {
        return 1;
    }
}

// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events) {
//         int res = 0;
//         // brute force
//         int n = events.size();
//         for(auto x: events) {
//             int st = x[0], end = x[1];
//             res = max(res, x[2]);
//             for(auto y: events) {
//                 int st2 = y[0], end2 = y[1];
//                 if(st2 > end || end2 < st) {
//                     res = max(res, x[2] + y[2]);
//                 }
//             }
//         }

//         return res;
//     }
// };

int binarySearchU(vector<vector<int>>&vec, int num) {
    int l = 0, r = vec.size()-1;
    int res = -1;
    int mid;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(vec[mid][0] >= num) {
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    return res == -1 ? 0 : vec[res][2];
}

int binarySearchL(vector<vector<int>>&vec, int num) {
    int l = 0, r = vec.size()-1;
    int res = -1;
    int mid;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(vec[mid][0] <= num) {
            res = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    return res == -1 ? 0 : vec[res][2];
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int res = 0;
        int n = events.size();
        vector<vector<int>>sortedbystart(n, vector<int>(3, 0)), sortedbyend(n, vector<int>(3, 0));
        for(int i = 0; i < n; i++) {
            sortedbystart[i][0] = events[i][0];
            sortedbystart[i][1] = events[i][2];
            sortedbyend[i][0] = events[i][1];
            sortedbyend[i][1] = events[i][2];
        }

        sort(sortedbystart.begin(), sortedbystart.end());
        sort(sortedbyend.begin(), sortedbyend.end());

        sortedbyend[0][2] = sortedbyend[0][1];
        for(int i = 1; i < n; i++) {
            sortedbyend[i][2] = max(sortedbyend[i-1][2], sortedbyend[i][1]);
        }


        sortedbystart[n-1][2] = sortedbystart[n-1][1];
        for(int i = n-2; i >= 0; i--) {
            sortedbystart[i][2] = max(sortedbystart[i+1][2], sortedbystart[i][1]);
        }
        
        for(auto x: events) {
            int st = x[0], end = x[1];
            res = max(res, x[2]);
            int u = binarySearchU(sortedbystart, end+1);
            res = max(res, x[2] + u);
            int l = binarySearchL(sortedbyend, st-1);
            res = max(res, x[2] + l);
        }

        return res;
    }
};

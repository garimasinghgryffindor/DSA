// // memoization
// class Solution {
// private:
//     int dpi[1000][3];
//     int fi(int idx, int cnt, vector<int> &rating) {
//         // base cases
//         if(cnt == 3) return 1;
//         if(dpi[idx][cnt] != -1) return dpi[idx][cnt];

//         int res = 0;
//         for(int i=idx+1; i<rating.size(); ++i) {
//             if(rating[i] <= rating[idx]) continue;
//             res += fi(i, cnt+1, rating);
//         }
//         return dpi[idx][cnt] = res;
//     }
//     int dpd[1000][3];
//     int fd(int idx, int cnt, vector<int> &rating) {
//         // base cases
//         if(cnt == 3) return 1;
//         if(dpd[idx][cnt] != -1) return dpd[idx][cnt];

//         int res = 0;
//         for(int i=idx+1; i<rating.size(); ++i) {
//             if(rating[i] >= rating[idx]) continue;
//             res += fd(i, cnt+1, rating);
//         }
//         return dpd[idx][cnt] = res;
//     }
// public:
//     int numTeams(vector<int>& rating) {
//         int res = 0;
//         memset(dpi, -1, sizeof(dpi));
//         memset(dpd, -1, sizeof(dpd));
//         for(int i=0; i<rating.size(); ++i) {
//             res += fi(i,1,rating);
//             res += fd(i,1,rating);
//         }
//         return res;
//     }
// };


// tabulation
class Solution {
private:
    int dpi[1000][4];
    int dpd[1000][4];
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int n = rating.size();
        memset(dpi, 0, sizeof(dpi));
        memset(dpd, 0, sizeof(dpd));
        
        for(int i = 0; i < n; i++) {
            dpi[i][3] = 1;
            dpd[i][3] = 1;
        }
        
        for(int cnt = 2; cnt > 0;  cnt--) {
            for(int i = 0; i < n; ++i) {
                int res1 = 0, res2 = 0;
                for(int j = i+1; j < n; j++) {
                    if(rating[j] > rating[i]) res1 += dpi[j][cnt+1];
                    if(rating[j] < rating[i]) res2 += dpd[j][cnt+1];
                }
                dpi[i][cnt] = res1;
                dpd[i][cnt] = res2;
            }
        }
        
        for(int i=0; i<n; ++i) {
            res += dpi[i][1];
            res += dpd[i][1];
        }
        return res;
    }
};

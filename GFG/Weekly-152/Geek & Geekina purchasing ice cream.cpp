//User function Template for C++

class Solution {
  public:
    long long findGoodPairs(vector<int> a, int n, int k) {
       long cnt = 0;
        unordered_map<int, long> map;
        for (int i = k; i < n; i++) {
            map[a[i - k]]++;
            cnt += map[a[i]];
        }
        return cnt;
    }
};

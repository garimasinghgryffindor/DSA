//User function Template for C++

class Solution{   
public:
    vector<int> frequency(int n, vector<int> &a){
        // Write your code here.
        unordered_map<int, int> frq;
        vector<int>res(n, 0);
        for(int i = n-1; i >= 0; i--) {
            frq[a[i]]++;
            res[i] = frq[a[i]];
        }
        return res;
    }
};

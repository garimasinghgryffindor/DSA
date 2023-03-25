class Solution {
public:
    vector<int>parent;
    
    int find(int u) {
        if(parent[u] < 0) {
            return u;
        }
        return find(parent[u]);
    }
    
    void unionByWeight(int u, int v) {
        int pu = find(u) , pv = find(v);
        
        if(pu != pv) {
            if(parent[pu] < parent[pv]) {
                parent[pu] += parent[pv];
                parent[pv] = pu;
            } else {
                parent[pv] += parent[pu];
                parent[pu] = pv;
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n,-1);
        long long res = 0;
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            if(find(u) != find(v)) {
                // i.e; they do not belong to the same component
                unionByWeight(u,v);
            }
        }
        
        // [1, 4, 2] 
        
        // let count us the number of components
        vector<int>components;
        
        for(int i=0 ; i<n ; i++) {
            if(parent[i] < 0) {
                components.push_back(-parent[i]);
            }
        }
        
        int sz = components.size();
        
        // let us calculate prefix sum for easeful calculation
        vector<int> prefixSum(sz,0);
        for(int i=0 ; i<sz ; i++) {
            if(i==0) {
                prefixSum[i] = components[i];
            } else {
                prefixSum[i] = prefixSum[i-1] + components[i];
            }
        }
        
        reverse(prefixSum.begin(), prefixSum.end());
        reverse(components.begin(), components.end());
        
        for(int i=0 ; i<sz-1 ; i++) {
            res += (long long)components[i]*((long long)prefixSum[i]-(long long)components[i]);
        }
        
        return res;
    }
};

// // O(N) TLE
// class TreeAncestor {
// public:
//     int n;
//     vector<int>parent;
//     TreeAncestor(int n, vector<int>& parent) {
//         this->n = n;
//         this->parent = parent;
//     }
    
//     int getKthAncestor(int node, int k) {
//         int x = node;
//         int k1 = k;
//         while(k1) {
//             k1--;
//             x = parent[x];
//             if(x == -1) return -1;
//         }
//         return x;
//     }
// };


class TreeAncestor {
public:
    int n;
    vector<vector<int>>v;
    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        vector<vector<int>> par(n, vector<int>(20));
        for(int i = 0; i < n; i++) par[i][0] = parent[i];
        
        for(int j = 1; j < 20; j++) {
            for(int i = 0; i < n; i++) {
                if(par[i][j-1] == -1) par[i][j] = -1;
                else par[i][j] = par[par[i][j-1]][j-1];
            }
        }
        swap(v, par);
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++) {
            if((k >> i) & 1) {
                node = v[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

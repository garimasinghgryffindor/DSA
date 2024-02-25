class Solution {
public:
    unordered_map<int, vector<int>> mp;
    vector<int>parent;
    
    void gcd(int n, int i) {
        if(n%2==0) mp[2].push_back(i);
        while(n%2==0) n/=2;
        for(int x=3; x<=sqrt(n); x+=2) 
        { 
            if(n%x==0) mp[x].push_back(i);
            while(n%x==0) n/=x; 
        }
        if(n>2) mp[n].push_back(i);
    }
    
    int find(int x) {
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    
    void union_(int x, int y) {
        int px = find(x), py = find(y);
        if(px != py) {
            if(parent[px] <= parent[py]) {
                parent[px] += parent[py];
                parent[py] = px;
            } else {
                parent[py] += parent[px];
                parent[px] = py;
            }
        }
    }
    
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            gcd(nums[i], i);
        }
        
        parent.resize(n, -1);
        
        for(auto x: mp) {
            int sz = (x.second).size();
            if(sz > 1) {
                int first = (x.second)[0];
                // cout<<"first:  "<<first<<endl;
                for(int i = 1; i < sz; i++) {
                    // cout<<(x.second)[i]<<"  ";
                    union_(first, (x.second)[i]);
                } 
            }
        }
        
        int firstPar = find(0);
        for(int i = 1; i < n; i++) {
            if(find(i) != firstPar) return false;
        }
        
        return true;
    }
};

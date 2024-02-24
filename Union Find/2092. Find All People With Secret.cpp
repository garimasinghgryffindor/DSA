class Solution {
public:
    vector<int> parent;
    vector<bool>knows;
    
    static bool compare(vector<int>&a, vector<int>&b) {
        return a[2] < b[2];
    }
    
    int find(int x) {
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    
    void union_(int u, int v) {
        int pu = find(u), pv = find(v);
        
        if(pu != pv) {
            if(parent[pu] < parent[pv]) {
                parent[pu]+=parent[pv];
                parent[pv] = pu;
            } else {
                parent[pv]+=parent[pu];
                parent[pu] = pv;
            }
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
     
        sort(meetings.begin(), meetings.end(), compare);
        vector<int>res;      
        parent.resize(n, -1);
        knows.resize(n, false);
        
        knows[0] = true;    knows[firstPerson] = true;
        union_(0, firstPerson);
        
        int i = 0;
        
        while(i < meetings.size()) {
            int time = meetings[i][2];
            
            vector<int>temp;
            while(i < meetings.size() && meetings[i][2] == time) {
                int u = meetings[i][0], v = meetings[i][1];
                union_(u, v);
                i++;
                temp.push_back(u); temp.push_back(v);
            }
            
            for(auto x: temp) {
                if(find(x) != find(0)) {
                    parent[x] = -1;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0)) {
                res.emplace_back(i);
            }
        }
        
        return res;
    }
};


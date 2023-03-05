class Solution {
public:
    int minJumps(vector<int>& arr) {
        queue<pair<int,int> > q;
        q.push({0,0});
        vector<bool> vis(arr.size(), false);
        unordered_map<int, vector<int>> mp;
        
        for(int i=0 ; i<arr.size() ; i++) {
            mp[arr[i]].push_back(i);
        }
        
        vis[0] = true;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            int dist = x.second;
            int index = x.first;
            
            if(index == arr.size()-1)
                return dist;
            
            if(index-1 >= 0 && !vis[index-1]) {
                vis[index-1] = true;
                q.push({index-1, dist+1});
            }
            
            if(index+1 < arr.size() && !vis[index+1]) {
                vis[index+1] = true;
                q.push({index+1, dist+1});
            }
            
            for(auto x: mp[arr[index]]) {
                if(!vis[x]) {
                    vis[x] = true;
                    q.push({x, dist+1});
                }
            }
            
            mp[arr[index]] = {};
        }
        
        return INT_MAX;
    }
};




Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0, res = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        unordered_map<string, int> mp;
        for(auto i: obstacles) {
            string temp = to_string(i[0]) + "," + to_string(i[1]);
            mp[temp] = 1;
        }
        
        for(auto c: commands) {
            if(c < 0) {
                // cmd
                if(c == -1) {
                    // turn right
                    d = (d+1)%4;
                } else {
                    // turn left
                    d = (d+3)%4;
                }
            } else {
                // dist
                for(int i = 0; i < c; i++) {
                    int x_ = x+dir[d][0];
                    int y_ = y+dir[d][1];
                    if(mp.find({to_string(x_)+","+to_string(y_)}) != mp.end()) {
                        break;
                    }
                    x = x_;
                    y = y_;
                    res = max(res, x*x + y*y);
                }
            }
        }
        
        return res;
    }
};

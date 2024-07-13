class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<int>res;
        // brute force approach
        vector<vector<int>> vec;
        int n = positions.size();
        
        for(int i = 0; i < n; i++) {
            vec.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(vec.begin(), vec.end());
        vector<vector<int>> stack;
        
        for(auto robot: vec) {
            if(robot[2] == 'R' || stack.empty() || stack.back()[2] == 'L') {
                stack.push_back({robot});
            } else {
                // collision
                bool add = true;
                while(!stack.empty() && stack.back()[2] == 'R' && add) {
                    int last_health = stack.back()[1];
                    int curr_health = robot[1];
                    
                    if(last_health > curr_health) {
                        stack.back()[1] -= 1;
                        add = false;
                    } else if(last_health < curr_health) {
                        stack.pop_back();
                        robot[1] -= 1;
                    } else {
                        stack.pop_back();
                        add = false;
                    }
                }
                
                if(add) {
                    stack.push_back(robot);
                }
            }
        }
        
        sort(stack.begin(), stack.end(), [](vector<int>& a, vector<int>& b) {
            return a[3] < b[3];
        });
        
        
        for (auto& robot : stack) {
            res.push_back(robot[1]);
        }

        return res;
    }
};

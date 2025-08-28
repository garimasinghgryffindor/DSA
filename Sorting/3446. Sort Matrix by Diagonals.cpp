class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // go through first elements of all rows
        for(int i = 0; i < r; i++) {
            int x = i;
            int y = 0;
            vector<int>vec;
            while(x < r && y < c) {
                vec.push_back(grid[x][y]);
                x++;
                y++;  
            }

            sort(vec.rbegin(), vec.rend());

            x = i;
            y = 0;
            int cnt = 0;
            while(x < r && y < c) {
                grid[x][y] = vec[cnt];  cnt++;
                x++;    y++;
            }
        }

        // go through first elements of all cols
        for(int i = 1; i < c; i++) {
            int x = 0;
            int y = i;
            vector<int>vec;
            while(x < r && y < c) {
                vec.push_back(grid[x][y]);
                x++;
                y++;  
            }

            sort(vec.begin(), vec.end());

            x = 0;
            y = i;
            int cnt = 0;
            while(x < r && y < c) {
                grid[x][y] = vec[cnt];  cnt++;
                x++;    y++;
            }
        }

        return grid;
    }
};

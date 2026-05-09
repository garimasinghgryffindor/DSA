class Solution {
public:

    void rotation(vector<vector<int>>& res,
                  vector<vector<int>>& grid,
                  int layer,
                  int rot) {

        vector<pair<int,int>> pos;

        int n = grid.size();
        int m = grid[0].size();

        int top = layer;
        int left = layer;

        int bottom = n - layer - 1;
        int right = m - layer - 1;

        // top row
        for(int c = left; c <= right; c++)
            pos.push_back({top, c});

        // right column
        for(int r = top + 1; r <= bottom; r++)
            pos.push_back({r, right});

        // bottom row
        for(int c = right - 1; c >= left; c--)
            pos.push_back({bottom, c});

        // left column
        for(int r = bottom - 1; r > top; r--)
            pos.push_back({r, left});

        vector<int> vals;

        for(auto &[r,c] : pos)
            vals.push_back(grid[r][c]);

        rot %= vals.size();

        rotate(vals.begin(), vals.begin() + rot, vals.end());

        for(int i = 0; i < pos.size(); i++) {
            auto &[r,c] = pos[i];
            res[r][c] = vals[i];
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res = grid;

        int layers = min(m, n) / 2;

        for(int i = 0; i < layers; i++) {

            int height = m - 2*i;
            int width = n - 2*i;

            int num_of_elem = 2 * (height + width) - 4;

            int actual_rotations = k % num_of_elem;

            rotation(res, grid, i, actual_rotations);
        }

        return res;
    }
};

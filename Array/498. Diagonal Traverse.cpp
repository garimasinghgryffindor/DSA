class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int r = mat.size();
        int c = mat[0].size();

        bool flow = true;
        for(int i = 0; i < r; i++) {
            int x = i;
            int y = 0;
            vector<int>temp;
            while(x >= 0 && y < c) {
                temp.push_back(mat[x][y]);
                x--;
                y++;
            }

            if(flow) {
                for(int x: temp) {
                    res.push_back(x);
                }
            } else {
                for(int j = temp.size()-1; j >= 0; j--) {
                    res.push_back(temp[j]);
                }
            }
            flow = !flow;
        }

        for(int i = 1; i < c; i++) {
            int x = r-1;
            int y = i;

            vector<int>temp;
            while(x >= 0 && y < c) {
                temp.push_back(mat[x][y]);
                x--;
                y++;
            }

            if(flow) {
                for(int x: temp) {
                    res.push_back(x);
                }
            } else {
                for(int j = temp.size()-1; j >= 0; j--) {
                    res.push_back(temp[j]);
                }
            }
            flow = !flow;
        }

        return res;
    }
};

// [2  5   8]
// [4  0  -1]

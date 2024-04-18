class Solution {
public:
    int helper(vector<vector<int>>&grid,int i , int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0) return 1;
        if(grid[i][j]==-1) return 0;
        grid[i][j]=-1;
        return helper(grid,i+1,j)+helper(grid,i,j+1)+helper(grid,i-1,j)+helper(grid,i,j-1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ct = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==1)
                    ct = helper(grid,i , j);
            }
        }
        
        return ct;
    }
};

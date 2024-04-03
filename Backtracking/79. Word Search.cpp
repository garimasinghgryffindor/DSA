class Solution {
public:
    bool dfs(vector<vector<char>>&board, int r, int c, string&word, int idx) {
        if(idx == word.size()) return true;
        int n = board.size(), m = board[0].size();
        
        if(r<0 || r>=n || c<0 || c>=m) return false;
        
        // vector<int>Rows = {-1, 0, 1, 0};
        // vector<int>Cols = {0, 1, 0, -1};
        
        if(board[r][c] != word[idx]) return false;
        char ch = board[r][c];
        board[r][c] = '$';
        
        bool ret = dfs(board, r, c+1, word, idx+1) || dfs(board, r+1, c, word, idx+1) || dfs(board, r-1, c, word, idx+1) || dfs(board, r, c-1, word, idx+1);
        
        board[r][c] = ch;
        
        if(ret) return true;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dfs(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};

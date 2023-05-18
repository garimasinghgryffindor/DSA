// BRUTE FORCE

class Solution {
public:
    void recur(int n,set<vector<string> >&res,int j,vector<string>temp,int ans) {
        if(ans == n) {
            res.insert(temp);
            return;
        }
        
        for(int k=0 ; k<n ; k++) {
                
            int flag = 1;

            int x = k;
            int y = j;

            // validation check over here for the index (x,y)
            // checking rows and cols
            for(int k=0 ; k<n ; k++) {
                if(temp[x][k] == 'Q' || temp[k][y] == 'Q') {
                    // not valid
                    flag = 0;
                    break;
                }
            }

            // checking diagonal elements
            int u = x, v = y;
            // towards top-left
            while(u>=0 && v>=0) {
                if(temp[u][v] == 'Q') {
                    // not valid
                    flag = 0;
                    break;
                }
                u--, v--;
            }
            u=x,v=y;
            // towards bottom-right
            while(u<n && v<n) {
                if(temp[u][v] == 'Q') {
                    // not valid
                    flag = 0;
                    break;
                }
                u++, v++;
            }
            u=x,v=y;
            // towards top-right
            while(u>=0 && u<n && v<n && v>=0) {
                if(temp[u][v] == 'Q') {
                    // not valid
                    flag = 0;
                    break;
                }
                u--;
                v++;
            }
            u=x,v=y;
            // towards top-left
            while(u<n && u>=0 && v>=0 && v<n) {
                if(temp[u][v] == 'Q') {
                    // not valid
                    flag = 0;
                    break;
                }
                u++;
                v--;
            }
            // checking diagonal elements ends here
            

            if(flag == 0)
                continue;

            // valid index otherwise
            temp[x][y] = 'Q';
            ans++;

            if(ans == n) {
                res.insert(temp);
                continue;
            }

            // make a recursive function call
            recur(n,res,y+1,temp,ans);

            // backtrack
            temp[x][y] = '.';
            ans--;
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        if(n==1) {
            return{{"Q"}};
        }
        
        set<vector<string>> res;
        
        vector<string>temp(n);
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                temp[i].push_back('.');
            }
        }
        
        int ans=0;
        
        recur(n,res,0,temp,ans);
        
        vector<vector<string>> res2(res.begin(),res.end());
        
        return res2;
    }
};




// (checking valid position) OPTIMIZED using HASHING


class Solution {
public:
    void recur(int n,set<vector<string> >&res,int j,vector<string>temp,int ans,vector<int>&leftRow,vector<int>&upperDiagonal,vector<int>&lowerDiagonal) {
        if(j == n) {
            res.insert(temp);
            return;
        }
        
        for(int k=0 ; k<n ; k++) {

            int x = k;
            int y = j;

            // validation check over here for the index (x,y)
            if(leftRow[x]==0 && lowerDiagonal[x+y]==0 && upperDiagonal[n-1+y-x]==0)
            {
                // a valid position
                temp[x][y] = 'Q';
                ans++;
                leftRow[x] = 1;
                lowerDiagonal[x+y] = 1;
                upperDiagonal[n-1+y-x] = 1;
                
                // make a recursive function call
                recur(n,res,y+1,temp,ans,leftRow,upperDiagonal,lowerDiagonal);
                
                // backtrack
                temp[x][y] = '.';
                leftRow[x] = 0;
                lowerDiagonal[x+y] = 0;
                upperDiagonal[n-1+y-x] = 0;
                ans--;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        if(n==1) {
            return{{"Q"}};
        }
        
        set<vector<string>> res;
        
        vector<string>temp(n);
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                temp[i].push_back('.');
            }
        }
        
        int ans=0;
        
        vector<int> leftrow(n,0), upperDiagonal(2*n-1,0), lowerDiagonal(2*n-1,0);
        
        recur(n,res,0,temp,ans,leftrow,upperDiagonal,lowerDiagonal);
        
        vector<vector<string>> res2(res.begin(),res.end());
        
        return res2;
    }
};


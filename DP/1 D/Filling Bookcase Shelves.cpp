// RECURSIVE
// TLE

class Solution {
public:
    int recur(int n,vector<vector<int>>books,int width,int index) {
        // base case
        if(index < 0)
            return 0;
        
        int resHeight = INT_MAX;
        // the choices we have
        // uptil filling the current level's full width
        int height=INT_MIN;
        int availableWidth = width;
        
        for(int i=index ; i>=0 && availableWidth - books[i][0]>=0 ; i--) {
            height = max(height, books[i][1]);
            availableWidth -= books[i][0];
            int currTotalHeight = height + recur(n,books,width,i-1);
            resHeight = min(currTotalHeight, resHeight);
        }
        
        return resHeight;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        return recur(n,books,shelfWidth,n-1);    
    }
};



// MEMOIZATION

class Solution {
public:
    int recur(int n,vector<vector<int>>books,int width,int index,vector<int>&dp) {
        // base case
        if(index < 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int resHeight = INT_MAX;
        // the choices we have
        // uptil filling the current level's full width
        int height=INT_MIN;
        int availableWidth = width;
        
        for(int i=index ; i>=0 && availableWidth - books[i][0]>=0 ; i--) {
            height = max(height, books[i][1]);
            availableWidth -= books[i][0];
            int currTotalHeight = height + recur(n,books,width,i-1,dp);
            resHeight = min(currTotalHeight, resHeight);
        }
        
        dp[index] = resHeight;
        return dp[index];
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n+1,-1);
        return recur(n,books,shelfWidth,n-1,dp);    
    }
};




// TABULATION

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int width) {
        int n = books.size();
        vector<int>dp(n+1,-1);
        
        // base case
        dp[0] = 0;
        for(int i=1 ; i<n+1 ; i++) {
            int resHeight = INT_MAX;
            // the choices we have
            // uptil filling the current level's full width
            int height=INT_MIN;
            int availableWidth = width;

            for(int j=i ; j>0 && availableWidth - books[j-1][0]>=0 ; j--) {
                height = max(height, books[j-1][1]);
                availableWidth -= books[j-1][0];
                int currTotalHeight = height + dp[j-1];
                resHeight = min(currTotalHeight, resHeight);
            }
            
            dp[i] = resHeight;
        }
        
        return dp[n];
    }
};


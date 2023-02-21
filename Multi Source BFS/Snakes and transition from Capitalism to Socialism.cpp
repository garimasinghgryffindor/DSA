#include <iostream>
#include <climits>
#include<vector>
#include <queue>

using namespace std;

// using multisource bfs

int multiSourceBfs(vector<vector<int> > &grid,int n,int m) {
    
    int res = 0;
    int movesX[] = {-1,0,1,0,-1,-1,1,1};
    int movesY[] = {0,1,0,-1,-1,1,-1,1};
    
    int mx = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            mx = max(mx,grid[i][j]);
        }
    }
    
    queue<pair<int,int> > q;
    vector<vector<int> > hours(n,vector<int>(m,INT_MAX));
    vector<vector<bool> > visited(n,vector<bool>(m,false));
    
    
    // pushing alll the sources to the push
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            if(grid[i][j] == mx) {
                q.push({i,j});
                hours[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0 ; i<8 ; i++) {
            int newX = x+movesX[i];
            int newY = y+movesY[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m ) {
                // if they are valid coords as per the grid
                if(!visited[newX][newY]) {
                    q.push({newX,newY});
                    visited[newX][newY] = true;
                    hours[newX][newY] = hours[x][y] + 1;
                    res = max(res,hours[newX][newY]);
                }
            }
        }
        
    }
    
    return res;
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int> > grid(n, vector<int> (m, 0));
	    for(int i=0 ; i<n ; i++) {
	        for(int j=0 ; j<m ; j++) {
	            cin>>grid[i][j];
	        }
	    }
	    int res = multiSourceBfs(grid,n,m);
	    cout<<res<<endl;
	}
	return 0;
}



CODECHEF


After a long duration of the painful, torturous and tumultuous periods of capitalism in Snakeland, now the snakes have decided to adopt socialism. The houses in Snakeland are arranged in a rectangular fashion of dimension n * m. The wealth of the snake in the house at cell (i, j) is given by a[i][j] rupees.

A bill has been passed for making a smooth transition from capitalism to socialism. At the end of each hour, the wealth of a snake will grow and will become equal to the highest wealth that its neighbor had (at the start of the hour). That is, consider the maximum wealth among its neighbors at the start of the hour, and this snake's wealth will become equal to that at the end of the hour. Note that this increase in wealth will happen simultaneously for each snake. Two houses are said to be neighbors of each other if they share a side or corner with each other. Find out the minimum number of hours required for this transition.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains two space separated integers: n, m.

Each of the next n lines contains m space separated integers. The j-th integer in the i-th row denotes a[i][j].

Output
For each test case output a single integer corresponding to the minimum number of hours required for the transition.

Constraints
1 ≤ T ≤ 4
1 ≤ n, m ≤ 500
1 ≤ a[i][j] ≤ 106





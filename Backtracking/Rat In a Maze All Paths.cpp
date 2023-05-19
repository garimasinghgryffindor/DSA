#include <bits/stdc++.h> 

void recur(vector<vector<int>>maze,int n,vector<vector<int>>&res,vector<int>temp,int r,int c) {
  if(r==n-1 && c==n-1) {
    res.push_back(temp);
    return;
  }

  // i can either of go right, or left, or top , or bottom
  // secondly i don't have to repeat same node in a path


  // go right
  if(c<n-1 && !temp[(r)*(n)+c+1] && maze[r][c+1]) {
    temp[(r)*(n)+c+1] = 1;
    recur(maze,n,res,temp,r,c+1);
    temp[(r)*(n)+c+1] = 0;
  }

  // go down
  if(r<n-1 && !temp[(r+1)*(n)+c] && maze[r+1][c]) {
    temp[(r+1)*(n)+c] = 1;
    recur(maze,n,res,temp,r+1,c);
    temp[(r+1)*(n)+c] = 0;
  }

  // go left
  if(c>0 && !temp[(r)*(n)+c-1] && maze[r][c-1]) {
    temp[(r)*(n)+c-1] = 1;
    recur(maze,n,res,temp,r,c-1);
    temp[(r)*(n)+c-1] = 0;
  }

  // go top
  if(r>0 && !temp[(r-1)*(n)+c] && maze[r-1][c]) {
    temp[(r-1)*(n)+c] = 1;
    recur(maze,n,res,temp,r-1,c);
    temp[(r-1)*(n)+c] = 0;
  }

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> res;
  vector<int>temp(n*n,0);
  temp[0] = 1;
  recur(maze,n,res,temp,0,0);

  sort(res.begin(),res.end());

  return res;

}

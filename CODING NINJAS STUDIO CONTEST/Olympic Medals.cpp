bool recur(int g, int s, int b, vector<vector<int>>&prizes,int n) {
    if(g == 0 && s == 0 && b == 0) return true;
    if(n == 0) return false;

    // play

    // don't play
    return recur(g,s,b,prizes,n-1) || recur(g-prizes[n-1][0],s-prizes[n-1][1],b-prizes[n-1][2],prizes, n-1);
}

int possibleOrNot(int n, int g, int s, int b, vector<vector<int>> prizes) {
    // Write your code here.
    return recur(g,s,b,prizes,n);
}

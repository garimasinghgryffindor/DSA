// CODE STUDIO PROBLEM

#include <bits/stdc++.h> 

bool recur(int nodes,vector<vector<int>>mat,int m,int pos,vector<int>color) {
    if(pos == nodes)
        return true;
    
    // to be colored node? => pos
    // with how many colors can it be colored? => [1,m]
    // let us try all the possibilies

    for(int i=1 ; i<=m ; i++) {
        // we need to check if it is valid to color it with "i" color
        // be checking all the adjacent nodes
        bool valid = true;
        for(int j=0 ; j<nodes ; j++) {
            if(mat[pos][j]) {
                // if there is an edge
                // we'll check whether it is colored with the "i" color
                if(color[j] == i) {
                    // not possible to color
                    valid = false;
                    break;
                }
            }
        }

        if(valid) {
            // if it is possible to color
            // color the node
            // and recursively call function for the next position
            color[pos] = i;
            bool ans = recur(nodes,mat,m,pos+1,color);
            if(ans == true)
                return true;
            color[pos] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int nodes = mat.size();

    vector<int>color(nodes,0);
    bool ans = recur(nodes,mat,m,0,color);
    if(ans) {
        return "YES";
    } 
    return "NO";
}

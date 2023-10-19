// USING RECURSION
bool recur(string&wild,string&pattern,int i, int j) {
    if(i == wild.length() && j == pattern.length()) return true;
    if(i > wild.length() || j > pattern.length()) return false;
    
    if(wild[i] == pattern[j]) return recur(wild,pattern,i+1,j+1);
    
    if(wild[i] == '?') return recur(wild,pattern,i+1,j+1);
    if(wild[i] == '*') {
        // either take none
        if(recur(wild,pattern,i+1,j)) return true;
        // or recursively take one
        if(recur(wild, pattern, i+1,j+1)) return true;
        // or recursively take many
        return recur(wild,pattern,i,j+1);
    }
    
    return false;
}

bool match(string wild, string pattern)
{
    return recur(wild, pattern, 0, 0);
}


// USING MEMOIZATION
bool recur(vector<vector<int>>&mem, string&wild, string&pattern, int i, int j) {
    if(mem[i][j] != -1) return mem[i][j];
    
    if(i == wild.length() && j == pattern.length()) {return mem[i][j] = true;}
    if(i > wild.length() || j > pattern.length()) {return mem[i][j] = false;}
    
    if(wild[i] == pattern[j]) return mem[i][j] = recur(mem, wild,pattern,i+1,j+1);
    
    if(wild[i] == '?') return mem[i][j] = recur(mem, wild,pattern,i+1,j+1);
    if(wild[i] == '*') {
        // either take none
        if(recur(mem, wild,pattern,i+1,j)) return mem[i][j] = true;
        // or recursively take one
        if(recur(mem, wild, pattern, i+1,j+1)) return mem[i][j] = true;
        // or recursively take many
        return mem[i][j] = recur(mem,wild,pattern,i,j+1);
    }
    
    return mem[i][j] = false;
}

bool match(string wild, string pattern)
{
    vector<vector<int>>mem(wild.length()+2, vector<int>(pattern.length()+2, -1));
    return recur(mem, wild, pattern, 0, 0);
}


// USING TABULATION





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



// USING TABULATION





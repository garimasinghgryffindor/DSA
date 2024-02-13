class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string x = a;
        
        while(x.length() < b.length()) {
            x.append(a);    count++;
        }
        
        if(x.find(b) != string::npos) {
            return count;
        }
        
        x.append(a);
        count++;
        if(x.find(b) != string::npos) {
            return count;
        }
        
        return -1;
    }
};

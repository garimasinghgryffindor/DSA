class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3) return false;
        bool vow = false, cons = false;
        for(auto x: word) {
            if(x >= '0' && x <= '9') {
                
            } else if(x >= 'A' && x <= 'Z') {
                
                if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') {
                    vow = true;
                } else {
                    cons = true;
                }
            } else if(x >= 'a' && x <= 'z') {
                
                if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                    vow = true;
                } else {
                    cons = true;
                }
            } else return false;
        }
        
        if(vow && cons) return true;
        
        return false;
    }
};

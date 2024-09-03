class Solution {
public:
    int getLucky(string s, int k) {
        string temp = "";
        for(auto x: s) {
            temp += to_string(x-'a'+1);
        }
        
        if(k == 0) return stoi(temp);
        
        while(k--) {
            int ans = 0;
            for(auto x: temp) {
                ans += x-'0';
            }
            temp = to_string(ans);
        }
        
        return stoi(temp);
    }
};

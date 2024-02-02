class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        
        string str = to_string(low);
        int first_start = str[0] - '0';
        
        string ans;
        
        int first_len = str.length();
        if(first_start + first_len - 1 > 9) {
            first_len++;
            if(first_len > 9) return {};
            first_start = 1;
        }
        
        for(int i = 0; i < first_len; i++) {
            ans = ans + to_string(first_start+i);
        }
        
        int a = stoi(ans);
        if(a >= low && a <= high) {
            res.push_back(a);
        }
        
        int len = first_len;
        
        while(1) {
            if(ans[len-1] != '9') {
                for(int i = 0; i < len; i++) {
                    ans[i] = ans[i]+1;
                }
                a = stoi(ans);
                if(a >= low && a <= high) {
                    res.push_back(a);
                } else if(a < low) {
                    continue;
                } else return res;
            } else {
                len++;
                if(len == 10) break;
                first_start = 1;
                ans = "";
                for(int i = 0; i < len; i++) {
                    ans = ans + to_string(first_start+i);
                }
                
                a = stoi(ans);
                if(a >= low && a <= high) {
                    res.push_back(a);
                } else return res;
            }
        }
        
        return res;
    }
};

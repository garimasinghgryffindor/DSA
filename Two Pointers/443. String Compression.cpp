class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        char prev = chars[0];
        string str = "";
        
        int i = 0;
        for(int k = 1; k < chars.size(); k++) {
            char x = chars[k];
            
            if(prev == x) {
                count++;
            } else {
                if(count == 1) {
                    chars[i] = prev;   i++;
                } else {
                    chars[i] = prev;    i++;
                    string cnt = to_string(count);
                    for(int j = 0; j < cnt.length(); j++) {
                        chars[i] = cnt[j];
                        i++;
                    }
                }
                count = 1;
            }
            prev = x;
        }
        
        if(count == 1) {
            chars[i] = prev;    i++;
        } else {
            chars[i] = prev;    i++;
            string cnt = to_string(count);
            for(int j = 0; j < cnt.length(); j++) {
                chars[i] = cnt[j];
                i++;
            }
        }
        
        return i;
    }
};



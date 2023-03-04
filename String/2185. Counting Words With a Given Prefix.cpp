class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        int len = pref.length();
        for(auto word: words) {
            if(word.substr(0,len) == pref)
                res++;
        }
        
        return res;
    }
};

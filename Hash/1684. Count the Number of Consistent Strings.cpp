class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char , bool>mp;
        for(auto x:allowed){
            mp[x] = true;
        }
        int res = 0;
        for(auto word: words){
            int f = 0;
            for(auto a: word){
                if(!mp[a]){
                    f=1;
                    break;
                }
            }
            if(f==0){
                res++;
            }
        }
        return res;
    }
};

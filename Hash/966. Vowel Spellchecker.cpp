class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int res = 0;
        int len = text.length();
        unordered_map<char,bool>mp;
        for(auto x: brokenLetters) {
            mp[x] = true;
        }

        bool isPossible = true;
        for(auto x: text) {
            if(x != ' ' && isPossible) {
                if(mp.find(x) == mp.end()) {
                    // goodie
                } else {
                    isPossible = false;
                }
            } if (x == ' ' && isPossible) {
                // word end is reached
                res++;
            } else if(x == ' '){
                // word end is reached and is broken word
                isPossible = true;
            }
        }

        if(isPossible) res++;

        return res;

    }
};

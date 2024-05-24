class Solution {
public:
    int recur(vector<string>&words, unordered_map<char, int>mp, vector<int>&score, int idx) {
        if(idx == words.size()) return 0;
        
        // not taking it
        int temp1 = recur(words, mp, score, idx+1);
        
        // taking that word
        int temp2 = 0;
        bool flag = true;
        unordered_map<char, int>mp2;
        for(auto ch: words[idx]) {
            mp2[ch]++;
        }
        for(auto x: mp2) {
            if(mp[x.first] >= mp2[x.first]) {
                // well and good
            } else {
                flag = false;   break;
            }
        }
        if(flag) {
            for(auto x: mp2) {
                mp[x.first] -= mp2[x.first];
                temp2 += score[x.first-'a']*mp2[x.first];
            }
            temp2 += recur(words, mp, score, idx+1);
        }
        
        return max(temp1, temp2);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> mp;
        for(auto ch: letters) {
            mp[ch]++;
        }
        
        int res = recur(words, mp, score, 0);
        return res;
    }
};

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res;
        unordered_map<string, int> mp, mp1;
        
        stringstream ss(s1);
        string word;
        while (ss >> word) {
            mp[word]++;
        }
        stringstream ss1(s2);
        while(ss1 >> word) {
            mp1[word]++;
        }
        
        for(auto wordx: mp) {
            auto word = wordx.first;
            if(mp[word] == 1 && mp1.find(word) == mp1.end()) {
                res.push_back(word);
            }
        }
        
        cout<<endl;
        for(auto wordx: mp1) {
            auto word = wordx.first;
            if(mp1[word] == 1 && mp.find(word) == mp.end()) {
                res.push_back(word);
            }
        }

        return res;
        
    }
};

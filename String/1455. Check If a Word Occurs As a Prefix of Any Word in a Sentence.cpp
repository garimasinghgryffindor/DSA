class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> vec;
        stringstream ss(sentence);
        int x = 0;
        string s;
        while (getline(ss, s, ' ')) {
            vec.push_back(s);
        }
        
        for(int i = 0; i < vec.size(); i++) {
            if(vec[i].find(searchWord) == 0) return i+1;
        }
        return -1;
    }
};

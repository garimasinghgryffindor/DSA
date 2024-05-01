class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);
        
        string first = word.substr(0, idx+1);
        reverse(first.begin(), first.end());
        string second = word.substr(idx+1);
        
        return first + second;
    }
};

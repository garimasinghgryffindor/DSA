class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // approach 1
        string res = "";
        int i = 0, j = 0, n1 = word1.length(), n2 = word2.length();
        while(i < n1 && j < n2) {
            res = res + word1[i++];
            res = res + word2[j++];
        }
        
        res = res + word1.substr(i, n1-i);
        res = res + word2.substr(j, n2-j);
        return res;
    }
};





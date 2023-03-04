struct Node {
    Node * links[26];
    bool flag = false;
};

class Trie {
private:
    Node * root;
    friend bool isCompleteString(string word, Trie trie);
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch - 'a']) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i=0 ; i<word.size() ; i++) {
            char ch = word[i];
            if(!node->links[ch - 'a']) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        
        return node->flag;
    }
    
};

bool isCompleteString(string word, Trie trie) {
    Node * node = trie.root;
    
    for(int i=0 ; i<word.length() ; i++) {
        char ch = word[i];
        if(!node->links[ch - 'a']->flag) {
            return false;
        }
        node = node->links[ch - 'a'];
    }
    
    return node->flag;
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie = Trie();
        for(auto x: words) {
            trie.insert(x);
        }
        
        int maxLen = 0;
        string res;
        for(auto x: words) {
            
            // i.e; is it a complete string
            // by that we mean that is it a word that has all it's prefixes in the dictionary
            if(isCompleteString(x,trie)) {
                // is it the longest so far
                if(x.length() > maxLen) {
                    maxLen = x.length();
                    res = x;
                }
                else if(x.length() == maxLen) {
                    int result = x.compare(res);
                    if(result < 0) {
                        // i.e; is it lexicographically smaller
                        res = x;
                    }
                }
            }
            
        }
        
        return res;
    }
};



Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

Note that the word should be built from left to right with each additional character being added to the end of a previous word. 

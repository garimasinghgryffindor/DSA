struct Node {
    Node* links[26];
    bool flag;
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                // not found
                // so insert
                node->links[ch-'a'] = new Node();
            }
            
            node = node->links[ch-'a'];
        }
        
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            
            if(!node->links[ch-'a']) {
                return false;
            }
            
            node = node->links[ch-'a'];
        }
        return node->flag;
    }
    
    bool isPrefix(string prefix) {
        Node *node = root;
        for(int i=0 ; i<prefix.length() ; i++) {
            char ch = prefix[i];
            
            if(!node->links[ch-'a']) {
                return false;
            }
            
            node = node->links[ch-'a'];
        }
        return true;
    }
};

class Solution {
public:
    Trie trie = Trie();
    
    void helper(string s, string temp, vector<string>&res, int pos) {
        
        if(pos == s.length()) {
            res.push_back(temp);
            return;
        }

        for(int i=pos ; i<s.length() ; i++) {
            string substring = s.substr(pos,i-pos+1);
            
            if(trie.search(substring)) {
                // if found
                // either include it or chk next
                if(pos==0)
                    helper(s,substring,res,i+1);
                else
                    helper(s,temp+" "+substring,res,i+1);
            }
            
            if(!trie.isPrefix(substring)) 
                break;
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        
        for(auto word: wordDict) {
            trie.insert(word);
        }
        
        string temp = "";
        int pos = 0;
        helper(s, temp, res, pos);
        
        return res;
    }
};



Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

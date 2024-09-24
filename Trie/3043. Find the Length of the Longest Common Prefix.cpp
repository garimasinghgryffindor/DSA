struct Node {
    Node* links[10];
    bool flag = false;
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
            if(!node->links[ch-'0']) {
                node->links[ch-'0'] = new Node();
            } 
            node = node->links[ch-'0'];
        }
        node->flag = true;
    }
    
    int search(string word) {
        int cnt = 0;
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'0']) {
                return cnt;
            }
            node = node->links[ch-'0'];
            cnt++;
        }
        return cnt;
    }
    
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0 ; i<prefix.length() ; i++) {
            char ch = prefix[i];
            if(!node->links[ch-'0']) {
                return false;
            }
            node = node->links[ch-'0'];
        }
        return true;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        
        Trie trie;
        
        for(int x: arr1) {
            trie.insert(to_string(x));
        }
        
        for(int y: arr2) {
            res = max(res, trie.search(to_string(y)));
        }
        
        return res;
    }
};

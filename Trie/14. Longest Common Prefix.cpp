struct Node {
    Node * links[27];
    bool flag = false;
};

class Trie {
    public:
    Node * root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node * node = root;
        if(s.empty()) {
            node->links[26] = new Node();
            return;
        }
        
        for(int i = 0; i < s.length(); i++) {
            if(!node->links[s[i]-'a']) {
                node->links[s[i]-'a'] = new Node();
            }
            node = node->links[s[i]-'a'];
        }
        node->flag = true;
    }
    
    Node * retRoot() {
        return root;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // using trie
        
        if(strs.empty()) return "";
        
        Trie trie;
        for(auto x: strs) {
            trie.insert(x);
        }
        
        Node * root = trie.retRoot();
        
        string ans;
        
        while(root) {
            int count = 0;
            int chartr = -1;
            for(int i = 0; i < 27; i++) {
                if(root->links[i]) {
                    count++;
                    chartr = i;
                    if(count > 1) {
                        cout<<endl;
                        return ans;
                    }
                }
            }
            
            if(count == 0) { return ans; }
            if(count == 1) {
                if(chartr == 26) {
                    return "";
                }
                ans.push_back(('a'+chartr));
                root = root->links[chartr];
                if(root->flag) return ans;
            }
        }
        
        cout<<endl;
        return ans;
    }
};

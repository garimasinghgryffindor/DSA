struct Node {
    Node * links[26];
    bool flag = false;
};

class WordDictionary {
public:
    Node * root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            if(!node->links[word[i]-'a'])
                node->links[word[i]-'a'] = new Node();
            
            node = node->links[word[i] - 'a'];
        }
        node->flag = true;
    }
    
    bool searchUtils(string word, Node* node, int pos) {
        if(pos == word.size()) {
            return node->flag;
        }
        
        if(word[pos] != '.') {
            node = node->links[word[pos] - 'a'];
            
            return node && searchUtils(word,node,pos+1);
        } 
        
        for(int i=0 ; i<26 ; i++) {
            if(node->links[i] && searchUtils(word,node->links[i],pos+1))
                return true;
        }
        
        return false;
        
    }
    
    bool search(string word) {
        return searchUtils(word,root,0);
    }
};



Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

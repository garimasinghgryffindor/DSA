struct Node {
    Node* links[26];
    bool flag = false;
};

class MagicDictionary {
public:
    Node * root;
    
    MagicDictionary() {
        root = new Node();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto x: dictionary) {
            Node * node = root;
            for(int i=0 ; i<x.length() ; i++) {
                if(!node->links[x[i]-'a']) {
                    node->links[x[i]-'a'] = new Node();
                }
                node = node->links[x[i]-'a'];
            }
            node->flag = true;
        }
    }
    
    bool searchUtils(string s, int pos, Node*node,bool allowedOnce) {
        if(node==NULL) return false;
        
        for(int i=pos ; i<s.length() ; i++) {
            if(allowedOnce) {
                for(int j=0 ; j<26 ; j++) {
                    if(searchUtils(s,i+1,node->links[j],j+'a'==s[i])) {
                        return true;
                    }
                }
                return false;
            }
            
            if(!node->links[s[i]-'a'])
                return false;
            
            node = node->links[s[i]-'a'];
        }
        
         if(node != NULL && !allowedOnce && node->flag)
            return true;
        
        return false;
    }
    
    bool search(string searchWord) {
        return searchUtils(searchWord,0,root,true);
    }
};




Design a data structure that is initialized with a list of different words. Provided a string, you should determine if you can change exactly one character in this string to match any word in the data structure.

Implement the MagicDictionary class:

MagicDictionary() Initializes the object.
void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.

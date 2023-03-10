struct Node {
    Node * links[26];
    bool flag = false;
};

class MapSum {
public:
    Node * root;
    unordered_map<string,int> mp;
    
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        mp[key] = val;
        Node * node = root;
        for(int i=0 ; i<key.length() ; i++) {
            if(!node->links[key[i]-'a']) {
                node->links[key[i]-'a'] = new Node();
            }
            node = node->links[key[i]-'a'];
        }
        node->flag = true;
    }
    
    void dfs(Node * node, int&res, string s) {
        if(node->flag) {
            res += mp[s];
        }
        
        for(int i=0 ; i<26 ; i++) {
            if(node->links[i]) {
                // if node exists
                // go visit it
                dfs(node->links[i], res, s+(char)(i+97));
            }
        }
    }
    
    int sum(string prefix) {
        int res = 0;
        Node * node = root;
        string s = prefix;
        for(int i=0 ; i<prefix.length() ; i++) {
            if(!node->links[prefix[i]-'a']) {
                return 0;
            }
            node = node->links[prefix[i]-'a'];
        }
        
        dfs(node, res, s);
        return res;
    }
};




Design a map that allows you to do the following:

Maps a string key to a given value.
Returns the sum of the values that have a key with a prefix equal to a given string.
Implement the MapSum class:

MapSum() Initializes the MapSum object.
void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.

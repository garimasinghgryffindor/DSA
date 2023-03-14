struct Node {
    Node * links[27];
    int index;
};

class WordFilter {
public:
    Node * root;
    
    WordFilter(vector<string>& words) {
        root = new Node();
        for(int i=0 ; i<words.size() ; i++) {
            // insert each word in the trie
            // inserting all possible suffixes as well
            int n = words[i].length();
            for(int j=0 ; j<n ; j++) {
                string newWord = words[i].substr(j,n-j) + "{" + words[i];
                Node * node = root;
                for(int k=0 ; k<newWord.length() ; k++) {
                    node->index = i;
                    if(!node->links[newWord[k]-'a'])
                        node->links[newWord[k]-'a'] = new Node();
                    node = node->links[newWord[k]-'a'];
                }
                node->index = i;
            }
        }
    }
    
    int f(string pref, string suff) {
        string s = suff + "{" + pref;
        Node * node = root;
        for(int i=0 ; i<s.length() ; i++) {
            if(!node->links[s[i]-'a']) {
                return -1;
            }
            node = node->links[s[i]-'a'];
        }
        
        return node->index;
    }
};




Design a special dictionary that searches the words in it by a prefix and a suffix.

Implement the WordFilter class:

WordFilter(string[] words) Initializes the object with the words in the dictionary.
f(string pref, string suff) Returns the index of the word in the dictionary, which has the prefix pref and the suffix suff. If there is more than one valid index, return the largest of them. If there is no such word in the dictionary, return -1.

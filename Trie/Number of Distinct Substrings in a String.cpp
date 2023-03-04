struct Node {
    Node* links[26];
    bool flag = false;
};

class Trie {
public:
    Node * root;
    Trie() {
        root = new Node();
    }
    
    int insert(string word) {
        int count = 0;

        Node * node = root;
        for(int i=0 ; i<word.length() ; i++) {
            char ch = word[i];
            if(!node->links[ch-'a']) {
                count++;
                node->links[ch-'a'] = new Node();
            }
            node = node->links[ch-'a'];
        }
        // cout<<count<<"  ";
        
        node->flag = true;
        return count;
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie trie = Trie();

    int count = 0;
    // cout<<"helloo";
    for(int i=0 ; i<s.length() ; i++) {
        for(int j=i ; j<s.length() ; j++) {
            // i.e; all substrings
            int c = trie.insert(s.substr(i,j-i+1));
            count += c;
        }
    }

    return count + 1;
}

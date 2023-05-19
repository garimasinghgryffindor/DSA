#include <bits/stdc++.h> 

struct Node {
    Node * links[26];
    bool flag = false;
};

class Trie {
    public:
    Node * root;

    Trie() {
        root = new Node();
    }

    void insert(string a) {
        Node * node = root;
        for(int i=0 ; i<a.length() ; i++) {
            if(!node->links[a[i]-'a']) {
                node->links[a[i]-'a'] = new Node();
            }
            node = node->links[a[i]-'a'];
        }
        node->flag = true;
    }

    bool search(string a) {
        Node * node = root;
        for(int i=0 ; i<a.length() ; i++) {
            if(!node->links[a[i]-'a'])
                return false;
            node = node->links[a[i]-'a'];
        }

        return node->flag;
    }

    bool isPrefix(string a) {
        Node * node = root;
        for(int i=0 ; i<a.length() ; i++) {
            if(!node->links[a[i]-'a'])
                return false;
            node = node->links[a[i]-'a'];
        }

        return true;
    }
};

void recur(string s,Trie dict,int pos,string temp,vector<string>&res) {
    if(pos == s.length()) {
        res.push_back(temp);
        return;
    }

    int n = s.length();

    for(int i=pos ; i<n ; i++) {
        string substr = s.substr(pos,i-pos+1);
        if(dict.search(substr)) {
            if(pos!=0)
                recur(s,dict,i+1,temp+" "+substr,res);
            else
                recur(s,dict,i+1,substr,res);
        }

        if(!dict.isPrefix(substr)) {
            break;
        }
    }

}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>res;
    Trie dict = Trie();

    // solution
    for(auto s: dictionary) {
        dict.insert(s);
    }
    recur(s,dict,0,"",res);

    return res;
}

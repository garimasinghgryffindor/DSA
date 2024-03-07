class Solution {
public:
    string lcs(string s1, string s2, int n, int m) {
        if(n == 0 || m == 0) return "";
        
        string ans = "";
        if(s1[n-1] == s2[m-1] && n != m) {
            string temp = lcs(s1, s2, n-1, m-1);
            ans = temp + s1[n-1];
        }
        
        string ans1 = lcs(s1, s2, n-1, m);
        string ans2 = lcs(s1, s2, n, m-1);
        if(ans.length() >= ans1.length() && ans.length() >= ans2.length()) return ans;
        if(ans1.length() >= ans.length() && ans1.length() >= ans2.length()) return ans1;
        if(ans2.length() >= ans1.length() && ans2.length() >= ans.length()) return ans2;
        
        return "";
    }
    
    string longestDupSubstring(string s) {
        // approach 1
        // using longest common substring/subarray
        // which is basically by using dp 
        // brute force approach
        // let us try recursion
        int n = s.length();
        return lcs(s, s, n, n);
    }
};


// TABULATION CODE
class Solution {
public:
    vector<vector<int>>dp;
    string longestDupSubstring(string s) {
        // approach 1
        // using longest common substring/subarray
        // which is basically by using dp 
        // brute force approach
        int n = s.length();
        dp.resize(n+1, vector<int>(n+1, 0));
        int ans = 0;
        int end_i = -1, end_j = -1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == s[j-1] && i != j) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                if(dp[i][j] > ans) {
                    ans = dp[i][j];
                    end_i = i;
                    end_j = j;
                }
            }
        }
        
        string res = "";
        while(end_i > 0 && end_j > 0 && dp[end_i][end_j] > 0) {
            res = s[end_i - 1] + res;
            end_i--;
            end_j--;
        }
        
        return res;
    }
};
// MEMORY LIMIT EXCEEDED


// second approach
// using trie + binary search
struct trie {
    trie *links[26];
    bool flag = false;
};

class Trie {
    public:
    trie * root;
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        trie * node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->links[word[i]-'a']) {
                node->links[word[i]-'a'] = new trie();
            }
            node = node->links[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) {
        trie * node = root;
        for(int i = 0; i < word.length(); i++) {
            if(!node->links[word[i]-'a']) return false;
            node = node->links[word[i]-'a'];
        }
        
        return node->flag;
    }
};

class Solution {
public:
    string longestDupSubstring(string s) {
        Trie obj;
        
        int l = 1, r = s.length();
        string ans = "";
        while(l <= r) {
            int mid = l + (r-l)/2;
            bool found = false;
            for(int i = 0; i < s.length()-mid+1; i++) {
                string temp = s.substr(i, mid);
                if(obj.search(temp)) {
                    // found a repeated substring
                    ans = temp;
                    l = mid+1;
                    found = true;
                    break;
                }
                obj.insert(temp);
            }
            
            if(!found) r = mid-1;
        }
        
        return ans;
    }
};
// MEMORY LIMIT EXCEEDED



// approach 3
// sliding window
// rolling hash
// rabin karp
#define p 10000007

class Solution {
public:
    vector<int> roll;

    bool rk(string s, int len, string&temp) {
        unordered_map<int, vector<int> > mp;
        int d = 31;
        int hash = 0;
        
        for(int i = 0; i < len; i++) {
            hash = (hash*d + s[i]-'a')%p;
        }
        mp[hash].push_back(0);

        for(int i = len; i < s.length(); i++) {
            hash = ((hash - (s[i-len]-'a')*roll[len-1])%p + p )%p;
            hash = (hash * d)%p;
            hash = (hash + s[i]-'a')%p;
            
            if(mp.find(hash) != mp.end()) {
                // duplicate value found
                // let's recheck it for collision
                for(auto x: mp[hash]) {
                    string cur = s.substr(x, len);
                    string curr = s.substr(i-len+1, len);
                    if(cur.compare(curr)==0)
                    {
                        temp = curr;
                        return true;
                    }
                }
            }

            mp[hash].push_back(i-len+1);
        }

        return false;
    }
    
    string longestDupSubstring(string s) {
        if(s.length() == 0) return "";
        
        roll.resize(s.length());
        roll[0] = 1;
        for(int i=1; i<s.length(); ++i)
            roll[i] = (31*roll[i-1])%p;
        
        int l = 1, r = s.length();
        string ans = "";
        while(l <= r) {
            int mid = l + (r-l)/2;
            string temp = "";
            
            bool found = rk(s, mid, temp);
            
            if(found) {
                if(temp.size() > ans.size()) {
                    ans = temp;
                }
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return ans;
    }
};








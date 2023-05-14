// BRUTE FORCE - RECURSION

class Solution {
public:
    void permutation(string s,int idx, vector<string>&res) {
        if(idx == s.length()) {
            res.push_back(s);
            return;
        }
        
        for(int i=idx ; i<s.length() ; i++) {
            swap(s[i],s[idx]);
            permutation(s,idx+1,res);
            swap(s[i],s[idx]);
        }
    }
    
    string getPermutation(int n, int k) {
        string s="";
        for(int i=1 ; i<=n ; i++) {
            s.push_back(i+'0');
        }
        
        vector<string>res;
        
        permutation(s,0,res);
        
        sort(res.begin(), res.end());
        
        auto it = res.begin()+(k-1);
        
        return *it;
        
    }
};



// OPTIMAL APPROACH

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>num;
        for(int i=1 ; i<n ; i++) {
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        
        string ans = "";
        
        int k1 = k-1;
        while(true){
            int idx = k1/fact;
            ans+=to_string(num[idx]);
            num.erase(num.begin()+idx);
            if(num.size() == 0)
                break;
            k1 = k1%fact;
            fact = fact/num.size();
        }
        
        return ans;
        
    }
};

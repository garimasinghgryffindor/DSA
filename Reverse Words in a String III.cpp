class Solution {
public:
  
    string reverseWords(string s) {
        string res="";
        int f=0;
        int l=0 , r=0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]==' '){
                f=1;
                r=i-1;
                string x = s.substr(l,r-l+1);
                reverse(x.begin() , x.end());
                res+=x+' ';
                l=i+1;
            }
        }
        if(f==0){
            reverse(s.begin() , s.end());
            return s;
        }
        string x = s.substr(l,r-l+1);
        reverse(x.begin() , x.end());
        res+=x;
        return res;
    }
};


// LEETCODE 557 

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

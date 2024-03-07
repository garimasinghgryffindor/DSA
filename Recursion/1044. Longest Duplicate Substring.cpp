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

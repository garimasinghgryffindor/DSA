class Solution {
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        int n = s.length();
        int k = p.length();
        if (n < k) {
            return ans;
        }

        unordered_map<char,int> freqOfLettersInAnag;
        
        for(char x: p) {
            freqOfLettersInAnag[x]++;
        }
        
        int l = 0, r = 0, count = freqOfLettersInAnag.size();
        while(r < n) {
            if(freqOfLettersInAnag.find(s[r]) != freqOfLettersInAnag.end()) {
                freqOfLettersInAnag[s[r]]--;
                if(freqOfLettersInAnag[s[r]] == 0)
                    count--;
            }
            
            if(r-l+1 < k) {
                r++;
            } else if(r-l+1 == k) {
                if(count == 0) {
                    ans.push_back(l);
                }
                
                if(freqOfLettersInAnag.find(s[l]) != freqOfLettersInAnag.end()) {
                    freqOfLettersInAnag[s[l]]++;
                    if(freqOfLettersInAnag[s[l]] == 1) {
                        count++;
                    }
                }
                l++;
                r++;
            }
        }
        
        return ans;
    }
};





// You are given a string s and a positive integer k.

// Let vowels and consonants be the number of vowels and consonants in a string.

// A string is beautiful if:

// vowels == consonants.
// (vowels * consonants) % k == 0, in other terms the multiplication of vowels and consonants is divisible by k.
// Return the number of non-empty beautiful substrings in the given string s.

// A substring is a contiguous sequence of characters in a string.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

// Consonant letters in English are every letter except vowels.

// USING PREFIX SUM

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int res = 0;
        int n = s.length();
        vector<pair<int,int>> prefix(n+1);
        prefix[0] = {0, 0};
        
        int vowels = 0, cons = 0;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                vowels++;
            } else {
                cons++;
            }
            prefix[i+1] = {vowels, cons};
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int v = prefix[j+1].first - prefix[i].first, c = prefix[j+1].second - prefix[i].second;
                
                if(v == c) {
                    if((v*c)%k == 0) res++;
                }
            }
        }
        
        return res;
    }
};

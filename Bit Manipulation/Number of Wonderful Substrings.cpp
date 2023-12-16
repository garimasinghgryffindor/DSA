class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int len = word.length();
        int bit = 0;
        for(int i = 0; i < len; i++) {
            
            // this is for even occurences
            // if all the letters are repeated even number of times
            // then qualifies as a wonderful substring
            bit = bit^(1<<(word[i]-'a'));
            ans = ans+mp[bit];
            
            // checking for 1 odd - lengthed character repetition
            // just try removing any character and see if another similar substring persists
            for(int j = 0; j < 10; j++) {
                ans = ans + mp[bit ^ (1<<j)];
            }
            mp[bit]++;
        }
        return ans;
    }
};

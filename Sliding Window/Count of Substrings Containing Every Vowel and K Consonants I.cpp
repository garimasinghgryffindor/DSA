class Solution {
public:
    set<char> vowels { 'a', 'e', 'i', 'o', 'u' };
    bool containsAllVowels(map<char, int>& freq) {
        for (const char& c : vowels)
            if (freq[c] == 0)
                return false;
        return true;
    }

    int countOfSubstrings(string word, int k) {
        int res = 0;
        map<char, int> mp;
        int l = 0, cons = 0, n = word.length(), start = 0;

        for(int r = 0; r < n; r++) {
            
            if(vowels.contains(word[r]))
                mp[word[r]]++;
            else
                cons++;

            while(cons > k) {
                if(vowels.contains(word[l]))
                    mp[word[l]]--;
                else 
                    cons--;
                start = ++l;
            }


            while(mp[word[l]] > 1 && vowels.contains(word[l]) )
                mp[word[l++]]--;

            if(containsAllVowels(mp) && cons == k) {
                res++;
                res += l - start;
            }

        }

        return res;
    }
};



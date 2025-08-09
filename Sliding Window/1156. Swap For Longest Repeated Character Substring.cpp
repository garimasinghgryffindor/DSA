class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> total(26, 0);
        for (char c : text) total[c - 'a']++;

        int n = text.size();
        vector<pair<char,int>> groups;
        
        // Step 1: group consecutive characters
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && text[j] == text[i]) j++;
            groups.push_back({text[i], j - i});
            i = j;
        }

        int res = 0;

        // Step 2: max length within each group (possibly +1 if spare char exists)
        for (auto &g : groups) {
            res = max(res, min(g.second + 1, total[g.first - 'a']));
        }

        // Step 3: check for merge with one-char gap
        for (int i = 0; i + 2 < (int)groups.size(); i++) {
            if (groups[i].first == groups[i + 2].first && groups[i + 1].second == 1) {
                int merged = groups[i].second + groups[i + 2].second;
                if (total[groups[i].first - 'a'] > merged) merged++; // use spare char
                res = max(res, merged);
            }
        }

        return res;
    }
};


// better code

class Solution {
public:
    int maximumLengthSubstring(string s) 
    {
        unordered_map<char, int> unmap;
        int maxLength = 0, left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            unmap[s[right]]++;
            while (unmap[s[right]] > 2)
            {
                unmap[s[left]]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

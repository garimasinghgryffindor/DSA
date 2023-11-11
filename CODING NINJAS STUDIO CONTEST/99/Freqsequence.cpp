string findFreqsequence(const std::string& s) {
    std::unordered_map<char, int> mp;
    int mx = 0;
    std::unordered_set<char> maxFreqChars;

    std::string res;
    for (char x : s) {
        int count = ++mp[x];
        if (count > mx) {
            mx = count;
            maxFreqChars.clear();
            maxFreqChars.insert(x);
        } else if (count == mx) {
            maxFreqChars.insert(x);
        }
    }

    for (char x : s) {
        if (maxFreqChars.count(x) > 0) {
            res.push_back(x);
        }
    }

    return res;
}





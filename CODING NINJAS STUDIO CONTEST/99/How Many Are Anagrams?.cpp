vector<int> howManyAreAnagrams(int n, int m, vector<string>& a, vector<string>& b) {
    vector<int>res(m, 0);

    unordered_map<string, int> mp;

    for(auto x: a) {
        string str = x;
        sort(str.begin(), str.end());
        mp[str]++;
    }

    for(int i = 0; i < m; i++) {
        string curr = b[i];
        sort(curr.begin(), curr.end());

        if(mp.find(curr) != mp.end()) {
            res[i] = mp[curr];
        }
    }

    return res;
}

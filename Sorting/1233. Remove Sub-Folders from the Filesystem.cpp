class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>res;
        sort(folder.begin(), folder.end());
        int last = 0;
        while(last < folder.size()) {
            res.push_back(folder[last]);
            int temp = last;
            last++;
            while(last < folder.size()) {
                int len = folder[temp].length();
                string t = folder[last].substr(0, len);
                if(t == folder[temp] && folder[last][len] == '/') {
                    last++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimumDeletions(string word, int k) {
        int res = INT_MAX;
        int curr = 0;
        int prev_sum = 0;
        unordered_map<char,int>mp;
        for(auto x: word) {
            mp[x]++;
        }
        vector<int>vec;
        for(auto x: mp) {
            vec.push_back(x.second);
        }
        sort(vec.begin(), vec.end());   

        for(int i = 0; i < vec.size(); i++) {
            int mn = vec[i];
            int mx = mn + k;
            curr = prev_sum;
            // cout<<"curr initially   ->>>   "<<curr<<endl;
            for(int j = i+1; j < vec.size(); j++) {
                curr += (vec[j]) - min( (vec[j]), mx );
            }
            // cout<<curr<<" <=---  curr afterwards\n";  
            res = min(res, curr);
            prev_sum += vec[i];
            // cout<<"prev sum now ---->>    "<<prev_sum<<endl;
        }

        return res;
    }
};


// 146
// 

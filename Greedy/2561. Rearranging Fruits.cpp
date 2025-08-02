class Solution {
public:

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int>b1;
        map<int,int>b2;
        map<int,int>b;
        int n = basket1.size();
        long long cost = 0;
        int global_minimum = INT_MAX; 
        for(int i = 0; i < n; i++) {
            b1[basket1[i]]++;
            b2[basket2[i]]++;
            b[basket1[i]]++;
            b[basket2[i]]++;
            global_minimum = min(global_minimum, basket1[i]);
            global_minimum = min(global_minimum, basket2[i]);
        }

        for(auto x: b) {
            // if odd count of any element, then definitely impossible
            if(x.second%2 == 1) return -1;
        }

        vector<int>diff1;
        vector<int>diff2;
        for(auto x: b) {
            int key = x.first;
            int ideal_freq_in_both = x.second/2;
            if(b1[key] > ideal_freq_in_both) {
                for(int i = 0; i < b1[key]-ideal_freq_in_both; i++) {
                    diff1.push_back(key);
                }
            }

            if(b2[key] > ideal_freq_in_both) {
                for(int i = 0; i < b2[key]-ideal_freq_in_both; i++) {
                    diff2.push_back(key);
                }
            }
        }

        sort(diff1.begin(), diff1.end()); // sort ascending
        sort(diff2.rbegin(), diff2.rend()); // sort descending

        for(int i = 0; i < diff1.size(); i++) {
            cost += min((long long)min(diff1[i], diff2[i]), (long long) global_minimum*2);
        }

        return cost;
    }
};

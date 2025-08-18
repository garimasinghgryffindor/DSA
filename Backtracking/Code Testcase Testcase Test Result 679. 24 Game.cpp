class Solution {
public:
    unordered_set<double> calculate(double a, double b) {
        unordered_set<double>res;
        res.insert(a+b);
        res.insert(a-b);
        res.insert(b-a);
        res.insert(a*b);
        if(a > 1e-6) res.insert(b/a);
        if(b > 1e-6) res.insert(a/b);
        return res;
    }

    bool backtrack(vector<double> cards) {
        if(cards.size() == 1) {
            if( fabs(cards[0] - 24.0) < 1e-6) return true;
            return false;
        }

        int n = cards.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                vector<double>newCards;
                for(int k = 0; k < n; k++) {
                    if(k!=i && k!=j) {
                        newCards.push_back(cards[k]);
                    }
                }

                for(auto x: calculate(cards[i], cards[j])) {
                    newCards.push_back(x);
                    if(backtrack(newCards)) return true;
                    newCards.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double>cards2(cards.begin(), cards.end());
        return backtrack(cards2);
    }
};

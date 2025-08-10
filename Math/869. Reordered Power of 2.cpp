class Solution {
public:
    void helper(map<int,int>&mp, int num) {
        while(num) {
            int s = num%10;
            mp[s]++;
            num/=10;
        }
    }

    bool reorderedPowerOf2(int n) {
        map<int,int> mp;
        helper(mp, n);

        for(int i = 0; i <= 30; i++) {
            int x = pow(2, i);
            map<int,int>mp2;
            helper(mp2, x);

            if(mp.size() != mp2.size()) continue;
            bool correct = true;
            for(auto x: mp) {
                if(mp2.find(x.first) == mp2.end()) {
                    correct = false;
                    break;
                }
                if(x.second != mp2[x.first]) {
                    correct = false;
                    break;
                }
            }

            if(correct) return true;

        }

        return false;
    }
};

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int res = 0, l = 0, r = people.size()-1;
        sort(people.begin(), people.end());
        
        while(l < r) {
            if(people[l] + people[r] <= limit) {
                res++;
                l++;
                r--;
            } else {
                res++;
                r--;
            }
        }
        if(l == r) res++;
        return res;
    }
};

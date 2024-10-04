class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        sort(skill.begin(), skill.end());
        int sm = skill[0] + skill[skill.size()-1];
        res += ((long long)skill[0] * skill[skill.size()-1]);
        for(int i = 1; i < skill.size()/2; i++) {
            if(skill[i] + skill[skill.size()-i-1] != sm) return -1;
            res += ((long long)skill[i] * skill[skill.size()-i-1]);
        }
        return res;
    }
};

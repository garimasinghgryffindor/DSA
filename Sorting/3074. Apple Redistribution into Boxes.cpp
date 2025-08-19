class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int x: apple) {
            sum += x;
        }

        sort(capacity.rbegin(), capacity.rend());

        int sm2 = 0;
        for(int i = 0; i < capacity.size(); i++) {
            sm2 += capacity[i];
            if(sm2 >= sum) return i+1; 
        }

        return -1;
    }
};

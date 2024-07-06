class Solution {
public:
    int passThePillow(int n, int time) {
        int interval = n-1;
        int turn = time/interval;
        
        if(turn%2 == 0) {
            int rem = time%(interval);
            return 1+rem;
        } else {
            int rem = time%(interval);
            return n-rem;
        }
    }
};

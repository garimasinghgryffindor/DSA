class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int temp = tickets[k];
        int n = tickets.size();
        for(int i = 0; i < n; i++) {
            if(tickets[i] <= temp) {
                res += tickets[i];
            } else {
                res += temp;
            }
            
            if(i > k && tickets[i] >= temp) {
                res--;
            }
        }
        
        return res;
    }
};

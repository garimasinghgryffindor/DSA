
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long> >pq;
        for(int x: nums) {
            pq.push(x);
        }
        
        int count = 0;
        while(pq.top() < k) {
            long first = pq.top();   pq.pop();
            long sec = pq.top();     pq.pop();
            pq.push(min(first, sec)*2 + max(first, sec));
            count++;
        }
        
        return count;
    }
};

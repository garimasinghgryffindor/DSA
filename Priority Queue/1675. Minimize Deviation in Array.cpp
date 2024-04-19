class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minDev = INT_MAX;
        int min_ = INT_MAX;
        priority_queue<int>pq;
        
        for(int x: nums) {
            x = x%2 ? x*2 : x;
            pq.push(x);
            min_ = min(min_, x);
        }
        
        while(pq.top()%2 == 0) {
            // by the time the top most element of priority queue is even
            minDev = min(minDev, pq.top() - min_);
            min_ = min(min_, pq.top()/2);
            int tp = pq.top();  pq.pop();
            pq.push(tp/2);
        }
        
        minDev = min(minDev, pq.top() - min_);
        return minDev;
    }
};


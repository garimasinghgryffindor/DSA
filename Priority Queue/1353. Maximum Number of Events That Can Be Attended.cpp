// BRUTE FORCE + SORTING

// class Solution {
// public:
//     static bool compare(vector<int>&a, vector<int>&b) {
//         if(a[1] == b[1]) return a[0] < b[0];
//         return a[1] < b[1];
//     }
    
//     int maxEvents(vector<vector<int>>& events) {
//         int n = events.size();
//         sort(events.begin(), events.end(), compare);
        
//         int maxTime = events[n-1][1];
//         vector<bool>slots(maxTime, false);
        
//         int res = 0;
//         int lastSlot = -1;
//         for(int i = 0; i < n; i++) {
//             for(int j = max(lastSlot+1, events[i][0]); j <= events[i][1]; j++) {
//                 if(!slots[j]) {
//                     res++;
//                     slots[j] = true;
//                     break;
//                 }
//             }
//         }
        
//         return res;
//     }
// };



class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        int res = 0;
        
        int i = 0;
        for(int d = 1; d <= 100000; d++) {
            
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            
            while(i < n && events[i][0] == d) {
                pq.push(events[i][1]); i++;
            }
            
            if(!pq.empty()) {
                res++;
                pq.pop();
            }
            
            if(pq.empty() && i == n) return res;
        }
    
        return res;
    }
};





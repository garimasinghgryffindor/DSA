class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> vec(26,0);
        int maxm = 0, maxElementCount=0;
        for(int i=0 ; i<tasks.size() ; i++) {
            vec[tasks[i]-65]++;
        }
        
        for(auto x: vec) {
            maxm = max(maxm, x);
        }
        
        for(auto x: vec) {
            if(x == maxm) {
                maxElementCount++;
            }
        }
        
        return max(len, (maxm-1)*(n+1) + maxElementCount);
    }
};


// LEETCODE 621

// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

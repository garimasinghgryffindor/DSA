class Solution {
public:
    // int max(int&a , int &b)
    // {
    //     if(a>b)
    //         return a;
    //     return b;
    // }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end() );
        vector<vector<int> > res;
        
        res.push_back(intervals[0]);
        
        for(int i=1 ; i<intervals.size() ; i++)
        {
            if(intervals[i][0]>res.back()[1])
            {
                res.push_back(intervals[i]);
            } else
            {
                res.back()[1] = max(res.back()[1] , intervals[i][1]);
            }
        }
        
        return res;
    }
};




LEETCODE 56
  
  
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



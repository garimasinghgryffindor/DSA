#include <bits/stdc++.h> 
bool static compare(pair<int,pair<int,int>> &m1, pair<int,pair<int,int>>& m2) {
         if (m1.first < m2.first) return true;
         else if (m1.first > m2.first) return false;
         else if (m1.second.second < m2.second.second) return true;
         return false;
      }

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int,pair<int,int>>> meetings;
    int n = start.size();
    for(int i=0 ; i<n ; i++) {
      meetings.push_back({end[i], {start[i], i+1}});
    }

    sort(meetings.begin(), meetings.end(),compare);

    int count = 0;
    vector<int>res;
    int currentEnd = -1;
    for(int i=0 ; i<n ; i++) {
        if(meetings[i].second.first > currentEnd) {
            count++;
            currentEnd = meetings[i].first;
            res.push_back(meetings[i].second.second);
        }
    }

    return res;
}

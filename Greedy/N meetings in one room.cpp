static bool compare(pair<int,int>&a,pair<int,int>&b) {
    if(a.second < b.second) 
        return true;
    if(a.second > b.second)
        return false;
    if(a.first < b.first)
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<pair<int,int>> activity;
    int n = start.size();
    for(int i=0 ; i<n ; i++) {
        activity.push_back({start[i], finish[i]});
    }

    sort(activity.begin(), activity.end(), compare);

    int currentEnd = -1;
    int count = 0;

    for(int i=0 ; i<n ; i++) {
        if(activity[i].first >= currentEnd) {
            count++;
            currentEnd = activity[i].second;
        }
    }

    return count;
}

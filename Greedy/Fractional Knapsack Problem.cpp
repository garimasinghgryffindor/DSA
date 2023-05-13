static bool compare(pair<int,int>&a,pair<int,int>&b) {
    double r1 = (double)a.second/a.first;
    double r2 = (double)b.second/b.first;

    return r1 > r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // ITEMS contains {weight, value} pairs.
    
    sort(items.begin(),items.end(), compare);

    double res = 0;
    int capacityLeft = w;

    for(auto x: items) {
        if(x.first <= capacityLeft) {
            // take the item as whole
            capacityLeft -= x.first;
            res += x.second;
            if(capacityLeft == 0)
                break;
        } else {
            // take whatsover fraction of the item is possible
            res += capacityLeft*((double)x.second/x.first);
            capacityLeft = 0;
            break;
        }
    }

    return res;
}

#include <bits/stdc++.h>

int countLessThanMid(vector<int>num , int mid) {
    int l = 0 ,h = num.size()-1;
    while(l<=h) {
        int md = l + (h-l)/2;
        if(num[md] <= mid) {
            l = md + 1;
        } else {
            h = md - 1;
        }
    }

    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Binary Search
    int low = 1;
    int high = 1e9;
    int r = matrix.size();
    int c = matrix[0].size();

    while(low <= high) {
        int mid = low + (high - low)/2;
        int cnt = 0;
        for(int i=0 ; i<r ; i++) {
            cnt += countLessThanMid(matrix[i],mid);
        }
        
        if(cnt <= r*c/2) {
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }

    return low;

}

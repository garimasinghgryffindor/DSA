#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>vec;

int merge(int l, int mid, int r) {
    int res = 0;
    int i = l, j = mid+1, k = l;
    vector<int>temp(vec.size());

    while(i <= mid && j <= r) {
        if(vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
            res+=mid-i+1;
        }
    }

    while(i <= mid) {
        temp[k++] = vec[i++];
    }

    while(j <= r) {
        temp[k++] = vec[j++];
    }

    for(int i=l ; i <= r ; i++) {
        vec[i] = temp[i];
    }

    return res;
}

int mergeSort(int l, int r) {
    int ans = 0;
    if(l < r) {
        int mid = l + (r-l)/2;
        ans += mergeSort(l, mid);
        ans += mergeSort(mid+1, r);
        ans += merge(l, mid, r);
    }
    return ans;
}

int main()
{
    int t;  cin>>t;

    while(t--) {
        int n;  cin>>n;
        vector<string>yoda(n), normal(n);
        unordered_map<string, int> mp;
        for(int i = 0; i < n; i++) {
            cin>>yoda[i];
        }
        for(int i = 0; i < n; i++) {
            cin>>normal[i];
            mp[normal[i]] = i;
        }

        //vector<int> vec(n);
        vec.resize(n);

        for(int i = 0; i < n; i++) {
            int idx = mp[yoda[i]];
            vec[i] = idx;
        }

        int ans = mergeSort(0, n-1);
        cout<<ans<<endl;
    }

    return 0;
}

There is an infinite grid. You are given N points on it. 2 points are said to be connected if the manhattan distance between them is equal to 1. If two points are not connected you can connect by air-pathways i.e. you can take a flight from one point to the other. The cost of an airpathway is the euclidean distance between the 2 points.

If there are three points A, B and C, Let's say points A & B are connected (by land or by air), B & C are connected (by land or by air) then by transitivity A & C are also connected. You have to connect all points in the same time minimizing the cost.

Input format
First line T, the no. of test cases
First line of each test case contains N
Then N lines follow where ith line contains the x and y coordinates of the ith point

Output format
For each test case output in a single line the minimum cost with 6 decimal places

Constraints
1<=T<=10
1<=N<=500
1<=x<=10^6
1<=y<=10^6

Sample test case

Input
1
3
1 1
2 2
3 2

output
1.414214


// Solution
  /////////////////////////////////////
  /////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

int find(int u, int parent[]){
    if(u!=parent[u])parent[u] = find(parent[u], parent);
    return parent[u];
}

void merge(int x, int y, int rank[], int parent[]){
    x = find(x, parent), y = find(y, parent);
    if(rank[x] > rank[y])parent[y] = x;
    else parent[x] = y;
        if (rank[x] == rank[y])rank[y]++;
    }
    double kruskal(vector<pair<double, pair<int, int> > >&edge, int n){
        double m=0;
        int parent[n], rank[n];
        for(int i=0; i<n; i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(int i=0; i<edge.size();i++){
            int u=edge[i].second.first;
            int v=edge[i].second.second;
            int set_u = find(u, parent);
            int set_v = find(v, parent);
            if(set_u != set_v){
            m+=edge[i].first;
            merge(set_u, set_v, rank, parent);
        }
    }
    return m;
}

int main(){
    int n, t, x, y;
    cin >> t;
    while(t--){
        cin >> n;
        vector<pair<int, int> >v(n);
        double mat[n][n];
        for(int i=0; i<n; i++){
            cin >> x >> y;
            v[i].first = x;
            v[i].second = y;
        }
        vector<pair<double, pair<int, int> > >edge;
        for(int i=0; i<n; i++){ 
            for(int j=i+1; j<n; j++){
                if(abs(v[i].first - v[j].first) + abs(v[i].second-v[j].second) == 1){
                    edge.push_back({0, {i,j}});
                }
                else {
                    double x=v[i].first-v[j].first, y=v[i].second-v[j].second;
                    double z=sqrt(pow(x,2) + pow(y,2));
                    edge.push_back({z, {i, j}});
                }
            }
        }
        sort(edge.begin(), edge.end());
        double minimumCost = kruskal(edge, n);
        cout<<fixed << setprecision(6)<<minimumCost<<"\n";
    }
    return 0;
}

#include <iostream>
#include <queue>
#include <climits> 

using namespace std;

int bfs01(vector<pair<int,int>> graph[],int N) {
    vector<int> weights(N+1,INT_MAX);
    weights[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int i=0 ; i<graph[node].size() ; i++) {
            int x = graph[node][i].first;
            int w = graph[node][i].second;
            if(weights[x] > weights[node] + w) {
                weights[x] = weights[node] + w;
                q.push(x);
            }
        }
    }
    	
    return weights[N]==INT_MAX ? -1 : weights[N];
}

int main() {
	// your code goes here
	int N,M;
	cin>>N>>M;
	vector<pair<int,int>> graph[N+1];
	for(int i=0 ; i<M ; i++) {
	    int x,y;
	    cin>>x>>y;
	    if(x == y) continue;
		// if edge exists the weight = 0
	    graph[x].push_back({y,0});
		// otherwise a reverse edge is required so weight = 1
		// check the notebook for god sake
	    graph[y].push_back({x,1});
	}
	
	int count = bfs01(graph,N);
	cout<<count;
	
	return 0;
}



CODECHEF

Sometimes mysteries happen. Chef found a directed graph with N vertices and M edges in his kitchen!

The evening was boring and chef has nothing else to do, so to entertain himself, Chef thought about a question "What is the minimum number of edges he needs to reverse in order to have at least one path from vertex 1 to vertex N, where the vertices are numbered from 1 to N.
  
  

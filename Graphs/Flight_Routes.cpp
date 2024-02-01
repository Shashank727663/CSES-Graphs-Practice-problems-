#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>>adj;
long long int n , m ,k;
vector<vector<long   long int>>dist;
void dijkstra() {
    	priority_queue <
	  pair<long long int,long long int>, 
	  vector<pair<long long int ,long long int >>, 
	  greater<pair<long long int ,long long int >>
	> pq; 
 
    pq.push({0,1});
    // dist , node
 
    while(!pq.empty()) {
       long long int  u = pq.top().second;
       long long int  d = pq.top().first;
        pq.pop();
 
        if(dist[u][k-1] < d) {
            continue;
        }
 
 
        for(auto x : adj[u]) {
            long long int v = x.first;
            long long int c = x.second;
            if(dist[v][k-1] > c + d) {
             dist[v][k-1] = c + d;
             pq.push({dist[v][k-1],v});
             sort(dist[v].begin(), dist[v].end());
            }
        }
    }
}
 
 
int main() {
    cin>>n>>m>>k;
    adj.resize(n+1);
    dist.resize(n+1);
    for(long long int i = 1 ;i <= n ;i++) {
        dist[i].resize(k);
        for(long long int j = 0 ; j < k; j++ ) {
            dist[i][j] = 1e17;
        }
    }
 
    dist[1][0] = 0;
    for(long long int i = 0 ; i < m ;i++) {
        long long int u ,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
 
 
    dijkstra();
    for(long long int  i = 0; i < k; ++i)
	{
		cout << dist[n][i] << " ";
	}
}

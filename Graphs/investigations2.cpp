#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;


const long long int INF = 1e17;
const long long int modb = 1e9+7;
const long long int MAXN = 1e5+1;
long long int n , m;

vector<vector<pair<int,int>>> adj(MAXN);
vector<long long int>cost(MAXN);
vector<long long int>route(MAXN);
vector<long long int>min_flights(MAXN);
vector<long long int>max_flights(MAXN);


void dijkstra() {
    priority_queue< pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>> > pq;
	pq.push({0,1});
	cost[1] = 0;
	route[1] = 1;

    while(!pq.empty()) {
        long long int node = pq.top().second;
        long long int d = pq.top().first;
        pq.pop();
        if( d > cost[node]) {
            continue;
        }

        for(auto x  :adj[node]) {
            long long int v = x.first;
            long long int w = x.second;
            if(w + d > cost[v]) {
                continue;
            }


            if( w + d == cost[v]) {
                route[v] += route[node];
                route[v] %= modb;
                min_flights[v] = min(min_flights[node] + 1 , min_flights[v]);
                max_flights[v] = max(max_flights[node] + 1 , max_flights[v]);
            }
            // relaxation 
            if( w + d < cost[v]) {
                cost[v] = w + d;
                route[v] = route[node];
				min_flights[v] = min_flights[node]+1;
				max_flights[v] = max_flights[node]+1;
				pq.push({cost[v],v});
            }
        }
        }
}

int main() {
    cin>>n>>m;
    // constructing the adj list
    for(int i = 0 ; i < m ; i++) {
       long long int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    	for(int i = 2; i <= n; ++i)
	{
		cost[i] = INF;
	}

    dijkstra();
    cout << cost[n] <<" " <<route[n] <<" "<<min_flights[n] <<" "<<max_flights[n] << endl;
}
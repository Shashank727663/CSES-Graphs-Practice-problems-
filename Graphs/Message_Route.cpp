#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
    long long int n , m;
    cin>>n>>m;
    vector<vector<long long int>>adj(n+1);
    // 1 --> creating a adj node
    for(int i = 0 ; i < m ; i++) {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 2 --> bfs trev with tracking the parent 
    // Create a priority queue for storing the nodes along with distances 
    // in the form of a pair { dist, node }.
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int,long long int>>> pq;
    vector<long long int>dist(n+1,1e9);
    vector<long long int>parent(n+1);
    for(int i = 0 ; i <= n ; i++) {
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({ 0 , 1 });

    while (!pq.empty()) {
    long long int dis = pq.top().first;
    long long int node = pq.top().second;
    pq.pop();
    for (auto x : adj[node]) {
        long long int wt = 1;  // Assuming unit weight for simplicity
        if (dist[x] > dis + wt) {  // Use dis instead of dist[node]
            dist[x] = dis + wt;
            pq.push({dist[x], x});
            parent[x] = node;
        }
    }
}


    if(dist[n] == 1e9) {
        cout<<"IMPOSSIBLE";
        return 0;
    }


    vector<long long int>path;
    int node = n;

    while(parent[node] != node ) {
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1);
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto x : path) {
        cout<<x<<" ";
    }

}




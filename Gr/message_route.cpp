#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;

lli  n , m;
int main() {
    cin >> n >> m;
    vector<vector<lli>>adj(n+1);
vector<lli >vis(n+1,0);

        vector<lli>parent( n  + 1);
    for(int i = 0 ; i <= n ;i++){
        parent[i]=i;
    }

    vector<lli>distance( n + 1, 1e9);
    for(lli i = 0 ; i < m ; i ++ ) {
        lli u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int,long long int>>> pq;
    pq.push( { 0 , 1});
    // dist , node

    distance[1] = 0;

    while(!pq.empty()) {
        lli node = pq.top().second;
        lli dist = pq.top().first;
        pq.pop();
        for(auto x : adj[node]) {
            lli nd  = dist + 1;
            if(distance[x] > nd) {
                distance[x] = nd;
                pq.push( { nd  ,x});
                parent[x] = node;
            }
        }
    }

     if(distance[n] == 1e9) {
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
   }
 
   vector<long long int>path;
   int node = n;
       while(parent[node] != node ) {
        path.push_back(node);
        node = parent[node];
    }

   path.push_back(1);
   reverse(path.begin() , path.end());
   cout<<path.size() <<endl;
   for(auto x : path) {
    cout<<x<<" ";
   }

  




}








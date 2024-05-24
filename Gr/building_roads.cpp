#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
vector<int>roads;

// dfs 
int cc = 0;
 int n , m;
void dfs(int src) {
    vis[src] = 1;
    for(auto x : adj[src]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}



void Connected_Components() {
    for(int i = 1; i <= n ; i++) {
        if(!vis[i]) {
            cc++;
            roads.push_back(i);
            dfs(i);
        }
    }
}
int main() {

    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n + 1,0);

    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Connected_Components();
    cout << cc - 1 << endl; 
    if(cc > 1) {
      int u = roads[0];
      int v;
      for(int i = 1;  i < cc ; i++) {
      
             v = roads[i];
            cout << u << " " << v;
            cout<<endl;
            u = v;
        
      }

    }



}
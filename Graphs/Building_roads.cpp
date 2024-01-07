#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;

int n , m;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>roads;
int cc = 0;

void dfs(int u) {
    vis[u] = true;
    for(auto x :adj[u]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}

void Connected_Components() {
    for(int i = 1 ; i <=n;i++) {
        if(!vis[i]) {
            cc++;
            roads.push_back(i);
            dfs(i);

        }
    }
}
int main() {
    cin>>n>>m;
    adj.resize(n+1);
    vis.resize(n+1,false);
    for(auto i = 0 ; i < m ; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // no of roads to be connected
    Connected_Components();
    cout<<cc - 1 <<endl;
    if(cc>1) {
        int u = roads[0];
        int v;
        for(auto i = 1;i<cc;i++) {
            v = roads[i];
            cout<<u<<" "<<v<<endl;
            u = v;
        }
    }
}
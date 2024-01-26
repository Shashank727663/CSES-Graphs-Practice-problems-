#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli ;


lli n , m;
vector<vector<lli>>adj;
vector<lli>vis;
void dfs(int src) {
    vis[src] = 1;

    for(auto x : adj[src]) {
        if(!vis[x]) {
            dfs(x);
        }
    }
}

int ans = 0;

void Connected_Components() {
    for(int i = 0 ; i < n ;i++) {
        if(!vis[i]) {
            ans++;
            dfs(i);

        }
    }
}
int main() {
    lli  t;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        adj.resize(n + 1);
        vis.resize(n+1,0);
        for(int i = 0  ;i < m ; i++) {
            int u , v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Connected_Components();
        cout<<ans - 1<<endl;

      
    }
}
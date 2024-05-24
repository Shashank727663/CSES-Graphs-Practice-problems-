#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;
vector<vector<int>>adj;
vector<int>vis;
vector<int>parent;
lli sv , ev;
bool dfs(int src,int par) {
    vis[src] = 1;
    parent[src] = par;

    for(auto x : adj[src]) {
        if(!vis[x]) {
            if(dfs(x,src)){
                return true;
            }
        }else if(x != par) {
            sv = x;
            ev = src;
            return true;
        }
    }

    return false;
}

int main() {
    int n , m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.resize(n+1 , 0);
    parent.resize(n+1,-1);

    for(int i = 0 ; i < m ; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i = 1 ; i <= n;i++){
        if(!vis[i]) {
            if(dfs(i , -1) ) {
                cycle = true;
                break;
            }
        }
    }


    if(cycle == false) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }


    vector<int>ans;
    int tv = ev;
    ans.push_back(ev);
    while(tv != sv) {
        ans.push_back(parent[tv]);
        tv = parent[tv];
    }
    ans.push_back(ev);
    cout << ans.size() << endl;
    for(auto  x : ans){
        cout <<x<<" ";
    }

}
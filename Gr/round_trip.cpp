#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;
long long int sv , ev;
vector<lli>par;
bool dfs(int src ,int parent,  vector<vector<int>>&adj , vector<int>&vis) {
    vis[src] = 1;
    par[src] = parent;
    for(auto x : adj[src]) {
        if(!vis[x]) {
            if(dfs(x,src , adj,vis) == true) {
            return true;
        }
        }else if(x != parent) {
            sv  = x ; 
            ev = src;
            return true;
        }
    }
    return false;
}


int main() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    vector<int>vis(n+1 , 0);
    par.resize(n + 1, -1);
    for(int i = 0  ; i < m ;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i = 1; i<= n ; i++) {
        if(!vis[i]) {
            if(dfs(i , - 1, adj,vis)) {
                cycle = true;
                break;
            }
        }
    }


    if(cycle == false) {
        cout <<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int tv = ev;
    vector<int>ans;

    

    ans.push_back(ev);
    while(tv != sv) {
        ans.push_back(par[tv]);
        tv = par[tv];
    }
    ans.push_back(ev);
        cout<<ans.size()<<endl;
    for(auto x : ans){
        cout<<x<<" ";
    }


}
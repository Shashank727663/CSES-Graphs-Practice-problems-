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
vector<vector<int>>paths;
lli sv , ev;

void dfs(int src , vector<int>&ans) {
    vis[src] = 1;
    ans.push_back(src);
    for(auto x : adj[src]) {
        if(!vis[x]) {
            dfs(x,ans);
        }
    }

    paths.push_back(ans);
    ans.clear();

}

int main() {
    int n , m;
    cin >> n >> m;
    adj.resize(n +  1);
    vis.resize(n+1,0);
    for(int i = 0 ; i < m ; i++) {
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans;

    for(int i = 1 ; i<= n ; i ++) {
        if(!vis[i]) {
            dfs(i,ans);
        }
    }
    
}
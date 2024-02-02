#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <climits>
#include <queue>
using namespace std;


void dfs(int src , vector<int>&vis,vector<vector<int>>&adj){
    vis[src] = 1;
    for(auto x : adj[src]) {
        if(!vis[x] ) {
            dfs(x,vis,adj);
        }
    }
}


int cc = 0;
void Connected_Componensts(int src , vector<int>&vis,vector<vector<int>>&adj,int& n) {
    for(int i = 0 ; i < n ; i++) {
        if(!vis[i]) {
            cc++;
            dfs(i,vis,adj);
        }
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<int>vis(n,0);
    for(int  i = 0 ; i < m ; i ++) {
        int u , v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    Connected_Componensts(0,vis,adj,n);
    cout<<cc - 1 <<endl;
}

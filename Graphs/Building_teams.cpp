#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include<iostream>
using namespace std;

int n , m;
vector<vector<int>>adj;
vector<bool>color;
vector<bool>vis;
bool ans;
void dfs(int src , int parent) {
    for(auto x : adj[src]) {
        if(!vis[x] ) {
            color[x] = 1 - color[src];
            vis[x] =1;
            dfs(x,src);
        }else{
            if(color[x] == color[src]) {
              ans = false;
            }
        }
    }
}

int main() {
    cin>>n>>m;
    adj.resize(n+1);
    color.resize(n+1);
    vis.resize(n+1);
    // constructing the adj matrix 
  
   while( m--) {
    int u ,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
   }

 ans = true;
 for(int i = 1 ; i <= n ;i++){
    if(!vis[i]) {
        vis[i] = true;
        color[i] = 0;
        dfs( i , 0);
    }
 }

if(ans == false) 
{ 
    cout<<"IMPOSSIBLE";
    return 0;
}



for(int i = 1 ; i <= n ; i++) {
cout<<color[i] + 1 << " ";
}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli;



using namespace std;
void dfs(int src , vector<int>&vis, vector<vector<int>>&adj  , int &ans , int n) {
    vis[src] = 1;
    if(src == n ) {
        ans++;
    }
    for(auto x  :adj[src]) {
        if(vis[x]) {
            if(x == n ) {
                ans++;
            }
        }
        if(!vis[x]) {
            dfs(x, vis, adj,ans , n );
        }
    }
}
int main() {
    int n , m;
    cin >> n >> m ;
    vector<vector<int>>adj(n+1);
    for(int i  = 0 ; i < m ; i++) {
        int u ,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int ans =0;
    vector<int>vis(n+1 , 0);
   for(int i = 0 ; i < n ; i++) {
       if(!vis[i]){
           dfs(1 , vis,adj,ans , n);
       }
   }
    cout<<ans<<" ";
    return 0;
}
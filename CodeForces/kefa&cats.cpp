#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long int lli ;
int ans = 0;
int n , k;
vector<int>c ,vis;


void dfs(int src , int m , vector<vector<int>>&adj) {
    vis[src] = 1;
    if( m > k ) {
        return;
    }

    int f = 1;
    for(auto x : adj[src]) {
     if(!vis[x] ) {
      f = 0;
         dfs(x , m *c[x] + c[x] , adj);
     }   
    }

    if(f) {
        ans++;
    }


}


int main() {
    
    cin >>n >> k ;
    c.resize(n);
    vector<vector<int>>adj(n);
    for(int i = 0 ; i <  n ; i ++ ) {
        cin >> c[i];
    }

    for(int i = 0 ; i < n-1 ; i ++) {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.resize( n , 0 );
    dfs( 0 , c[0] , adj);
    cout<<ans<<endl;
 }